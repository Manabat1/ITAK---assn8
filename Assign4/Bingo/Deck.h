//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <vector>
#include "Card.hpp"

// TODO: Extend this definition as you see fit

class Deck {

public:
    Deck(int cardSize, int cardCount, int numberMax);
    void print(std::ostream& out) const;
    void print(std::ostream& out, int cardIndex) const;

private:
    int m_cardCount;
    std::vector<Card*> m_deck;
};

#endif //BINGO_DECK_H
