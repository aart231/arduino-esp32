#ifndef Husarnet_h
#define Husarnet_h

namespace WebSetup {
void start(std::string confpath, std::string userAgent);

// Starts the Husarnet
void start() {
    start("", "Arduino-ESP32");
}
}

#endif
