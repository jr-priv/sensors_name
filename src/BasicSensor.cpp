#include "BasicSensor.hpp"
#include "Msg.hpp"
#include <cstring>
#include <mqueue.h>
#include <thread>
#include <iostream>

BasicSensor::BasicSensor(const unsigned my_id, const std::string& msgQ_name)
    : msgHandler(std::make_unique<Msg>(msgQ_name))
    , id(my_id)
{
}

int BasicSensor::get_id() const
{
    return id;
}

void BasicSensor::send_data() const
{
    std::string msg("id: ");
    msg += std::to_string(id);
    msg += ": " + measure();
    msgHandler->send(msg);
}

void BasicSensor::start()
{
    while(true)
    {
        using namespace std::chrono_literals;
        send_data();
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 4 + 1));
    }
}
