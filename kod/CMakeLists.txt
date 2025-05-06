# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)
project(CompanySimulation)

include_directories(include)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})