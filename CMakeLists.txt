cmake_minimum_required(VERSION 3.11-3.18)
project(SatInfo VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

include(CTest)
enable_testing()

add_subdirectory(Src)
