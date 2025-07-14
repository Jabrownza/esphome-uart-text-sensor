# __init__.py
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, text_sensor
from esphome.const import CONF_ID

AUTO_LOAD = ["text_sensor", "uart"]
DEPENDENCIES = ["uart"]

uart_text_sensor_ns = cg.esphome_ns.namespace("uart_text_sensor")
UartTextSensor = uart_text_sensor_ns.class_("UartTextSensor", cg.Component, text_sensor.TextSensor)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(UartTextSensor),
}).extend(uart.TEXT_SENSOR_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)
    yield text_sensor.register_text_sensor(var, config)
