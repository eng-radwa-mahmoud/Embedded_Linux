cmake_minimum_required(VERSION 3.16.3)
project (program)

find_library(CONTROL_LIB libControl_PC.so)
message(STATUS ${CONTROL_LIB})

add_executable(binary main.cpp)
target_link_libraries(binary PRIVATE ${CONTROL_LIB})
