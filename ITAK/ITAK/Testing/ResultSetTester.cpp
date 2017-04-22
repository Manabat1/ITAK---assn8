//
// Created by manab on 4/21/2017.
//

#include "ResultSetTester.hpp"
#include "../ResultSet.hpp"

void ResultSetTester::testPrint() {

    ResultSet resultSet;
    resultSet.add("Results",new std::vector<std::string>);
    resultSet.getValue("Results")->push_back("Sup");
    resultSet.getValue("Results")->push_back("Hi");
    resultSet.getValue("Results")->push_back("Bye");
    resultSet.getValue("Results")->push_back("Oop");
    resultSet.getValue("Results")->push_back("No");
    resultSet.add("Other things",new std::vector<std::string>);
    resultSet.getValue("Other things")->push_back("333");
    resultSet.getValue("Other things")->push_back("33");
    resultSet.getValue("Other things")->push_back("222");
    resultSet.getValue("Other things")->push_back("Oo111p");
    resultSet.getValue("Other things")->push_back("11");
    resultSet.print(std::cout);

    std::cout << "Result Set Test Complete" << std::endl;
}

void ResultSetTester::testCreation() {
    ResultSet resultSet;
    resultSet.add("Results",new std::vector<std::string>);
    resultSet.getValue("Results")->push_back("Sup");
    try {
        resultSet.getValue("Non existent")->push_back("Sup2");
    }catch (std::string s){
        //Should be thrown and caught
    }

    //should be able to actually add the value now
    resultSet.add("Non existent",new std::vector<std::string>);
    resultSet.getValue("Non existent")->push_back("Sup2");

}
