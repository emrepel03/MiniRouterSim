#include "Router.h"
#include <iostream>

Router::Router() {
    // Constructor: Possible to initialize default routes here if needed
}

void Router::addRoute(string destination, int outputPort) {
    routingTable[destination] = outputPort;
    cout << "[Router] Added route: " << destination << " → port " << outputPort << endl;
}

void Router::routePacket(const Packet& packet) {
    if (routingTable.find(packet.destination) != routingTable.end()) {
        int port = routingTable[packet.destination];
        cout << "[Router] Routing packet to " << packet.destination
             << " via port " << port << endl;
        packet.print();
    } else {
        cout << "[Router] No route for destination " << packet.destination << ". Packet dropped." << endl;
    }
}