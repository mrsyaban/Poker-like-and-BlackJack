/*
    Card class header
*/

#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "../ObjectWithValue/ObjectWithValue.hpp"
#include <utility>
using namespace std;

enum CardColor {
/*
    Green: 0,
    Blue: 1,
    Yellow: 2,
    Red: 3

    since Red > Yellow > Blue > Green
*/
    Green = 0,
    Blue = 1,
    Yellow = 2,
    Red = 3
};

class Card : public ObjectWithValue<double> {
    private:
        pair<CardColor, int> cardInfo;
        // TO BE ASKED : map for mapping card color to int, instead of implicit def. from enum (?)
    public:
        Card(CardColor, int); 
        Card(const Card&); //cctor
        ~Card(); //destructor
        Card& operator=(const Card&); //assignment op.
        
        /* Operator Overload */
        friend bool operator==(Card&, Card&);
        friend bool operator>(Card&, Card&);
        friend bool operator<(Card&, Card&);

        /* Accessor */
        CardColor getColor();
        int getNumber();
        double value(); // inherited from ObjectWithValue<double>

        /* Setter */
        void setNumber(int);
        void setColor(CardColor);
};

#endif