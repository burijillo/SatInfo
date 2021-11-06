cmake_minimum_required(VERSION 3.11-3.18)

project(SatInfo)

add_subdirectory(Backend)
add_subdirectory(Frontend)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Frontend_lib)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)