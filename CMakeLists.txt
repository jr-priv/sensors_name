cmake_minimum_required(VERSION 3.0.0)
project (sensors_network)
set(CMAKE_CXX_STANDARD 17)

add_executable(server
  src/Msg.cpp
  src/Server.cpp
  src/ServerMain.cpp)

target_link_libraries(server
  pthread
  rt)

add_executable(sensors
  src/Msg.cpp
  src/BasicSensor.cpp
  src/Temperature.cpp
  src/Ultrasonic.cpp
  src/SensorsMain.cpp)

target_link_libraries(sensors
  pthread
  rt)
