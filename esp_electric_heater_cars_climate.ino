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


struct can_frame canMsg;
MCP2515 mcp2515(10);

CarState carState;
Adapter *adapter = new Adapter(new Can2004Adapter());


void setup() {

   adapter->setCarState(&carState);

   mcp2515.reset();
   mcp2515.setBitrate(CAN_125KBPS);
   mcp2515.setNormalMode();
}

void loop() {

    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
        adapter->decode((uint32_t)canMsg.can_id, (uint8_t)canMsg.can_dlc, (uint8_t*)canMsg.data);
    }

}
