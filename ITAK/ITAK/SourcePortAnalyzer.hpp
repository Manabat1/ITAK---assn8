//
// Created by manab on 4/25/2017.
//

#ifndef ITAK_SOURCEPORTANALYZER_HPP
#define ITAK_SOURCEPORTANALYZER_HPP


#include "Analyzer.hpp"
#include "ResultSet.hpp"

class SourcePortAnalyzer : public Analyzer{
public:
    SourcePortAnalyzer(Configuration *config)
    :Analyzer(config,this){
            dataHolder = new Dictionary<std::string,std::vector<int>*>();
        m_name = "Source Port Analyzer";
    }
    void runMini(std::string* outData);
    void createResultSet(int likelyThreshold, int possibleThreshold);
    void verifyConfig(){}

private:
    Dictionary<std::string,std::vector<int>*>* dataHolder;
};


#endif //ITAK_SOURCEPORTANALYZER_HPP
