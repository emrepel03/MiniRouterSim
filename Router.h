#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <unordered_map>
#include "Packet.h"

using namespace std;

class Router {
public:
    Router();
    void addRoute(string destination, int outputPort);
    void routePacket(const Packet& packet);

private:
    unordered_map<string, int> routingTable;
};

#endif