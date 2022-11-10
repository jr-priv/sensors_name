#include "Server.hpp"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

Server::Server()
    : msgHandler(std::make_unique<Msg>("/server"))
{
}

void Server::start()
{
    while (true)
    {
        auto msg = msgHandler->receive();
        std::cout << msg << std::endl;
    }
}

void Server::stop()
{
    //tbd
}
