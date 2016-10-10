cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(LCCVLabCG)

add_executable(LCCVLabCG src/main.cpp src/OpenGLCustomObj.h)
set(SOIL_FLAGS "-lSOIL")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
include_directories(/usr/include/SOIL)
link_directories(/usr/lib/SOIL)

target_link_libraries(LCCVLabCG ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} SOIL)