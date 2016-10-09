cmake_minimum_required(VERSION 3.6)
project(FSM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Locations.h EntityNames.h BaseGameEntity.cpp BaseGameEntity.h Miner.cpp Miner.h State.h MinerOwnedState.cpp MinerOwnedState.h)
add_executable(FSM ${SOURCE_FILES})