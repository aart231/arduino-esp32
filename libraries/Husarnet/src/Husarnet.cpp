#include "Husarnet.h"
#include <cassert>

_Husarnet Husarnet;

namespace WebSetup {
void start(std::string confpath, std::string userAgent);
extern std::string joinCode;
extern std::string joinCodeHost;
}

static bool alreadyStarted = false;

void _Husarnet::start() {
    assert(!alreadyStarted);
    alreadyStarted = true;
    WebSetup::start("", "Arduino-ESP32");
    delay(1000);
}

void _Husarnet::joinIfNeeded(const char* joinCodeHost, const char* joinCode) {
    assert(!alreadyStarted);
    WebSetup::joinCode = joinCode;
    WebSetup::joinCodeHost = joinCodeHost;
}
