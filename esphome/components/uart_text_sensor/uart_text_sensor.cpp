// uart_text_sensor.cpp
#include "uart_text_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace uart_text_sensor {

static const char *const TAG = "uart_text_sensor";

void UartTextSensor::loop() {
  while (this->available()) {
    std::string line;
    if (!this->read_line(&line))
      continue;
    ESP_LOGD(TAG, "Received line: %s", line.c_str());
    this->publish_state(line);
  }
}

}  // namespace uart_text_sensor
}  // namespace esphome
