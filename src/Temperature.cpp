#include "Temperature.hpp"

TemperatureSensor::TemperatureSensor(const unsigned my_id, const std::string& msgQ_name)
    : BasicSensor(my_id, msgQ_name)
{
}

std::string TemperatureSensor::measure() const
{
    int temp = std::rand() % 40 - 20;
    return std::to_string(temp) + "°C";
}
