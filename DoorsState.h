#pragma once

#include <Arduino.h>

class DoorsState {

    public:
        // Structs for doors state
        struct Doors {
            bool frontLeft  {false};
            bool frontRight {false};
            bool backLeft   {false};
            bool backRight  {false};
            bool trunk      {false};
        };
        // TODO: add union, add get methods
    private:
};
