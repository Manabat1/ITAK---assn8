//
// Created by manab on 4/17/2017.
//

#ifndef ITAK_PORTSCANANALYZER_HPP
#define ITAK_PORTSCANANALYZER_HPP


#include "Analyzer.hpp"
#include "ResultSet.hpp"
#include <vector>

class PortScanAnalyzer : public Analyzer{
public:
    PortScanAnalyzer(Configuration* config)
        :Analyzer(config){
        dataHolder = new Dictionary<std::string,std::vector<int>*>();
    }
    void run(std::ifstream& fin);
    void print(std::ostream& stream);
    void verifyConfig();
private:
    void createResultSet();
    ResultSet* results;
    Dictionary<std::string,std::vector<int>*>* dataHolder;
};


#endif //ITAK_PORTSCANANALYZER_HPP
