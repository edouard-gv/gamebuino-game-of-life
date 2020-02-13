cmake_minimum_required(VERSION 3.15)
project(gameoflife)

set(CMAKE_CXX_STANDARD 14)

add_executable(gameoflife gameoflife.ino)
include_directories(MyLib_lib)
add_subdirectory(MyLib_lib)

add_subdirectory(Google_test)

target_link_libraries(gameoflife MyLib_lib)
