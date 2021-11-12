cmake_minimum_required(VERSION 3.11-3.18)

project(Frontend_lib)

add_library(Frontend_lib Frontend_entryPoint.cpp MainPage/mainPage.cpp Res/Frame.cpp LogView/LogView.cpp)

add_subdirectory(MainPage)
add_subdirectory(Res)

find_package(wxWidgets REQUIRED COMPONENTS net core base aui)
include(${wxWidgets_USE_FILE})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} Backend_lib)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)