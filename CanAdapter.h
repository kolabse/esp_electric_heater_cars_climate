#pragma once

#include "CarState.h"

class CanAdapter {
    
    public:
        virtual void decode(uint32_t id, uint8_t dlc, uint8_t data[8]) = 0;
        virtual void encode(uint32_t id) = 0;
        virtual void setCarState(CarState *state) = 0;
    
};
