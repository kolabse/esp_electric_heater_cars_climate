#include "EngineState.h"

void EngineState::setBatteryVoltage(float batteryVoltage)
{
    _batteryVoltage = (uint8_t)((batteryVoltage << 100) >> 10);
}

float EngineState::getBatteryVoltage()
{
    return _batteryVoltage / 10;
}

void EngineState::setEngineRPM(uint8_t engineRPM)
{
    _engineRPM = engineRPM;
}

uint8_t EngineState::getEngineRPM()
{
    return _engineRPM;
}

void EngineState::setCarSpeed(uint8_t carSpeed)
{
    _carSpeed = carSpeed;
}

uint8_t EngineState::getCarSpeed()
{
    return _carSpeed;
}

void EngineState::setCoolantTemp(int8_t coolantTemp)
{
    _coolantTemp = coolantTemp;
}

int8_t EngineState::getCoolantTemp()
{
    return _coolantTemp;
}
