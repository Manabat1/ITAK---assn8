//
// Created by manab on 4/21/2017.
//

#include "AnalyzerTester.hpp"
#include "../Analyzer.hpp"
#include "../SourcePortAnalyzer.hpp"
#include <fstream>



void AnalyzerTester::testConstructor() {
    // NO ANALYZER CAN BE CREATED>>> ABSTRACT
    Configuration* configuration = new Configuration();
    configuration->add("Random", "Stuff");
    SourcePortAnalyzer sourcePortAnalyzer(configuration);
    std::ifstream fin;
    fin.open("SampleData.csv");
    try { //invalid config
        sourcePortAnalyzer.run(fin);
    } catch(std::string e){
        std::cout << e << std::endl;
    }
    fin.close();
    Configuration* configuration2 = new Configuration();
    configuration2->add(configuration2->possible_attackers, "2");
    configuration2->add(configuration2->likely_attackers, "10");
    SourcePortAnalyzer sourcePortAnalyzer2(configuration2);
    fin.open("SampleData.csv");
    try { //should work
        sourcePortAnalyzer2.run(fin);
    } catch(std::string e){
        std::cout << e << std::endl;
    }
    try {
        sourcePortAnalyzer2.print(std::cout);
    } catch (std::string s){
        std::cout << s << std::endl;
    }

    std::cout << "Analyzer Test Complete" << std::endl;
}
