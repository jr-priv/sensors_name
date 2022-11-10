#include "Server.hpp"
#include <unistd.h>

int main()
{
    Server server{};
    server.start();
}