cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(LCCVLabCG)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(OBJECTS)

add_executable(LCCVLabCG src/main.cpp Wall.cpp Wall.h src/OpenGLCustomObj.h)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(LCCVLabCG ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(LCCVLabCG Qt5::Widgets)
