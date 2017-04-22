//
// Created by manab on 4/17/2017.
//

#include "PortScanAnalyzer.hpp"

void PortScanAnalyzer::run(std::ifstream &fin) {
    verifyConfig();
    if(!fin.is_open()){
        throw std::string("File Not Open");
    }

    std::string inData;
    std::string* outData= new std::string[4];
    while(fin >> inData){
        //Should split into timestamp, src adress, src port, des port
        //Dictionary should be <IP , vector<int>>
        if(split(inData,',',outData,4)){
            try{ // if that value exists
                std::vector<int>* temp = dataHolder->getValue(outData[1]);
                temp->push_back(std::stoi(outData[3]));
            } catch(std::string d){ // otherwise
                std::vector<int>* temp = new std::vector<int>;
                temp->push_back(std::stoi(outData[3]));
                dataHolder->add(outData[1], temp);
            }
        } else {
            throw std::string("Input String Read Incorrectly");
        }
    }
    //ALL data should be stored in dataHolder now
    createResultSet();
}

void PortScanAnalyzer::createResultSet() {

    results = new ResultSet();
    results->add(config->likely_attackers,new std::vector<std::string>);
    results->add(config->possible_attackers,new std::vector<std::string>);
    results->add(config->port_count,new std::vector<std::string>);

    //results->getValue(config->port_count)->push_back("Likely Ports: " + config->getValueAsString(config->likely_attackers));
   // results->getValue(config->port_count)->push_back("Likely Ports: " + config->getValueAsString(config->likely_attackers));
    int likelyThreshold = config->getValueAsInt(config->likely_attackers);
    int possibleThreshold = config->getValueAsInt(config->possible_attackers);

    results->getValue(config->port_count)->push_back("Likely: " + std::to_string(likelyThreshold));
    results->getValue(config->port_count)->push_back("Possible: " + std::to_string(possibleThreshold));
    //   Dictionary<std::string,std::vector<int>*>* dataHolder;
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

void PortScanAnalyzer::print(std::ostream &stream) {
    results->print(stream);
}

void PortScanAnalyzer::verifyConfig() {
    //These will all throw a string if they are invalid
    config->getValue(config->likely_attackers);
    config->getValue(config->possible_attackers);
    //config->getValue(config->port_count);

}
