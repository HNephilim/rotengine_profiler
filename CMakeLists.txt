cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RotProfiler VERSION 0.1)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp )
add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})

target_include_directories(RotRenderer PUBLIC include/)



if(PROFILER)
    add_compile_definitions(GENERIC_PROFILER)
endif()
