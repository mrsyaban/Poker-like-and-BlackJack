/*
    Card class header
*/

#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "../ObjectWithValue/ObjectWithValue.hpp"

class Card : public ObjectWithValue<double> {
    private:
        CardColor color;
        int number;
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

enum CardColor {
/*
    *Order matters*
    Green: 0,
    Blue: 1,
    Yellow: 2,
    Red: 3

    since Red > Yellow > Blue > Green
*/
    Green,
    Blue,
    Yellow,
    Red
};

#endif