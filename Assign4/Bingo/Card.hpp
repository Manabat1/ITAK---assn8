//
// Created by manab on 2/22/2017.
//

#ifndef BINGO_CARD_HPP
#define BINGO_CARD_HPP


#include <vector>
#include "Testing/CardTester.hpp"

class Card {
public:
    Card(int cardSize, int maxNumber,int cardId);
    ~Card();
    void print(std::ostream& out)const;
private:
    int randomIndex()const;
    void generateRandomNumbers() ;
    int* m_numbers;
    //std::vector<int> v_numbers;
    int m_totalNumbers;
    int m_maxNumber;
    int m_cardSize;
    int m_cardId;
};


#endif //BINGO_CARD_HPP
