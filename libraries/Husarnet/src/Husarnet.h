#ifndef Husarnet_h
#define Husarnet_h

#include "Arduino.h"
#include "HusarnetServer.h"
//#include <freertos/task.h>

struct _Husarnet {
    // Starts the Husarnet
    void start();
};

extern _Husarnet Husarnet;

#endif
