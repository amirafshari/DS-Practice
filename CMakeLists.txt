cmake_minimum_required(VERSION 3.0.0)

# define the project
project(main VERSION 0.1.0)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)

# includes
include_directories(/usr/include /usr/include/opencv4 /usr/include/opencv4/opencv2 /usr/include/soci /usr/include/mysql /usr/include/x86_64-linux-gnu/qt5) 


# subdirectories
add_subdirectory(core)
add_subdirectory(thread)

# EXECUTE
add_executable(main main.cpp)

# include libs
target_include_directories(main PUBLIC ui)

# compile options
target_compile_options(main PUBLIC -fPIC)

# link libs
target_link_libraries(main PUBLIC core thread zbar ${OpenCV_LIBS} Qt5::Core Qt5::Core Qt5::Widgets soci_core soci_mysql) 
