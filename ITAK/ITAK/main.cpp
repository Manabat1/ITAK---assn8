#include <iostream>
#include "DenialOfServiceAnalyzer.hpp"
#include "PortScanAnalyzer.hpp"

int main() {

    std::ifstream fin;
    //Showing of a basic run
    std::cout << "Port Scan" << std::endl;

    //PortScanner
    Configuration* config2 = new Configuration();
    config2->add(config2->possible_attackers, "2");
    config2->add(config2->likely_attackers, "10");
   // config2->add(config2->port_count, "5");

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
    std::cout << "DOS" << std::endl;


    Configuration* config = new Configuration();
    config->add(config->possible_attackers, "10");
    config->add(config->likely_attackers, "15");
    config->add(config->timeFrame, "10");
    DenialOfServiceAnalyzer denialOfServiceAnalyzer(config);

    fin.open("SampleData.csv");

    try {
        denialOfServiceAnalyzer.run(fin);
    } catch (std::string e){
        std::cout << e << std::endl;
    }
    fin.close();

    denialOfServiceAnalyzer.print(std::cout);

    std::cout << "The End" << std::endl;


    return 10;
}