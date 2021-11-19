cmake_minimum_required(VERSION 3.11-3.18)

project(Backend_lib)

find_package(CURL REQUIRED)
add_library(Backend_lib Backend.cpp curl/curl_manager.cpp Log/Logger.cpp DataParser/DataParser.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} libcurl.so)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)