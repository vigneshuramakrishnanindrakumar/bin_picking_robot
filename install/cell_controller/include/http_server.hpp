// This code is referred from ChatGPT

#pragma once
// Minimal single-threaded HTTP/1.1 server using POSIX sockets.
// Handles one connection at a time; sufficient for this demo use case.

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

struct HttpRequest {
  std::string method;
  std::string path;
  std::string body;
};

struct HttpResponse {
  int         status  = 200;
  std::string content_type = "application/json";
  std::string body;
};

using RequestHandler = std::function<HttpResponse(const HttpRequest &)>;

// Parse a raw HTTP request from a string buffer
inline HttpRequest parse_request(const std::string & raw)
{
  HttpRequest req;
  std::istringstream ss(raw);
  std::string line;

  // Request line
  if (std::getline(ss, line)) {
    std::istringstream rl(line);
    rl >> req.method >> req.path;
  }

  // Headers — skip until blank line
  while (std::getline(ss, line) && line != "\r" && !line.empty()) {}

  // Body — everything after blank line
  std::string body_buf;
  while (std::getline(ss, line)) {
    body_buf += line + "\n";
  }
  req.body = body_buf;
  return req;
}

// Build a raw HTTP response string
inline std::string build_response(const HttpResponse & resp)
{
  std::ostringstream out;
  out << "HTTP/1.1 " << resp.status << " OK\r\n";
  out << "Content-Type: " << resp.content_type << "\r\n";
  out << "Content-Length: " << resp.body.size() << "\r\n";
  out << "Connection: close\r\n\r\n";
  out << resp.body;
  return out.str();
}

// Blocking HTTP server — call run() in a dedicated thread
class SimpleHttpServer
{
public:
  SimpleHttpServer(int port, RequestHandler handler)
  : port_(port), handler_(std::move(handler)) {}

  void run()
  {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return; }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port        = htons(port_);

    if (bind(server_fd, (sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("bind"); close(server_fd); return;
    }
    if (listen(server_fd, 5) < 0) {
      perror("listen"); close(server_fd); return;
    }

    std::cout << "[HTTP] Listening on port " << port_ << std::endl;

    while (true) {
      sockaddr_in client{};
      socklen_t   len = sizeof(client);
      int client_fd = accept(server_fd, (sockaddr *)&client, &len);
      if (client_fd < 0) { perror("accept"); continue; }

      // Read request
      char buf[4096] = {};
      recv(client_fd, buf, sizeof(buf) - 1, 0);

      auto req  = parse_request(buf);
      auto resp = handler_(req);
      auto raw  = build_response(resp);

      send(client_fd, raw.c_str(), raw.size(), 0);
      close(client_fd);
    }
    close(server_fd);
  }

private:
  int            port_;
  RequestHandler handler_;
};