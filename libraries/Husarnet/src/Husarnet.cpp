#include "Husarnet.h"

_Husarnet Husarnet;


namespace WebSetup {
void start(std::string confpath, std::string userAgent);
}

void _Husarnet::start() {
    WebSetup::start("", "Arduino-ESP32");
    delay(1000);
}
