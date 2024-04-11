cmake_minimum_required(VERSION 3.19)

project("bear")

file(GLOB HEAD_FILE ./*.h)

add_executable(bear ${HEAD_FILE} main.cpp)