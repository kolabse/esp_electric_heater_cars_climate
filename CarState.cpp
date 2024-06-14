#include "CarState.h"

void CarState::setBatteryVoltage(float batteryVoltage)
{
    this->_batteryVoltage = ((uint8_t)(batteryVoltage * 100) >> 10);
}

float CarState::getBatteryVoltage()
{
    return this->_batteryVoltage / 10;
}

void CarState::setEconomyMode(bool economyMode)
{
    this->_economyMode = economyMode;
}

bool CarState::isEconomyMode()
{
    return this->_economyMode;
}

void CarState::setEngineRPM(uint8_t engineRPM)
{
    this->_engineRPM = engineRPM;
}

uint8_t CarState::getEngineRPM()
{
    return this->_engineRPM;
}

void CarState::setCarSpeed(uint8_t carSpeed)
{
    this->_carSpeed = carSpeed;
}

uint8_t CarState::getCarSpeed()
{
    return this->_carSpeed;
}

void CarState::setCoolantTemp(int8_t coolantTemp)
{
    this->_coolantTemp = coolantTemp;
}

int8_t CarState::getCoolantTemp()
{
    return this->_coolantTemp;
}

void CarState::setDashboardBrightness(uint8_t brightness)
{
    this->_dashboardBrightness = brightness;
}

uint8_t CarState::getDashboardBrightness()
{
    return this->_dashboardBrightness;
}

void CarState::setFuelConsumptionCounter(uint8_t fuelConsumption)
{
    this->_fuelConsumptionCounter = fuelConsumption;
}

uint8_t CarState::getFuelConsumptionCounter()
{
    return this->_fuelConsumptionCounter;
}

void CarState::setIgnitionMode(CarState::IgnitionMode ignitionMode)
{
    this->_ignitionMode = ignitionMode;
}

CarState::IgnitionMode CarState::getIgnitionMode()
{
    return this->_ignitionMode;
}

void CarState::setOdometerFromStartValue(uint8_t odometerFromStart)
{
    this->_odometerFromStartValue = odometerFromStart;
}

uint8_t CarState::getOdometerFromStartValue()
{
    return this->_odometerFromStartValue;
}
