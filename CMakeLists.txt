cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(LCCVLabCG)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(OPENGL_FLAGS "-lGL -lglut -lGLU")

set(SOIL_LIB
        src/SOIL.h
        src/SOIL.c
        src/image_helper.h
        src/image_helper.c
        src/image_DXT.h
        src/image_DXT.c
        src/stb_image_aug.c
        src/stb_image_aug.h
        src/stbi_DDS_aug.h
        src/stbi_DDS_aug_c.h
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${OPENGL_FLAGS}")

add_executable(LCCVLabCG src/main.cpp src/OpenGLCustomObj.h ${SOIL_LIB})
