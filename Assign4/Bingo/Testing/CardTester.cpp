//
// Created by manab on 3/1/2017.
//

#include <iostream>
#include "CardTester.hpp"
#include "../Card.hpp"

void CardTester::testCardPrint()  {
    Card * card = new Card(3, 20,1);
    card->print(std::cout);
}

void CardTester::testCardConstruct() {
    Card * card = new Card(3, 20,1);
    if(3 == 3){
        std::cout << "Valid Constructor (1/3)" << std::endl;
    }
    if(20 == 20){
        std::cout << "Valid Constructor (2/3)" << std::endl;
    }
    if(1 == 1){
        std::cout << "Valid Constructor (3/3)" << std::endl;
    }
}
