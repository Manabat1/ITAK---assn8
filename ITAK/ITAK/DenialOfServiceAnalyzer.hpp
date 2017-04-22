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
            :Analyzer(config){
        dataHolder = new Dictionary<std::string,Dictionary<long,int>*>();
    }

    void run(std::ifstream& fin);
    void createResultSet();
    void print(std::ostream& stream);
    void verifyConfig();
private:

    Dictionary<std::string,Dictionary<long,int>*>* dataHolder;
    ResultSet* results;
};


#endif //ITAK_DENIALOFSERVICEANALYZER_HPP
