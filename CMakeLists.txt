cmake_minimum_required(VERSION 3.21)
project(BigReal_A2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigReal_A2
        BigDecimalIntClass.cpp
        BigDecimalIntClass.h)
