cmake_minimum_required(VERSION 3.14)
project(laboCiclos)

add_executable(laboCiclos
        cases.cpp
        cases.h
        ejercicios.cpp
        ejercicios.h
        main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})