cmake_minimum_required(VERSION 3.6)
project(Dictionary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.hpp KeyValue.hpp )
set(TEST_FILES Testing/testMain.cpp Testing/DictionaryTester.hpp Testing/KeyValueTester.hpp Testing/KeyValueTester.cpp Testing/DictionaryTester.cpp)

add_executable(Dictionary ${SOURCE_FILES})
add_executable(Test ${TEST_FILES})