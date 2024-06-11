#pragma once

#include <Arduino.h>
#include "ClimateState.h"
#include "EnvironmentState.h"
#include "EngineState.h"
#include "LampsState.h"
#include "DoorsState.h"
#include "SystemTime.h"

class CarState {

    public:
        TimeState time;
        ClimateState climate;
        EnvironmentState environment;
        EngineState engine;
        LampsState lamps;
        DoorsState doors;

        // TODO: add state classes 
    private:
};
