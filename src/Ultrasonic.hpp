#pragma once

#include "BasicSensor.hpp"

class UltrasonicSensor : public BasicSensor
{
public:
    UltrasonicSensor(const unsigned int my_id, const std::string& msgQ_name);

    virtual std::string measure() const;

};
