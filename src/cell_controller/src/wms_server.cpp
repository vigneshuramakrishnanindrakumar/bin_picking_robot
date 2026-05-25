#include <atomic>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "http_server.hpp"
#include "http_client.hpp"

std::atomic<int> latest_pick_id{-1};
std::atomic<int> latest_barcode{0};
std::atomic<bool> latest_success{false};
// ---------------------------------------------------------------------------
// Simple JSON helpers
// ---------------------------------------------------------------------------
static int json_int(const std::string & json, const std::string & key)
{
  auto pos = json.find("\"" + key + "\"");
  if (pos == std::string::npos) return -1;
  pos = json.find(':', pos);
  if (pos == std::string::npos) return -1;
  ++pos;
  while (pos < json.size() && (json[pos] == ' ' || json[pos] == '\t')) ++pos;
  try { return std::stoi(json.substr(pos)); } catch (...) { return -1; }
}

static bool json_bool(const std::string & json, const std::string & key)
{
  auto pos = json.find("\"" + key + "\"");
  if (pos == std::string::npos) return false;
  pos = json.find(':', pos);
  if (pos == std::string::npos) return false;
  ++pos;
  while (pos < json.size() && (json[pos] == ' ' || json[pos] == '\t')) ++pos;
  return json.substr(pos, 4) == "true";
}

static std::string json_string(const std::string & json, const std::string & key)
{
  auto pos = json.find("\"" + key + "\"");
  if (pos == std::string::npos) return "";
  pos = json.find(':', pos);
  if (pos == std::string::npos) return "";
  ++pos;
  while (pos < json.size() && (json[pos] == ' ' || json[pos] == '\t')) ++pos;
  if (pos >= json.size()) return "";

  if (json[pos] == '"') {
    ++pos;
    auto end = json.find('"', pos);
    if (end == std::string::npos) return json.substr(pos);
    return json.substr(pos, end - pos);
  }

  auto end = json.find_first_of(",}", pos);
  if (end == std::string::npos) return json.substr(pos);
  return json.substr(pos, end - pos);
}

// ---------------------------------------------------------------------------
// WMS server
// ---------------------------------------------------------------------------
int main()
{
  const std::string robot_host = "127.0.0.1";
  const int         robot_port = 8080;

  // Listening to robot on confirmPick
  SimpleHttpServer confirm_server(8081, [](const HttpRequest & req) -> HttpResponse {
    HttpResponse resp;

    if (req.path != "/confirmPick") {
      resp.status = 404;
      resp.body   = "{\"error\":\"Not found\"}";
      return resp;
    }

    int  pick_id  = json_int(req.body, "pickId");
    bool success  = json_bool(req.body, "pickSuccessful");
    int  barcode  = json_int(req.body, "itemBarcode");
    std::string  error  = json_string(req.body, "errorMessage");
    
    latest_pick_id = pick_id;
    latest_barcode = barcode;
    latest_success = success;
    std::string confirm_body =
    "{"
      "\"pickId\":" + std::to_string(pick_id) + ","
      "\"pickSuccessful\":" + std::string(success ? "true" : "false") + ","
      "\"itemBarcode\":" + std::to_string(barcode) + ","
      "\"errorMessage\":\"" + error + "\""
    "}";

    http_post("127.0.0.1", 8090, "/confirmPick", confirm_body);  // To HMI

    std::cout << "[WMS] ConfirmPick received: pickId=" << pick_id
              << " success=" << (success ? "true" : "false")
              << " barcode=" << barcode << std::endl;          

  
    resp.body = "{\"status\":\"acknowledged\"}";
    return resp;
  });

  // Thread A: server running for listening
  std::thread confirm_thread([&]() { confirm_server.run(); });

  // Thread B: send pick request
  std::atomic<int> pick_id_counter{1};
  std::thread sender_thread([&]() {
  
    std::this_thread::sleep_for(std::chrono::seconds(3));

    while (true) {
      int pid = pick_id_counter.fetch_add(1);
      std::string body = "{\"pickId\":" + std::to_string(pid) + ",\"quantity\":1}";
      std::cout << "[WMS] Sending pick request: pickId=" << pid << std::endl;
      http_post(robot_host, robot_port, "/pick", body);
      http_post("127.0.0.1", 8090, "/pick", body); // To HMI
      std::this_thread::sleep_for(std::chrono::seconds(10));
    }
  });

  confirm_thread.join();
  sender_thread.join();
  return 0;
}
