#pragma once

#include <Arduino.h>

class EngineState {

    public:

        void  setBatteryVoltage(float batteryVoltage);
        float getBatteryVoltage();

        void    setEngineRPM(uint8_t engineRPM);
        uint8_t getEngineRPM();

        void    setCarSpeed(uint8_t carSpeed);
        uint8_t getCarSpeed();

        void   setCoolantTemp(int8_t coolantTemp);
        int8_t getCoolantTemp();


    private:

        typedef enum {
            OFF   = 0,
            ACC   = 1,
            ON    = 2,
            START = 3
        } IgnitinMode;

        // Structs for engine state 
        uint8_t _batteryVoltage;                             // Напряжение бортовой сети
        uint8_t _engineRPM;                                  // Обороты двигателя
        uint8_t _carSpeed;                                   // Скорость автомобиля
        int8_t _coolantTemp;                                 // Температура охлаждающей жидкости
        int8_t _odometerValue;
        int8_t _odometerFromStartValue;
        bool _economyModeIsEnabled {false};
        IgnitinMode _ignitionMode;                                // OFF|ACC|ON|START
        // TODO: refactor
};
