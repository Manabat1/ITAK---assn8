//
// Created by Stephen Clyde on 2/20/17.
//

#include <iostream>
#include <ctime>

#include "MenuOptionTester.h"
#include "MenuTester.h"
#include "DeckTester.hpp"
#include "CardTester.hpp"

int main()
{

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // TODO: Test your components

    MenuOptionTester menuOptionTester;
    menuOptionTester.testConstructorAndGetter();

    MenuTester menuTester;
    menuTester.testConstructorAndGetter();

    DeckTester deckTester;
    deckTester.testDeckPrint();
    deckTester.testDeckConstruct();

    CardTester cardTester;
    cardTester.testCardPrint();
    cardTester.testCardConstruct();
}