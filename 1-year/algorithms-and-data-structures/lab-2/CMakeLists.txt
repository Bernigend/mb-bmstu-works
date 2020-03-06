cmake_minimum_required(VERSION 3.15)
project(lab_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2 main.cpp Table.cpp Table.h TableElement.h KeyOrdTable.cpp KeyOrdTable.h ValueOrdTable.cpp ValueOrdTable.h)