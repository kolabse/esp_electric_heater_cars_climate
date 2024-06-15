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

void CarState::setClimateAirDirection(ClmateAirDirection airDirection)
{
    this->_climateAirDirection = airDirection;
}

CarState::ClmateAirDirection CarState::getClimateAirDirection()
{
    return this->_climateAirDirection;
}

void CarState::setClimateAirRecicling(bool enabled)
{
    this->_recyclingAir = enabled;
}

bool CarState::isClimateAirRecicling()
{
    return this->_recyclingAir;
}

void CarState::setClimateFanSpeed(uint8_t climateFanSpeed)
{
    this->_climateFanSpeed = climateFanSpeed;
}

uint8_t CarState::getClimateFanSpeed()
{
    return this->_climateFanSpeed;
}

void CarState::setClimateLeftTemperature(float leftTemperature)
{
    this->_climateLeftTemperature = leftTemperature;
}

float CarState::getClimateLeftTemperature()
{
    return this->_climateLeftTemperature;
}

void CarState::setClimateRightTemperature(float rightTemperature)
{
    this->_climateRightTemperature = rightTemperature;
}

float CarState::getClimateRightTemperature()
{
    return this->_climateRightTemperature;
}

void CarState::setClimateWindshieldBlowing(bool enabled)
{
    this->_blowingWindshield = enabled;
}

bool CarState::isClimateWindshieldBlowing()
{
    return this->_blowingWindshield;
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

void CarState::setDoor(Door door, bool state)
{
    bitWrite(this->_doorsState.doorsData, door, state);
}

bool CarState::getDoor(Door door)
{
    return (bool)bitRead(this->_doorsState.doorsData, door);
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

void CarState::setLamp(Lamp lamp, bool state)
{
    bitWrite(this->_lampsState.lampsData, lamp, state);
}

bool CarState::getLamp(Lamp lamp)
{
    return (bool)bitRead(this->_lampsState.lampsData, lamp);
}

void CarState::setOdometerFromStartValue(uint8_t odometerFromStart)
{
    this->_odometerFromStartValue = odometerFromStart;
}

uint8_t CarState::getOdometerFromStartValue()
{
    return this->_odometerFromStartValue;
}

void CarState::setOdometerValue(int8_t odometerValue)
{
    this->_odometerValue = odometerValue;
}

uint8_t CarState::getOdometerValue()
{
    return this->_odometerValue;
}

void CarState::setOutdoorTemp(int8_t outdoorTemp)
{
    this->_outdoorTemp = outdoorTemp;
}

uint8_t CarState::getOutdoorTemp()
{
    return this->_outdoorTemp;
}
