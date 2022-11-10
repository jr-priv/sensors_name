#pragma once
#include <string>
#include <mqueue.h>
class Msg
{
public:
    Msg(const std::string& msgQ_name);
    void send(const std::string& s);
    std::string receive();

private:
    mqd_t msgQ;
};
