cmake_minimum_required(VERSION 3.11-3.18)

project(Backend_lib)

add_library(Backend_lib Backend.cpp)

# PUBLIC needed to make both hello.h and hello library available elsewhere in project
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)