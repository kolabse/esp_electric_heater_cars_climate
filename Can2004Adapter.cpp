#include "Can2004Adapter.h"

void Can2004Adapter::decode(uint32_t id, uint8_t dlc, uint8_t data[8])
{
}

void Can2004Adapter::encode(uint32_t id)
{
}

void Can2004Adapter::setCarState(CarState *state)
{
    carState = state;
}
