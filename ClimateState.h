#pragma once

#include <Arduino.h>

class ClimateState {

    public:

    private:
        // Structs for car state
        int8_t _climateFanSpeed;                             // Выбранная скорость воздушного потока климатичсеской установки
        int8_t _climateLeftTemperature;                      // Выбранная температура для левой зоны климатической установки
        int8_t _climateRightTemperature;                     // Выбранная температура для правой зоны климатической установки
        bool _recyclingAir {false};                          // Актиен режим рециркуляции на климатической установке
        bool _blowingWindshield {false};                     // Активен режим обдува ветрового стекла
        // TODO: refactor
};
