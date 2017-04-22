//
// Created by manab on 4/12/2017.
//

#ifndef ITAK_RESULTSET_HPP
#define ITAK_RESULTSET_HPP


#include <map>
#include <vector>
#include <ostream>
#include "Dictionary.hpp"


class ResultSet : public Dictionary<std::string, std::vector<std::string>*> {

public:
    virtual void print(std::ostream& out);
};


#endif //ITAK_RESULTSET_HPP
