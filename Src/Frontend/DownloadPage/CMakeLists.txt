cmake_minimum_required(VERSION 3.11-3.18)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})