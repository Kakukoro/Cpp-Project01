cmake_minimum_required(VERSION 3.10)
project(SeqProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)          # -g so the debugger works

add_executable(seqproject src/main.cpp src/Sequence.cpp)
target_include_directories(seqproject PRIVATE include)
