//
// Created by manab on 4/21/2017.
//

#include "AnalyzerSpecializationsTester.hpp"
#include "../Analyzer.hpp"
#include "../DenialOfServiceAnalyzer.hpp"
#include "../PortScanAnalyzer.hpp"
#include "../SourcePortAnalyzer.hpp"

void AnalyzerSpecializationsTester::testCreation() {
    Configuration* configuration = new Configuration();
    configuration->add("Random", "Stuff");
    //Testing if proper specialization by assigning to pointer of generalization
    Analyzer* denial = new DenialOfServiceAnalyzer(configuration);
    Analyzer* port = new PortScanAnalyzer(configuration);
    Analyzer* source = new SourcePortAnalyzer(configuration);

    PortScanAnalyzer portScanAnalyzer(configuration);
    DenialOfServiceAnalyzer denialOfServiceAnalyzer(configuration);
    SourcePortAnalyzer sourcePortAnalyzer(configuration);

    std::ifstream theStream;  //  = new std::fstream("../SampleData.csv");
    theStream.open("../SampleData.csv");


    try {
        denialOfServiceAnalyzer.run(theStream);
    } catch(std::string string){
        std::cout << "INVALID CONFIG " << string << std::endl;
    }
    theStream.close();

    theStream.open("../SampleData.csv");


    try {
        sourcePortAnalyzer.run(theStream);
    } catch(std::string string){
        std::cout << "INVALID CONFIG " << string << std::endl;
    }
    theStream.close();

    theStream.open("../SampleData.csv");


    try {
        portScanAnalyzer.run(theStream);
    } catch(std::string string){
        std::cout << "INVALID CONFIG " << string << std::endl;
    }
    theStream.close();


}

void AnalyzerSpecializationsTester::testResults() {


    std::ifstream fin;
    //Showing of a basic run

    //PortScanner
    Configuration* config2 = new Configuration();
    config2->add(config2->possible_attackers, "10");
    config2->add(config2->likely_attackers, "15");
    config2->add(config2->port_count, "5");

    PortScanAnalyzer portScanAnalyzer(config2);
    fin.open("SampleData.csv");

    try {
        portScanAnalyzer.run(fin);
    } catch (std::string e){
        std::cout << e << std::endl;
    }

    fin.close();

    portScanAnalyzer.print(std::cout);



    //TimeFrame

    Configuration* config = new Configuration();
    config->add(config->possible_attackers, "10");
    config->add(config->likely_attackers, "15");
    config->add(config->timeFrame, "80");
    DenialOfServiceAnalyzer denialOfServiceAnalyzer(config);

    fin.open("SampleData.csv");

    try {
        denialOfServiceAnalyzer.run(fin);
    } catch (std::string e){
        std::cout << e << std::endl;
    }
    fin.close();

    denialOfServiceAnalyzer.print(std::cout);


    //Source Port Scanner
    Configuration* config3 = new Configuration();
    config3->add(config3->possible_attackers, "10");
    config3->add(config3->likely_attackers, "15");
    config3->add(config3->port_count, "5");

    SourcePortAnalyzer sourcePortAnalyzer(config3);
    fin.open("SampleData.csv");

    try {
        sourcePortAnalyzer.run(fin);
    } catch (std::string e){
        std::cout << e << std::endl;
    }

    fin.close();

    sourcePortAnalyzer.print(std::cout);


    std::cout << "Analyzer Specializations Test Complete" << std::endl;
}
