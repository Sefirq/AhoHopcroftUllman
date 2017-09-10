cmake_minimum_required(VERSION 3.8)
project(AhoHopcroftUllman)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
add_executable(DSAA_run ${SOURCE_FILES})

include_directories(DataStructuresAndAlgorithms)

add_subdirectory(DataStructuresAndAlgorithms)
add_subdirectory(DataStructuresAndAlgorithmsTests)

target_link_libraries(DSAA_run DataStructuresAndAlgorithms)