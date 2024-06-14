#pragma once

#include <Arduino.h>

class CarState {

    public:

        typedef enum {
            OFF   = 0,
            ACC   = 1,
            ON    = 2,
            START = 3
        } IgnitionMode;

        void  setBatteryVoltage(float batteryVoltage);
        float getBatteryVoltage();

        void    setEngineRPM(uint8_t engineRPM);
        uint8_t getEngineRPM();

        void    setCarSpeed(uint8_t carSpeed);
        uint8_t getCarSpeed();

        void   setCoolantTemp(int8_t coolantTemp);
        int8_t getCoolantTemp();

        void         setIgnitionMode(IgnitionMode ignitionMode);
        IgnitionMode getIgnitionMode();


    private:

        // Structs for climate state
        int8_t _climateFanSpeed;                             // Выбранная скорость воздушного потока климатичсеской установки
        int8_t _climateLeftTemperature;                      // Выбранная температура для левой зоны климатической установки
        int8_t _climateRightTemperature;                     // Выбранная температура для правой зоны климатической установки
        bool _recyclingAir {false};                          // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield {false};                     // Активен режим обдува ветрового стекла
        // TODO: refactor

        // Structs for doors state
        struct Doors {
            bool frontLeft  {false};
            bool frontRight {false};
            bool backLeft   {false};
            bool backRight  {false};
            bool trunk      {false};
            bool bonnet     {false};
            bool fuelTank   {false};
        };
        // TODO: add union, add get methods
        struct Doors _doors;

        // Structs for engine state 
        uint8_t _batteryVoltage;                             // Напряжение бортовой сети
        uint8_t _engineRPM;                                  // Обороты двигателя
        uint8_t _carSpeed;                                   // Скорость автомобиля
        int8_t _coolantTemp;                                 // Температура охлаждающей жидкости
        int8_t _odometerValue;
        int8_t _odometerFromStartValue;
        bool _economyModeIsEnabled {false};
        IgnitionMode _ignitionMode;                           // OFF|ACC|ON|START
        // TODO: refactor

        // Structs for car state
        int8_t _outdoorTemp;                                  // Наружная температура
        // TODO: refactor

        // Structs for lamps state
        struct Lamps {
            bool reverse            {false};
            bool leftTurn           {false};
            bool rightTurn          {false};
            bool driverBelt         {false};
            bool doors              {false};
            bool sidelight          {false};
            bool beamLow            {false};
            bool beamHigh           {false};
            bool fogFront           {false};
            bool fogRear            {false};
            bool leftIndcator       {false};
            bool rightIndcator      {false};
            bool fuelLow            {false};
            bool dashboardLightning {false};
            bool parkingBrakeLight  {false};
        };
        // TODO: add union, add get methods
        struct Lamps _lamps;
        int8_t _dashboardLightningBrightnessLevel;

        // Structs for car state
        struct SystemTime {
            uint32_t secAfterStart;                           // Секунд после запуска
            int8_t year         {2000}; // TODO: change to byte value, add getter/seter to convert
            int8_t month        {1};
            int8_t day          {1};
            int8_t hour         {0};
            int8_t minutes      {0};
            bool   is24hFormat  {true};
        };
        // TODO: refactor
        struct SystemTime _systemTime;
};
