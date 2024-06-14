#pragma once

#include "CanAdapter.h"
#include "CarState.h"


class Can2004Adapter: public CanAdapter {

    public:
        void decode(uint32_t id, uint8_t dlc, uint8_t data[8]);
        void encode(uint32_t id, uint8_t &data);
};