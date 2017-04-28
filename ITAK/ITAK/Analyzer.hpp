//
// Created by manab on 4/17/2017.
//

#ifndef ITAK_ANALYZER_HPP
#define ITAK_ANALYZER_HPP


#include <ostream>
#include <fstream>
#include <vector>
#include "Utils.hpp"
#include "Configuration.hpp"
#include "ResultSet.hpp"


class Analyzer {
public:
    // MUST PASS IN AN ANALYZER !!! GUI SHOULD TAKE CARE OF IT...
    Analyzer(Configuration* config, Analyzer* analyzer){
        this->config = config;
        this->concreteAnalyzer = analyzer;
    }

    void run(std::ifstream& fin){
        verifyConfig();
        if(!fin.is_open()){
            throw std::string("File Not Open");
        }

        std::string inData;
        std::string* outData = new std::string[4];
        while(fin >> inData){
            //Should split into timestamp, src adress, src port, des port
            if(split(inData,',',outData,4)){
                concreteAnalyzer->runMini(outData);
            } else {
                throw std::string("Input String Read Incorrectly");
            }
        }
        createResultSet();
    };
    void print(std::ostream &stream) {
        results->print(stream);
    }
    std::string getName(){ return m_name;};
protected:
    virtual void runMini(std::string* outData)=0;
    virtual void createResultSet(int,int)=0;
    virtual void verifyConfig(){
        concreteAnalyzer->verifyConfig();
        config->getValue(config->likely_attackers);
        config->getValue(config->possible_attackers);
    }

    void createResultSet(){
        results = new ResultSet();
        results->add(config->likely_attackers,new std::vector<std::string>);
        results->add(config->possible_attackers,new std::vector<std::string>);

        int likelyThreshold = config->getValueAsInt(config->likely_attackers);
        int possibleThreshold = config->getValueAsInt(config->possible_attackers);

        concreteAnalyzer->createResultSet(likelyThreshold,possibleThreshold);
    }
    std::string m_name;
    Configuration* config;
    ResultSet* results;
private:
    Analyzer* concreteAnalyzer;
};


#endif //ITAK_ANALYZER_HPP
