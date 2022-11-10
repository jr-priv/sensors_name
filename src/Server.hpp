#pragma once

#include "Temperature.hpp"
#include "Msg.hpp"
#include <vector>
#include <memory>
#include <mqueue.h>



class Server
{
public:
    Server();
    void start();
    void stop();

private:
    std::unique_ptr<Msg> msgHandler;
    std::vector<std::unique_ptr<BasicSensor>> sensors;
};

