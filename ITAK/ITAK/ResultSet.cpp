//
// Created by manab on 4/12/2017.
//

#include "ResultSet.hpp"

void ResultSet::print(std::ostream &out) {
    for(KeyValue<std::string, std::vector<std::string>*>* keyValue : m_keyValues) {
        out << keyValue->getKey() << ": " << std::endl;;
        for (std::string printString : *keyValue->getValue()) {
            out << " -" << printString << "-" << std::endl;
        }
    }
    out << std::endl;
}
