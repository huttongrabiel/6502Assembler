cmake_minimum_required(VERSION 3.16)

project(6502Assembler)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -D CMAKE_CXX_COMPILER=g++-11")

set(SRC OpCodes.cpp
        OpCodes.h
   )

add_executable(Whuty6502Assembler SRC)

include_directories("${CMAKE_SOURCE_DIR}/src/")