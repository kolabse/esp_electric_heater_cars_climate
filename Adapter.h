#pragma once

#include "CanAdapter.h"
#include "CarState.h"

class Adapter {
    CanAdapter *canAdapter;
    
    public:
        Adapter(CanAdapter *iCanAdapter) :canAdapter(iCanAdapter){}
        void decode(uint32_t id, uint8_t dlc, uint8_t data[8]) {
            canAdapter->decode(id, dlc, data);
        }
        void encode(uint32_t id) {
            canAdapter->encode(id);
        }

        void setCarState(CarState *carState) {
            canAdapter->setCarState(carState);
        }

    private:
        
};