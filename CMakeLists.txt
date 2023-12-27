cmake_minimum_required(VERSION 3.27)
project(LearnOpenGL2024)

set(CMAKE_CXX_STANDARD 17)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(External/glfw)

# GLAD
add_subdirectory(External/glad)

# Executable
add_executable(LearnOpenGL2024 LearnOpenGL/src/Main.cpp)

# Linker
target_link_libraries(LearnOpenGL2024 glfw glad)