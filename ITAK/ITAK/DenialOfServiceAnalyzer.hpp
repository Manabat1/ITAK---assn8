//
// Created by manab on 4/17/2017.
//

#ifndef ITAK_DENIALOFSERVICEANALYZER_HPP
#define ITAK_DENIALOFSERVICEANALYZER_HPP


#include <ostream>
#include "Analyzer.hpp"
#include "ResultSet.hpp"

class DenialOfServiceAnalyzer : public Analyzer{
public:
    DenialOfServiceAnalyzer(Configuration* config)
            :Analyzer(config,this){
        dataHolder = new Dictionary<std::string,Dictionary<long,int>*>();
        m_name = "Denial Of Service Analyzer";
    }

    void runMini(std::string* outData);
    void createResultSet(int likelyThreshold, int possibleThreshold);
    void verifyConfig();
private:
    Dictionary<std::string,Dictionary<long,int>*>* dataHolder;
};


#endif //ITAK_DENIALOFSERVICEANALYZER_HPP
