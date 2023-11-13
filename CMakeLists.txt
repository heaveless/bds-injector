cmake_minimum_required(VERSION 3.27)

set(PROGRAM bds_injector)
project(${PROGRAM} LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(${PROGRAM} src/main.cpp)

target_link_libraries(${PROGRAM} PRIVATE fmt::fmt)
