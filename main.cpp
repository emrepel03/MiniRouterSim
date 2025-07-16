#include "Router.h"
#include "Packet.h"
#include "Logger.h"
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

void runDemoMode() {
    Logger::log("MiniRouterSim [DEMO MODE] starting...");

    Router router;
    router.addRoute("DeviceA", 1);
    router.addRoute("DeviceB", 2);
    router.addRoute("Server", 3);

    vector<Packet> incomingPackets = {
        Packet("Client1", "DeviceA", "Ping"),
        Packet("Client2", "DeviceB", "Upload"),
        Packet("Client3", "Unknown", "???"),
        Packet("Client4", "Server", "Login")
    };

    Logger::log("Routing packets from queue...");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> delay(100, 500);

    for (const auto& packet : incomingPackets) {
        router.routePacket(packet);
        this_thread::sleep_for(chrono::milliseconds(delay(gen)));
    }

    Logger::log("All packets processed.");
}

void runPerformanceMode() {
    Logger::log("MiniRouterSim [PERFORMANCE MODE] starting...");

    Router router;
    router.addRoute("DeviceA", 1);
    router.addRoute("DeviceB", 2);
    router.addRoute("Server", 3);

    // Generate 1000 packets
    vector<Packet> testPackets;
    for (int i = 0; i < 1000; ++i) {
        string dest = (i % 3 == 0) ? "DeviceA" : (i % 3 == 1) ? "DeviceB" : "Server";
        testPackets.push_back(Packet("PerfClient", dest, "Payload_" + to_string(i)));
    }

    Logger::log("Routing 1000 packets...");

    auto start = chrono::high_resolution_clock::now();

    for (const auto& packet : testPackets) {
        router.routePacket(packet);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    Logger::log("Performance mode complete.");
    Logger::log("Total packets routed: 1000");
    Logger::log("Total time taken: " + to_string(duration) + " ms");
    Logger::log("Avg time per packet: " + to_string(duration / 1000.0) + " ms");
}

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--performance") {
        runPerformanceMode();
    } else {
        runDemoMode();
    }

    return 0;
}