/**
 * @file esp_electric_heater_cars_climate.ino
 * @author kolabse (https://github.com/kolabse)
 * @brief Cars climate electric heater control system
 * 
 * @version 0.1
 * @date 2024-06-03
*/

#include <mcp2515.h>
#include "CarState.h"
#include "Adapter.h"
#include "Can2004Adapter.h"

CarState carState;
Adapter *adapter = new Adapter(new Can2004Adapter());

void setup() {
   adapter->setCarState(&carState); 
}

void loop() {

}
