# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)
project(CompanySimulation)

include_directories(include)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

set(TEST_SOURCES ${SOURCES})
list(FILTER TEST_SOURCES EXCLUDE REGEX ".*main\\.cpp")

add_executable(testcatch test.cpp ${TEST_SOURCES})

target_include_directories(testcatch PRIVATE include)
enable_testing()
