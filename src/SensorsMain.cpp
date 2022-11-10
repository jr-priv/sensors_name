#include "Temperature.hpp"
#include "Ultrasonic.hpp"
#include <iostream>
#include <vector>
#include <thread>

int main()
{
    std::vector<std::unique_ptr<BasicSensor>> sensors;
    sensors.emplace_back(std::make_unique<TemperatureSensor>(1, "/server"));
    sensors.emplace_back(std::make_unique<TemperatureSensor>(2, "/server"));
    sensors.emplace_back(std::make_unique<UltrasonicSensor>(3, "/server"));
    sensors.emplace_back(std::make_unique<UltrasonicSensor>(4, "/server"));

    std::vector<std::thread> threadVec;
    for(auto& sensor: sensors)
    {
        threadVec.emplace_back(std::thread([&sensor]{sensor->start();}));
    }
    for(auto& thread: threadVec)
    {
        thread.join();
    }

}
