cmake_minimum_required(VERSION 3.8)

project(TEXT_EDITOR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(include)

add_executable(Text_Editor src/Text_Editor.cpp)