cmake_minimum_required(VERSION 3.16)
project(Namespace LANGUAGES CXX)
add_executable(${PROJECT_NAME} src/main.cpp)
include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/include)