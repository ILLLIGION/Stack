cmake_minimum_required(VERSION 2.8.7)
project(Stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests/)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/Stack.cpp)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/examples/main.cpp)
add_executable(tests ${TESTS_SOURCE} tests/main.cpp tests/push.cpp tests/pop.cpp tests/count.cpp)
