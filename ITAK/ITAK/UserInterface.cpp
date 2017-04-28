//
// Created by Stephen Clyde on 2/16/17.
//

#include "UserInterface.h"
#include "Menu.h"
#include "Utils.hpp"
#include "SourcePortAnalyzer.hpp"
#include "PortScanAnalyzer.hpp"
#include "DenialOfServiceAnalyzer.hpp"

#include <iostream>



UserInterface::~UserInterface()
{
    cleanup();
}

void UserInterface::setupMenu()
{
    if (m_menu != nullptr)
    {
        delete m_menu;
        m_menu = nullptr;
    }
    if(m_analyzer != nullptr) {
        m_menu = new Menu(m_analyzer->getName());
    } else {
        m_menu = new Menu("No analyzer");
    }
    m_menu->addOption("F", "Input a filename");
    m_menu->addOption("S", "Create a Source Port Analyzer");
    m_menu->addOption("A", "Create a Port Scan Analyzer");
    m_menu->addOption("D", "Create a Denial of Service Analyzer");
    if(m_analyzer != nullptr) {
        m_menu->addOption("P", "Print and run a report of " + m_analyzer->getName());
    }

}



void UserInterface::cleanup()
{


}

void UserInterface::run()
{


    if(m_analyzer != nullptr) {
        std::cout << "Current Analyzer: " << m_analyzer->getName() << std::endl;
    }

    bool keepGoing = true;
    while (keepGoing)
    {
        setupMenu();
        std::string command = m_menu->show();
        if (command=="P")
        {
            print();
        }
        else if (command=="X")
        {
            keepGoing = false;
        }
        else if (command=="F")
        {
            std::cout << "File name: ";
            std::cin >> filename;
            std::cout << std::endl;
        }
        else if (command=="S")
        {
            Configuration* config2 = new Configuration();
            config2->add(config2->possible_attackers, "2");
            config2->add(config2->likely_attackers, "10");

            m_analyzer = new SourcePortAnalyzer(config2);

        }
        else if (command=="A")
        {
            Configuration* config2 = new Configuration();
            config2->add(config2->possible_attackers, "4");
            config2->add(config2->likely_attackers, "10");

            m_analyzer = new PortScanAnalyzer (config2);

        }
        else if (command=="D")
        {
            Configuration* config = new Configuration();
            config->add(config->possible_attackers, "10");
            config->add(config->likely_attackers, "15");
            config->add(config->timeFrame, "10");
            m_analyzer = new DenialOfServiceAnalyzer (config);

        }
    }
}


void UserInterface::print()
{
    if(m_analyzer != nullptr && filename != ""){
        std::ifstream fin;
        fin.open(filename);

        try {
            m_analyzer->run(fin);
            fin.close();
            m_analyzer->print(std::cout);
        } catch (std::string e){
            std::cout << e << std::endl;
        }

    } else {
          std::cout << "No analyzer created or improper file " << std::endl;
    };
}



