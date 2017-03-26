//
// Created by Stephen Clyde on 3/4/17.
//

#include <iostream>
#include "Nation.h"

Nation::Nation(const std::string data[]) : Region(NationType, data)
{

    validate();
    //std::cout << "ID: " << getId() << std::endl;
}
