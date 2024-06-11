#pragma once

#include <Arduino.h>

class EngineState {

    public:
        // Structs for engine state 
        float _batteryVoltage;                               // Напряжение бортовой сети
        int8_t _coolantTemp;                                 // Температура охлаждающей жидкости
        int8_t _engineRPM;                                                // Обороты двигателя
        int8_t _carSpeed;                                                 // Скорость автомобиля
        int8_t _ignitionMode;
        int8_t _odometerValue;
        int8_t _odometerFromStartValue;
        bool _economyModeIsEnabled {false};
        // TODO: refactor
    private:
};
