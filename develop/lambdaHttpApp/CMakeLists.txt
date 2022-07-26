cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# set the project name and version
project(SampleSrc CXX)

# compile library file
add_library(PrintLog PrintLog.cpp)

# compile executable file
add_executable(http_server http_server.cpp PrintLog)
add_executable(http_client http_client.cpp PrintLog)
