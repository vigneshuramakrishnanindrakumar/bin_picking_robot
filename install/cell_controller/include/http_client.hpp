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

// Send a single HTTP POST and return the response body (blocking)
inline std::string http_post(const std::string & host, int port,
                             const std::string & path, const std::string & body)
{
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) return "";

  sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_port   = htons(port);
  inet_pton(AF_INET, host.c_str(), &addr.sin_addr);

  if (connect(fd, (sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect"); close(fd); return "";
  }

  std::ostringstream req;
  req << "POST " << path << " HTTP/1.1\r\n";
  req << "Host: " << host << ":" << port << "\r\n";
  req << "Content-Type: application/json\r\n";
  req << "Content-Length: " << body.size() << "\r\n";
  req << "Connection: close\r\n\r\n";
  req << body;

  std::string req_str = req.str();
  send(fd, req_str.c_str(), req_str.size(), 0);

  // Read response
  std::string resp;
  char buf[4096];
  int n;
  while ((n = recv(fd, buf, sizeof(buf) - 1, 0)) > 0) {
    buf[n] = '\0';
    resp += buf;
  }
  close(fd);

  // Return only the body (after \r\n\r\n)
  auto pos = resp.find("\r\n\r\n");
  return (pos != std::string::npos) ? resp.substr(pos + 4) : resp;
}
