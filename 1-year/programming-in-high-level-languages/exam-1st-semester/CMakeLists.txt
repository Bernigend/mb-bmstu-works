cmake_minimum_required(VERSION 3.15)
project(exam_1st_semester)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(exam_1st_semester main.cpp functions.h structs.h functions.cpp)