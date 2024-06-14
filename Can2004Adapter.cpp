#include "Can2004Adapter.h"

void Can2004Adapter::decode(uint32_t id, uint8_t dlc, uint8_t data[8])
{
    if (id == 0x036) {
        carState->setEconomyMode(data[2] >> 7);
        switch (data[4] & 0b00000111)
        {
            case 0b00000001:
                carState->setIgnitionMode(CarState::IgnitionMode::ON);
                break;
            case 0b00000010:
                carState->setIgnitionMode(CarState::IgnitionMode::OFF);
                break;
            case 0b00000011:
                carState->setIgnitionMode(CarState::IgnitionMode::START);
                break;
        }
    } else if (id == 0x0B6) {
        carState->setEngineRPM((data[0] << 8) + (data[1] >> 3));
        carState->setCarSpeed((data[2] << 8) + (data[3]));
        carState->setOdometerFromStartValue((data[4] << 8) + (data[5]));
        carState->setFuelConsumptionCounter(data[6]);
    }
}

void Can2004Adapter::encode(uint32_t id, uint8_t &data)
{
}
