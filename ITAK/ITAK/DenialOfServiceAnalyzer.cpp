//
// Created by manab on 4/17/2017.
//


#include "DenialOfServiceAnalyzer.hpp"
#include "Configuration.hpp"
void DenialOfServiceAnalyzer::run(std::ifstream &fin) {
    verifyConfig();
    if(!fin.is_open()){
        throw std::string("File Not Open");
    }
    //std::cout << "Ln 12 denial.cpp " << std::endl;
    std::string inData;
    std::string* outData= new std::string[4];
    while(fin >> inData){
        //Should split into timestamp, src adress, src port, des port
        //Dictionary should be <IP , <timestamp , counter >>
        if(split(inData,',',outData,4)){
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

        } else {
            throw std::string("Input String Read Incorrectly");
        }
    }
    //ALL data should be stored in dataHolder now
    createResultSet();
}

void DenialOfServiceAnalyzer::createResultSet() {

    results = new ResultSet();
    results->add(config->likely_attackers,new std::vector<std::string>);
    results->add(config->possible_attackers,new std::vector<std::string>);
    results->add(config->attack_periods,new std::vector<std::string>);
    results->add(config->timeFrame,new std::vector<std::string>);
    int timeframe = config->getValueAsInt(config->timeFrame);
    results->getValue(config->timeFrame)->push_back(std::to_string(timeframe));

    int likelyThreshold = config->getValueAsInt(config->likely_attackers);
    int possibleThreshold = config->getValueAsInt(config->possible_attackers);
    //   Dictionary<std::string,Dictionary<std::string,int>*>* dataHolder;
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

void DenialOfServiceAnalyzer::print(std::ostream& stream) {
    results->print(stream);

}

void DenialOfServiceAnalyzer::verifyConfig() {
    //These will all throw a string if they are invalid
    config->getValue(config->likely_attackers);
    config->getValue(config->possible_attackers);
    config->getValue(config->timeFrame);
}
