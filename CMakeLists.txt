cmake_minimum_required(VERSION 4.3)
project(VicsekModel VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(${PROJECT_NAME} src/main.cpp
        include/particle.h
        src/vicsekStep.cpp
        include/vicsekStep.h
        src/Simulation.cpp
        include/Simulation.h
        include/stateSpace.h
        include/utils.h
)