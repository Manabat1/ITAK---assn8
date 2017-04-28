//
// Created by manab on 4/25/2017.
//

#include "SourcePortAnalyzer.hpp"


void SourcePortAnalyzer::runMini(std::string* outData) {
    try{ // if that value exists
        std::vector<int>* temp = dataHolder->getValue(outData[1]);
        temp->push_back(std::stoi(outData[2]));
    } catch(std::string d){ // otherwise
        std::vector<int>* temp = new std::vector<int>;
        temp->push_back(std::stoi(outData[2]));
        dataHolder->add(outData[1], temp);
    }
}

void SourcePortAnalyzer::createResultSet(int likelyThreshold, int possibleThreshold) {

    results->add(config->port_count,new std::vector<std::string>);
    results->getValue(config->port_count)->push_back("Likely: " + std::to_string(likelyThreshold));
    results->getValue(config->port_count)->push_back("Possible: " + std::to_string(possibleThreshold));

    for(KeyValue<std::string,std::vector<int>*>* kv : dataHolder->m_keyValues){
        std::string src = kv->getKey();
        int portAmount = kv->getValue()->size();
        if(portAmount >= likelyThreshold){
            results->getValue(config->likely_attackers)->push_back(src + " " + std::to_string(portAmount));
        } else if (portAmount >= possibleThreshold){
            results->getValue(config->possible_attackers)->push_back(src);
        }

    }
}

