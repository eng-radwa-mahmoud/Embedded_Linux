cmake_minimum_required(VERSION 3.16.3)

project(simple_lib)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(PCControl SHARED Executer.cpp Server.cpp)

install(TARGETS PCControl DESTINATION /usr/lib)
install(FILES include/Server.hpp include/Executer.hpp DESTINATION include)