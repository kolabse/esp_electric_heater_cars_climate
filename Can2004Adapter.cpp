#include "Can2004Adapter.h"

void Can2004Adapter::decode(uint32_t id, uint8_t dlc, uint8_t data[8])
{
    // 0x036
    if (id == 0x036) {
        carState->setEconomyMode(data[2] >> 7);
        carState->setLamp(CarState::Lamp::DASHBOARD_LIGHTNING, bitRead(data[3], 2));
        carState->setDashboardBrightness(data[3] & 0b00001111);
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
    else if (id == 0x0E6) {
        carState->setBatteryVoltage((data[6] + 144) / 20);
    }
    // 0x0F6
    else if (id == 0x0F6) {
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
        carState->setLamp(CarState::Lamp::REVERSE, bitRead(data[7], 0));
        carState->setLamp(CarState::Lamp::RIGHT_TURN, bitRead(data[7], 6));
        carState->setLamp(CarState::Lamp::LEFT_TURN, bitRead(data[7], 7));
    }
    // 0x128
    else if (id == 0x128) {
        carState->setLamp(CarState::Lamp::DRIVER_BELT, bitRead(data[0], 1));
        carState->setLamp(CarState::Lamp::PARKING_BRAKE_LIGHT, bitRead(data[0], 2));
        carState->setLamp(CarState::Lamp::DOORS, bitRead(data[1], 3));
        carState->setLamp(CarState::Lamp::SIDE_LIGHT, bitRead(data[4], 0));
        carState->setLamp(CarState::Lamp::BEAM_LOW, bitRead(data[4], 1));
        carState->setLamp(CarState::Lamp::BEAM_HIGH, bitRead(data[4], 2));
        carState->setLamp(CarState::Lamp::FOG_FRONT, bitRead(data[4], 3));
        carState->setLamp(CarState::Lamp::FOG_REAR, bitRead(data[4], 4));
        carState->setLamp(CarState::Lamp::RIGHT_INDCATOR, bitRead(data[4], 5));
        carState->setLamp(CarState::Lamp::LEFT_INDCATOR, bitRead(data[4], 6));
        carState->setLamp(CarState::Lamp::FUEL_LOW, bitRead(data[5], 0));
    }
    // 0x1D0
    else if (id = 0x1D0) {
        carState->setClimateFanSpeed(data[2]);
        carState->setClimateAirDirection((CarState::ClmateAirDirection)((data[3] & 0b01110000) >> 4));
        carState->setClimateAirRecicling(bitRead(data[4], 2));
        carState->setClimateLeftTemperature(mapClimateTemperature(data[6]));
        carState->setClimateRightTemperature(mapClimateTemperature(data[7]));
    }
}

void Can2004Adapter::encode(uint32_t id, uint8_t &data)
{
}

float Can2004Adapter::mapClimateTemperature(float value)
{
    if (value == 0) {
        return 0.0f;
    } else if (value == 22) {
        return 99.0f;
    } else if (value < 6 ) {
        return map(value, 2, 5, 15, 18);
    } else if (value < 17) {
        return map(value, 6, 16, 18.5, 23.5);
    } else {
        return map(value, 17, 20, 24, 27);
    }
}
