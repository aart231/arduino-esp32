#ifndef Husarnet_h
#define Husarnet_h

#include "Arduino.h"
#include "HusarnetServer.h"
//#include <freertos/task.h>

struct _Husarnet {
    // Starts the Husarnet
    void start();

    // Provides join code. Use before Husarnet.start().
    void joinIfNeeded(const char* joinCodeHost, const char* joinCode);
};

extern _Husarnet Husarnet;

#endif
