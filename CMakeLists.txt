cmake_minimum_required(VERSION 3.14)
project(algorithms_yandex)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(algorithms_yandex pisano_period.cpp)
