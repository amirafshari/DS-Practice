cmake_minimum_required(VERSION 2.8)

# project name
project(Project)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(source_dir "${PROJECT_SOURCE_DIR}/src")

file(GLOB source_files "${source_dir}/*.cpp")

find_package(OpenCV REQUIRED)

# include directory for OpenCV
#include_directories(/usr/include/opencv4/)


add_executable(Project ${source_files})

target_link_libraries(Project ${OpenCV_LIBS} zbar)
