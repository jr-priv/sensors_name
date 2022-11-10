#pragma once

#include "BasicSensor.hpp"

class TemperatureSensor : public BasicSensor
{
public:
    TemperatureSensor(const unsigned int my_id, const std::string& msgQ_name);

    virtual std::string measure() const;

};
