cmake_minimum_required(VERSION 3.0.0)
project(rt)

add_executable(rt auto.cpp Main.cpp CComplexVector.h CComplexVector0.h CComplexVector1.h CFabric.h CFabric0.h CFabric1.h CFabric.cpp CComplexVector.cpp CComplexVector0.cpp CComplexVector1.cpp autotests.cpp autotests.h)

set (CMAKE_CXX_FLAGS "-fopenmp")
