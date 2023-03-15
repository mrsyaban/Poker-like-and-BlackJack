/*
    Card class header
*/

#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "../ObjectWithValue/ObjectWithValue.hpp"
#include <utility>
#include <string>
#include <map>
using namespace std;

enum CardColor {
/* Card Color */
    Green = 0,
    Blue = 1,
    Yellow = 2,
    Red = 3
};

const map<CardColor, string> cardToString = {
/* Mapping color to int for */
    {Green, "Green"},
    {Blue, "Blue"},
    {Yellow, "Yellow"},
    {Red, "Red"}
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
        friend bool operator==(const Card&, const Card&);
        friend bool operator>(const Card&, const Card&);
        friend bool operator<(const Card&, const Card&);

        /* Accessor */
        CardColor getColor() const;
        int getNumber() const;
        double value() const; // inherited from ObjectWithValue<double>

        /* Setter */
        void setNumber(int);
        void setColor(CardColor);
};

#endif