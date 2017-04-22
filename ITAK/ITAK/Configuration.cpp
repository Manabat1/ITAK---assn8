//
// Created by manab on 4/17/2017.
//

#include "Configuration.hpp"

int Configuration::getValueAsInt(std::string key) {
    std::string value = getValue(key);
    return std::stoi(value);
}

std::string Configuration::getValueAsString(std::string key) {
    return getValue(key);
}

double Configuration::getValueAsDouble(std::string key) {
    std::string value = getValue(key);
    return std::stod(value);
}

const std::string Configuration::port_count = "Port Count";
const std::string Configuration::likely_attackers = ("Likely Attackers");
const std::string Configuration::possible_attackers = ("Possible Attackers");
const std::string Configuration::attack_periods = ("Attack Periods");
const std::string Configuration::timeFrame = ("Time Frame");