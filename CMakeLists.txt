cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RotRenderer VERSION 0.1)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp )
add_executable(RotRenderer main.cpp ${SRC_FILES})

find_library(GLFW glfw3 vendor/glfw-3.3.8/lib-vc2022/)
find_library(VULKAN vulkan-1 $ENV{VULKAN_SDK}/Lib/)
target_include_directories(RotRenderer PUBLIC $ENV{VULKAN_SDK}/Include include/)
target_link_libraries(RotRenderer PUBLIC ${VULKAN} ${GLFW})


#PROFILER
add_subdirectory(include/tracy)

if(PROFILER)
    add_compile_definitions(TRACY_ENABLE)
    target_link_libraries(RotRenderer PUBLIC Tracy::TracyClient)
    
endif()
