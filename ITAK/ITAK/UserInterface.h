//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef GEO_REGIONS_USER_INTERFACE_H
#define GEO_REGIONS_USER_INTERFACE_H

#include "Analyzer.hpp"
#include "Menu.h"
#include <string>



class UserInterface {
private:
    Analyzer*   m_analyzer = nullptr;
    Menu*     m_menu = nullptr;
    std::string filename = "";
public:
    ~UserInterface();
    void run();

private:
    void setupMenu();
    void cleanup();
    void add();
    void list();
    void print();
};


#endif //GEO_REGIONS_USER_INTERFACE_H
