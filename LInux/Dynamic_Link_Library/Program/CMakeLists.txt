
                                    /*****************************************************************************
                                    *   Author: Radwa Mahmoud                                                    *
                                    *   Date  : 20/10/2023                                                       *
                                    *   Task  : Cmake to link our app with our created Control_PC shared library *
                                    *****************************************************************************/

cmake_minimum_required(VERSION 3.16.3)
project (program)

find_library(CONTROL_LIB libControl_PC.so)
message(STATUS ${CONTROL_LIB})

add_executable(binary main.cpp)
target_link_libraries(binary PRIVATE ${CONTROL_LIB})
