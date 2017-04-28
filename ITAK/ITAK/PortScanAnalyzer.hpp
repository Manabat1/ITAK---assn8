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
        :Analyzer(config,this){
        dataHolder = new Dictionary<std::string,std::vector<int>*>();
        m_name = "Port Scan Analyzer";
    }
    void runMini(std::string* outData);
    void verifyConfig(){}
    void createResultSet(int likelyThreshold, int possibleThreshold);
private:
    Dictionary<std::string,std::vector<int>*>* dataHolder;
};


#endif //ITAK_PORTSCANANALYZER_HPP
