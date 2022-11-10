#include "Ultrasonic.hpp"

UltrasonicSensor::UltrasonicSensor(const unsigned my_id, const std::string& msgQ_name)
    : BasicSensor(my_id, msgQ_name)
{
}

std::string UltrasonicSensor::measure() const
{
    int temp = std::rand() % 50 - 25;
    return std::to_string(temp) + " cm";
}
