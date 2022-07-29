cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# set the project name and version
project(glut CXX)

# compile executable file
add_executable(glut main.cpp graphLine.cpp graphLine.h drawShape.cpp drawShape.h)

# link OpenGL library
target_link_libraries(glut -lglut -lGLU -lGL)
