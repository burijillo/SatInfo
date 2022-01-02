cmake_minimum_required(VERSION 3.11-3.18)

project(SatInfo)

add_subdirectory(Backend)
add_subdirectory(Frontend)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Frontend_lib)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)