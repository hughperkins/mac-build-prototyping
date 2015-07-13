cmake_minimum_required(VERSION 2.8)

add_library(mylib mylib.cpp)
add_executable(myexe myexecutable.cpp)
target_link_libraries(myexe mylib)


