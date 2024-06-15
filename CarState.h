#pragma once

#include <Arduino.h>

class CarState {

    public:

        typedef enum {
            UP_WINDSHIELD = 0b001,
            DOWN          = 0b010,
            FRONT         = 0b011,
            UP            = 0b100,
            FRONT_DOWN    = 0b101,
            UP_DOWN       = 0b110
        } ClmateAirDirection;

        typedef enum {
            BACK_LEFT   = 0,
            BACK_RIGHT  = 1,
            BONNET      = 2,
            FRONT_LEFT  = 3,
            FRONT_RIGHT = 4,
            FUEL_TANK   = 5,
            TRUNK       = 6
        } Door;

        typedef enum {
            OFF   = 0,
            ACC   = 1,
            ON    = 2,
            START = 3
        } IgnitionMode;

        typedef enum {
            BEAM_HIGH           = 0,
            BEAM_LOW            = 1,
            DASHBOARD_LIGHTNING = 2,
            DOORS               = 3,
            DRIVER_BELT         = 4,
            FOG_FRONT           = 5,
            FOG_REAR            = 6,
            FUEL_LOW            = 7,
            LEFT_INDCATOR       = 8,
            LEFT_TURN           = 9,
            PARKING_BRAKE_LIGHT = 10,
            REVERSE             = 11,
            RIGHT_INDCATOR      = 12,
            RIGHT_TURN          = 13,
            SIDE_LIGHT          = 14
        } Lamp;

        void  setBatteryVoltage(float batteryVoltage);
        float getBatteryVoltage();

        void    setCarSpeed(uint8_t carSpeed);
        uint8_t getCarSpeed();

        void               setClimateAirDirection(ClmateAirDirection airDirection);
        ClmateAirDirection getClimateAirDirection();

        void setClimateAirRecicling(bool enabled);
        bool isClimateAirRecicling();

        void    setClimateFanSpeed(uint8_t climateFanSpeed);
        uint8_t getClimateFanSpeed();

        void  setClimateLeftTemperature(float leftTemperature);
        float getClimateLeftTemperature();

        void  setClimateRightTemperature(float rightTemperature);
        float getClimateRightTemperature();

        void setClimateWindshieldBlowing(bool enabled);
        bool isClimateWindshieldBlowing();

        void   setCoolantTemp(int8_t coolantTemp);
        int8_t getCoolantTemp();

        void    setDashboardBrightness(uint8_t brightness);
        uint8_t getDashboardBrightness();

        void setDoor(Door door, bool state);
        bool getDoor(Door door);

        void setEconomyMode(bool economyMode);
        bool isEconomyMode();

        void    setEngineRPM(uint8_t engineRPM);
        uint8_t getEngineRPM();

        void    setFuelConsumptionCounter(uint8_t fuelConsumption);
        uint8_t getFuelConsumptionCounter();

        void         setIgnitionMode(IgnitionMode ignitionMode);
        IgnitionMode getIgnitionMode();

        void setLamp(Lamp lamp, bool state);
        bool getLamp(Lamp lamp);

        void    setOdometerFromStartValue(uint8_t odometerFromStart);
        uint8_t getOdometerFromStartValue();

        void    setOdometerValue(int8_t odometerValue);
        uint8_t getOdometerValue();

        void    setOutdoorTemp(int8_t outdoorTemp);
        uint8_t getOutdoorTemp();


    private:

        // Structs for climate state
        ClmateAirDirection _climateAirDirection;             // Направление воздушного потока климатической установки
        float _climateLeftTemperature;                       // Выбранная температура для левой зоны климатической установки
        float _climateRightTemperature;                      // Выбранная температура для правой зоны климатической установки
        uint8_t _climateFanSpeed;                            // Выбранная скорость воздушного потока климатичсеской установки
        bool _recyclingAir {false};                          // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield {false};                     // Активен режим обдува ветрового стекла
        // TODO: refactor

        // Structs for engine state 
        uint8_t _batteryVoltage;                             // Напряжение бортовой сети
        uint8_t _engineRPM;                                  // Обороты двигателя
        uint8_t _carSpeed;                                   // Скорость автомобиля
        uint8_t _fuelConsumptionCounter;                     // Счетчик расхода топлива
        int8_t _coolantTemp;                                 // Температура охлаждающей жидкости
        int8_t _odometerValue;
        int8_t _odometerFromStartValue;
        bool _economyMode {false};
        IgnitionMode _ignitionMode;                          // OFF|ACC|ON|START
        // TODO: refactor

        // Structs for car state
        int8_t _outdoorTemp;                                 // Наружная температура
        // TODO: refactor

        // Union for lamps state        
        typedef union {
            uint16_t lampsData;
            struct Lamps {
                int beamHigh           : 1;
                int beamLow            : 1;
                int dashboardLightning : 1;
                int doors              : 1;
                int driverBelt         : 1;
                int fogFront           : 1;
                int fogRear            : 1;
                int fuelLow            : 1;
                int leftIndcator       : 1;
                int leftTurn           : 1;
                int parkingBrakeLight  : 1;
                int reverse            : 1;
                int rightIndcator      : 1;
                int rightTurn          : 1;
                int sidelight          : 1;
                int reserve            : 1;
            } lamps;
        } LampsState;

        LampsState _lampsState;

        // Union for doors state
        typedef union {
            uint8_t doorsData;
            struct Doors {
                int backLeft   : 1;
                int backRight  : 1;
                int bonnet     : 1;
                int frontLeft  : 1;
                int frontRight : 1;
                int fuelTank   : 1;
                int reserve    : 1;
                int trunk      : 1;
            } doors;
        } DoorsState;
        
        DoorsState _doorsState;

        int8_t _dashboardBrightness;

        // Structs for car state
        struct SystemTime {
            uint32_t secAfterStart;                          // Секунд после запуска
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
