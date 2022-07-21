cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# set the project name and version
project(SampleSrc CXX)

add_executable(http_server http_server.cpp)
add_executable(http_client http_client.cpp)
