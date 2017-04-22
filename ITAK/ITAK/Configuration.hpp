//
// Created by manab on 4/17/2017.
//

#ifndef ITAK_CONFIGURATION_HPP
#define ITAK_CONFIGURATION_HPP


#include <map>
#include <string>
#include "Dictionary.hpp"


class Configuration : public Dictionary<std::string,std::string>{
public:
    std::string getValueAsString(std::string key);
    int getValueAsInt(std::string key);
    double getValueAsDouble(std::string key);

    const static std::string port_count;
    const static std::string likely_attackers;
    const static std::string possible_attackers;
    const static std::string attack_periods;
    const static std::string timeFrame;

};


#endif //ITAK_CONFIGURATION_HPP
