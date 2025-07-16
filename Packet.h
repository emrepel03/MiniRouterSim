#ifndef PACKET_H
#define PACKET_H

#include <string>
using namespace std;

class Packet {
public:
    string source;
    string destination;
    string payload;

    Packet(string src, string dest, string data);
    void print() const;
};

#endif