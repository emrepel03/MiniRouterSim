# MiniRouterSim 🚀

A fast and modular C++ simulation of a network packet router, built to demonstrate core concepts in routing, embedded systems, and object-oriented programming.

---

## 🧠 Features

- Object-oriented architecture with clean header/source separation
- Routing logic using a `std::unordered_map` routing table
- Packet queue simulation (like buffered packet handling in real routers)
- Custom logging system with timestamped output
- Two execution modes:
  - `--demo`: Manual test routing with simulated delays
  - `--performance`: Simulates routing of 1000 packets and measures execution time

---

## 📂 File Structure

| File         | Purpose                        |
|--------------|--------------------------------|
| `Packet.h/.cpp` | Defines packet structure with metadata and print function |
| `Router.h/.cpp` | Handles routing logic and routing table |
| `Logger.h/.cpp` | Timestamped logging for console output |
| `main.cpp`      | Runs the simulation with either demo or performance mode |

---

## 🧪 Sample Output (Performance Mode)
```
[Thu Jul 17 00:32:21 2025] MiniRouterSim starting...
[Router] Added route: DeviceA → port 1
[Router] Routing packet to Server via port 3
[Packet] From: PerfClient, To: Server, Data: Payload_998
[Router] Routing packet to DeviceA via port 1
[Packet] From: PerfClient, To: DeviceA, Data: Payload_999
[Thu Jul 17 00:32:21 2025] Performance mode complete.
[Thu Jul 17 00:32:21 2025] Total packets routed: 1000
[Thu Jul 17 00:32:21 2025] Total time taken: 45 ms
[Thu Jul 17 00:32:21 2025] Avg time per packet: 0.045000 ms
```
---

## 🚀 Run Instructions

### 🔹 Compile:
```bash
g++ main.cpp Packet.cpp Router.cpp Logger.cpp -o MiniRouterSim -std=c++17
```

🔹 Run:
```bash
./MiniRouterSim                 # Demo mode
./MiniRouterSim --performance  # Performance mode
```

👨‍💻 Author

Emre Pelzer
GitHub: emrepel03
Created July 2025