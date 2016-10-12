cmake_minimum_required(VERSION 3.5)
project(FSMWoman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Locations.h EntityNames.h BaseGameEntity.cpp BaseGameEntity.h Miner.cpp Miner.h State.h MinerOwnedState.cpp MinerOwnedState.h MinersWife.cpp MinersWife.h MinersWifeOwnedStates.cpp MinersWifeOwnedStates.h StateMachine.h)
add_executable(FSMWoman ${SOURCE_FILES})