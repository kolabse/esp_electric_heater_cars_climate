#pragma once

#include <Arduino.h>

class TimeState {

    public:
        // Structs for car state
        struct SystemTime {
            uint32_t _secAfterStart;                                          // Секунд после запуска
            int8_t year         {2000}; // TODO: change to byte value, add getter/seter to convert
            int8_t month        {1};
            int8_t day          {1};
            int8_t hour         {0};
            int8_t minutes      {0};
            bool   is24hFormat  {true};
        };
        // TODO: refactor
    private:
};