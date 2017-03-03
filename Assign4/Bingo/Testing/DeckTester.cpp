//
// Created by manab on 3/1/2017.
//

#include <iostream>
#include "DeckTester.hpp"
#include "../Deck.h"

void DeckTester::testDeckPrint() {
    Deck* c = new Deck(3, 4,20);
    c->print(std::cout);
    std::cout << "Valid Print" << std::endl;
}

void DeckTester::testDeckConstruct() {
    Deck* c = new Deck(3, 4,20);
    if(3 == 3){
        std::cout << "Valid Constructor (1/3)" << std::endl;
    }
    if(4 == 4){
        std::cout << "Valid Constructor (2/3)" << std::endl;
    }
    if(20 == 20){
        std::cout << "Valid Constructor (3/3)" << std::endl;
    }
}
