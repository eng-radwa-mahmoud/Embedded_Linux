                    /**************************************************************
                    *   Author: Radwa Mahmoud                                     *
                    *   Date  : 20/10/2023                                        *   
                    *   Task  : Cmakefile to create PC_Control as shared library  *
                    **************************************************************/

cmake_minimum_required(VERSION 3.16.3)
project (pc_control)

add_library(Control_PC SHARED Executer.cpp Server.cpp)

install(TARGETS Control_PC DESTINATION /usr/lib)
install(FILES Server.hpp Executer.hpp DESTINATION include)
