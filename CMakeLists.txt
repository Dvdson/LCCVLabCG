cmake_minimum_required(VERSION 3.5)
project(LCCVLabCG)


set(OPENGL_FLAGS "-lGL -lglut -lGLU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${OPENGL_FLAGS}")

set(MAIN src/main.cpp)
set(OBJECTS Object.cpp Object.h)
add_executable(CG_Exercises ${MAIN} ${OBJECTS} )