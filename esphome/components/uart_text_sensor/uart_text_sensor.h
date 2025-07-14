// uart_text_sensor.h
#pragma once

#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace uart_text_sensor {

class UartTextSensor : public Component, public uart::UARTDevice, public text_sensor::TextSensor {
 public:
  void loop() override;
};

}  // namespace uart_text_sensor
}  // namespace esphome
