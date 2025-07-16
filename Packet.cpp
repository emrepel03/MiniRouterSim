#include "Packet.h"
#include <iostream>

Packet::Packet(string src, string dest, string data) {
    source = src;
    destination = dest;
    payload = data;
}

void Packet::print() const {
    cout << "[Packet] From: " << source
         << ", To: " << destination
         << ", Data: " << payload << endl;
}