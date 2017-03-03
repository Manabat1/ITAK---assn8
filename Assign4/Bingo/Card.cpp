//
// Created by manab on 2/22/2017.
//

#include <cstdlib>
#include <time.h>
#include <array>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Card.hpp"

Card::Card(int cardSize, int maxNumber,int cardID)
{
    m_cardSize= (cardSize);
    m_maxNumber=(maxNumber);
    m_cardId=(cardID);
    m_totalNumbers=(cardSize*cardSize);
    generateRandomNumbers();
}

void Card::generateRandomNumbers() {
    //Generates all the possible numbers

    int* theNums;
    theNums = new int[m_maxNumber];
    for(int i = 1; i <= m_maxNumber; i++){
        theNums[i-1] = i;
    }
    //Random shuffle

//    std::cout << "Initial Array\n";
//    for(int i = 0; i < m_maxNumber;i++){
//        std::cout << theNums[i] << ", " << std::endl;
//    }

    for(int i = 0; i < m_maxNumber; i++){
        int ran = randomIndex();
//        std::cout << "Swapping index " << i << " and " << ran  <<"\n";
        std::swap(theNums[i],theNums[ran]);
    }
//    std::cout << "Random Array\n";
//    for(int i = 0; i < m_maxNumber;i++){
//        std::cout << theNums[i] << ", "<< std::endl;
//    }
//    std::cout << "\n";
    //std::random_shuffle(theNums[0],theNums[m_totalNumbers-1]);

    m_numbers = new int[m_totalNumbers];
    for(int i = 0; i < m_totalNumbers; i++){
        m_numbers[i] = theNums[i];
    }

    delete [] theNums;
}
int Card::randomIndex() const{

    return (rand() % m_totalNumbers);
}
void Card::print(std::ostream& out) const{
    out << "Card #" << m_cardId << "\n";
    int index = 0;
    for(int j = 0; j < m_cardSize; j++){
        for(int i = 0; i < m_cardSize;i++){
            out << "|" << std::setw(3) << m_numbers[index] << "| ";
            index ++;
        }
        out << "\n";
    }
    out << "\n";
}
Card::~Card() {
    delete [] m_numbers;
}

