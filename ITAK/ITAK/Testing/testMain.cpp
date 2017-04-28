//
// Created by manab on 4/21/2017.
//


#include <iostream>
#include <sstream>
#include "../Utils.hpp"
#include "ResultSetTester.hpp"
#include "ConfigurationTester.hpp"
#include "AnalyzerTester.hpp"
#include "AnalyzerSpecializationsTester.hpp"


int main(void){


    ResultSetTester resultSetTester;
    resultSetTester.testCreation();
    resultSetTester.testPrint();

    ConfigurationTester configurationTester;
    configurationTester.testConfigurations();

    AnalyzerTester analyzerTester;
    analyzerTester.testConstructor();

    AnalyzerSpecializationsTester analyzerSpecializationsTester;
    analyzerSpecializationsTester.testCreation();
    analyzerSpecializationsTester.testResults();

    return 0;
}
/**
 *  test for split
 *     std::string test = "mew,3.5.6.7,45,46 ";
    std::string* out = new std::string[4];
    split(test,',',out,4);
    for(int i = 0; i < 4; i++){
        std::cout <<out[i] <<std::endl;
    }

 *
 */
