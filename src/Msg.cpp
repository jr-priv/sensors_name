#include "Msg.hpp"
#include <stdexcept>
#include <string.h>
#include <iostream>

namespace
{
    constexpr int bufsize = 1024;
}

Msg::Msg(const std::string& msgQ_name)
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = bufsize;
    attr.mq_curmsgs = 0;
    
    if((msgQ =
        mq_open(msgQ_name.c_str(), O_RDWR | O_CREAT, 0660, &attr)) == -1)
    {
        throw(std::runtime_error("Can not open mq. "
                        + std::string(strerror(errno))));
    }
}

void Msg::send(const std::string& msg)
{
    if(mq_send(msgQ, msg.data(), msg.size() + 1, 0) < 0)
    {
        throw(std::runtime_error("Can not send data. "
                        + std::string(strerror(errno))));
    }
}

std::string Msg::receive()
{
    char buf[bufsize];
    int ret = mq_receive(msgQ, buf, bufsize, 0);
    if(ret < 0)
    {
        throw(std::runtime_error("Can not read data. "
                        + std::string(strerror(errno))));
    }
    return std::string(buf);
}
