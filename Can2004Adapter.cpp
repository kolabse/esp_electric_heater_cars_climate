#include "Can2004Adapter.h"

void Can2004Adapter::decode(uint32_t id, uint8_t dlc, uint8_t data[8])
{
    // 0x036
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
    } 
    // 0x0B6
    else if (id == 0x0B6) {
        carState->setEngineRPM((data[0] << 8) + (data[1] >> 3));
        carState->setCarSpeed((data[2] << 8) + (data[3]));
        carState->setOdometerFromStartValue((data[4] << 8) + (data[5]));
        carState->setFuelConsumptionCounter(data[6]);
    }
    // 0x0E6
    else if(id == 0x0E6) {
        carState->setBatteryVoltage((data[6] + 144) / 20);
    }
    // 0x0F6
    else if(id == 0x0F6) {
        switch (data[0] & 0b00001000)
        {
            case 0b00001000:
                carState->setIgnitionMode(CarState::IgnitionMode::ON);
                break;
            case 0b00000000:
                carState->setIgnitionMode(CarState::IgnitionMode::OFF);
                break;
        }
        carState->setCoolantTemp(data[1] - 39);
        carState->setOdometerValue((data[2] << 16) + (data[3] << 8) + (data[4]));
        carState->setOutdoorTemp(round(data[6] / 2.0 - 39.5));
        carState->setLamp(CarState::Lamp::REVERSE, data[7] & 0b10000000);
        carState->setLamp(CarState::Lamp::RIGHT_TURN, data[7] & 0b00000010);
        carState->setLamp(CarState::Lamp::LEFT_TURN, data[7] & 0b00000001);
    }
}

void Can2004Adapter::encode(uint32_t id, uint8_t &data)
{
}
