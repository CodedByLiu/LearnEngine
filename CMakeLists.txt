cmake_minimum_required(VERSION 3.28)

project(LearnEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(Sandbox)

target_sources(Sandbox PRIVATE
    src/main.cpp
)

target_sources(Sandbox PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    src/Core.ixx
    src/Log.ixx
    src/Window.ixx
)

target_link_libraries(Sandbox PRIVATE 
    spdlog::spdlog 
    glfw
    opengl32
)