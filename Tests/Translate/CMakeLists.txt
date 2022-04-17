cmake_minimum_required(VERSION 3.16)

project(6502Assembler)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17 -Werror -D CMAKE_CXX_COMPILER=/usr/bin/g++-11")

set(SRC TestTranslateInstructionToHexOpcode.cpp 
        ../../src/Translate.h
        ../../src/Translate.cpp
        ../../src/OpCodes.cpp
        ../../src/OpCodes.h
   )

find_package(Catch2 3 REQUIRED)

add_executable(Tests ${SRC})

include_directories("${CMAKE_SOURCE_DIR}/../../src/")

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)
