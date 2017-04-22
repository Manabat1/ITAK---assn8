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

class Analyzer {
public:
    Analyzer(Configuration* config){
       this->config = config;
    }

protected:
    virtual void run(std::ifstream& fin){
        if(!fin.is_open()){
            throw std::string("File Not Open");
        }

        std::string inData;
        std::string* outData = new std::string[4];
        while(fin >> inData){
            //Should split into timestamp, src adress, src port, des port
            if(split(inData,',',outData,4)){
                m_data.push_back(outData);
            } else {
                throw std::string("Input String Read Incorrectly");
            }

        }
    };
    Configuration* config;
    std::vector<std::string*> m_data;
private:
};


#endif //ITAK_ANALYZER_HPP
