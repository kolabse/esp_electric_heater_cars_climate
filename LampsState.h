#pragma once

#include <Arduino.h>

class LampsState {

    public:
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
            bool _dashboardLightningIsEnabled {false};
            int8_t _dashboardLightningBrightnessLevel;
        };
        // TODO: add union, add get methods 
    private:
};
