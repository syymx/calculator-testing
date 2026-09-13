cmake_minimum_required(VERSION 3.16)

project(calculator_testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(calculator_app
    app/main.cpp
)

target_include_directories(calculator_app PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

find_package(GTest REQUIRED)

enable_testing()

add_executable(calculator_tests
    tests/test_smoke.cpp

    tests/test_basic.cpp
    tests/test_precedence.cpp
    tests/test_parentheses.cpp
    tests/test_bitwise.cpp
    tests/test_complex.cpp
)

target_include_directories(calculator_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(calculator_tests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(calculator_tests)