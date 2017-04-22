//
// Created by manab on 4/21/2017.
//

#include "AnalyzerTester.hpp"
#include "../Analyzer.hpp"
#include <fstream>

void AnalyzerTester::testDefaultRun() {
    Configuration* configuration = new Configuration();
    configuration->add("Random", "Stuff");
    Analyzer analyzer(configuration);
    std::fstream theStream;  //  = new std::fstream("../SampleData.csv");
    theStream.open("../SampleData.csv");

    //_____ Pops up protected, as should _________
    //analyzer.run(theStream);
    theStream.close();
}

void AnalyzerTester::testConstructor() {
    Configuration* configuration = new Configuration();
    configuration->add("Random", "Stuff");
    Analyzer analyzer(configuration);


    Configuration* configuration2 = new Configuration();
    configuration2->add("weird", "Stuff");
    configuration2->add("fee", "Stuff");
    configuration2->add("asdda", "dasads");
    Analyzer analyzer2(configuration2);

    Analyzer analyzer3(configuration2);

    std::cout << "Analyzer Test Complete" << std::endl;
}
