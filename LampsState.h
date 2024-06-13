#pragma once

#include <Arduino.h>

class LampsState {

    public:
         
    private:
        // Structs for lamps state
        struct Lamps {
            bool reverse        {false};
            bool leftTurn       {false};
            bool rightTurn      {false};
            bool driverBelt     {false};
            bool doors          {false};
            bool sidelight      {false};
            bool beamLow        {false};
            bool beamHigh       {false};
            bool fogFront       {false};
            bool fogRear        {false};
            bool leftIndcator   {false};
            bool rightIndcator  {false};
            bool fuelLow        {false};
            bool dashboardLightningIsEnabled {false};
        };
        // TODO: add union, add get methods
        struct Lamps _lamps;
        int8_t _dashboardLightningBrightnessLevel;
};
