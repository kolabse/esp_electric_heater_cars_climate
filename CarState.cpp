#include "CarState.h"

void CarState::setBatteryVoltage(float batteryVoltage)
{
    _batteryVoltage = ((uint8_t)(batteryVoltage * 100) >> 10);
}

float CarState::getBatteryVoltage()
{
    return _batteryVoltage / 10;
}

void CarState::setEngineRPM(uint8_t engineRPM)
{
    _engineRPM = engineRPM;
}

uint8_t CarState::getEngineRPM()
{
    return _engineRPM;
}

void CarState::setCarSpeed(uint8_t carSpeed)
{
    _carSpeed = carSpeed;
}

uint8_t CarState::getCarSpeed()
{
    return _carSpeed;
}

void CarState::setCoolantTemp(int8_t coolantTemp)
{
    _coolantTemp = coolantTemp;
}

int8_t CarState::getCoolantTemp()
{
    return _coolantTemp;
}

void CarState::setIgnitionMode(CarState::IgnitionMode ignitionMode)
{
    _ignitionMode = ignitionMode;
}

CarState::IgnitionMode CarState::getIgnitionMode()
{
    return _ignitionMode;
}
