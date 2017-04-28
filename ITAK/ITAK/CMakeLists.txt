cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ResultSet.cpp
        ResultSet.hpp
        Analyzer.hpp
        PortScanAnalyzer.cpp
        PortScanAnalyzer.hpp
        DenialOfServiceAnalyzer.cpp
        DenialOfServiceAnalyzer.hpp
        Configuration.cpp
        Configuration.hpp
        Utils.cpp
        Utils.hpp
        Dictionary.hpp
        KeyValue.hpp
        SourcePortAnalyzer.cpp
        SourcePortAnalyzer.hpp
        Menu.cpp
        Menu.h
        MenuOption.cpp
        MenuOption.h
        UserInterface.cpp
        UserInterface.h)
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/AnalyzerTester.cpp
        Testing/AnalyzerTester.hpp
        Testing/ResultSetTester.cpp
        Testing/ResultSetTester.hpp
        Testing/ConfigurationTester.cpp
        Testing/ConfigurationTester.hpp
        Testing/AnalyzerSpecializationsTester.cpp
        Testing/AnalyzerSpecializationsTester.hpp)

add_executable(TEST Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})