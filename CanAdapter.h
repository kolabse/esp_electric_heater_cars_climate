#pragma once

#include "CarState.h"
#include "Helpers.h"

class CanAdapter {
    
    public:
        CarState *carState;
        virtual void decode(uint32_t id, uint8_t dlc, uint8_t data[8]) = 0;
        virtual void encode(uint32_t id, uint8_t &data) = 0;
        virtual void setCarState(CarState *state);
};
