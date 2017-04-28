//
// Created by manab on 4/17/2017.
//


#include "DenialOfServiceAnalyzer.hpp"
#include "Configuration.hpp"
void DenialOfServiceAnalyzer::runMini(std::string* outData) {
    try{ // if the IP exists
        Dictionary<long,int>* temp = dataHolder->getValue(outData[1]);
        try {
            temp->setValueByKey(std::stol(outData[0]), (temp->getValue(std::stol(outData[0]))) + 1);
        }catch(std::string){ // New attack time
            //temp->add(std::stol(outData[0]),1);
            dataHolder->getValue(outData[1])->   //Get the IP Dictionary
                    add(std::stol(outData[0]),1); //add a record to that dictionary
        }
    } catch(std::string d){ // first time ip address
        Dictionary<long,int>* temp2 = new Dictionary<long,int>;
        temp2->add(std::stol(outData[0]),1); // create time/count record
        dataHolder->add(outData[1], temp2); //add record to IP dictionary
    }
}

void DenialOfServiceAnalyzer::createResultSet(int likelyThreshold, int possibleThreshold) {


    results->add(config->attack_periods,new std::vector<std::string>);
    results->add(config->timeFrame,new std::vector<std::string>);
    int timeframe = config->getValueAsInt(config->timeFrame);
    results->getValue(config->timeFrame)->push_back(std::to_string(timeframe));

    for(KeyValue<std::string,Dictionary<long,int>*>* kv : dataHolder->m_keyValues){ // Iterates through Ip dictionary
        for(KeyValue<long,int>* inKv : kv->getValue()->m_keyValues) { // iterates though ip address's attack details
            long startTime = inKv->getKey();
            int startCount = 0;
            for (KeyValue<long, int> *afterKv : kv->getValue()->m_keyValues) {
                if ((afterKv->getKey() <= inKv->getKey() + timeframe)) {
                    startCount += afterKv->getValue();
                }
            }
            if(startCount >= likelyThreshold){
                results->getValue(config->likely_attackers)->push_back( kv->getKey());
                std::string toAdd = "" + std::to_string(startTime) + " to " + std::to_string(startTime+timeframe);
                results->getValue(config->attack_periods)->push_back(toAdd);
            } else if (startCount >= possibleThreshold){
                results->getValue(config->possible_attackers)->push_back("" + kv->getKey());
                std::string toAdd = "" + std::to_string(startTime) + " to " + std::to_string(startTime+timeframe);
                results->getValue(config->attack_periods)->push_back(toAdd);
            }
        }

    }
    // All stuffs should be in the result set now

}



void DenialOfServiceAnalyzer::verifyConfig() {
    config->getValue(config->timeFrame);
}
