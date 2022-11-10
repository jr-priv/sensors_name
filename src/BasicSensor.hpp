#pragma once

#include <string>
#include <memory>
#include "Msg.hpp"

class BasicSensor
{
public:
    BasicSensor(const unsigned my_id, const std::string& msgQ_name);
    virtual ~BasicSensor() = default;

    int get_id() const;
    virtual std::string measure() const = 0;
    virtual void send_data() const;
    void start();
    void stop();

private:
    const unsigned int id;
    std::unique_ptr<Msg> msgHandler;
};
