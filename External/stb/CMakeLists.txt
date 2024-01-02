cmake_minimum_required(VERSION 3.27)
project(stb)

add_library(stb include/stb_image.h src/stb_image.cpp)
target_include_directories(stb PUBLIC include/)