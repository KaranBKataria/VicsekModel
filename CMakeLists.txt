cmake_minimum_required(VERSION 4.3)
project(VicsekModel)

set(CMAKE_CXX_STANDARD 23)

add_executable(VicsekModel src/main.cpp
        include/particle.h
        src/vicsekStep.cpp
        include/vicsekStep.h
        src/Simulation.cpp
        include/Simulation.h
        include/stateSpace.h
        include/utils.h
)
