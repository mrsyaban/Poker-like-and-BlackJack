/*
    Card class implementation
*/

#include "Card.hpp"

//ctor
Card::Card(CardColor color, int num){
    this->cardInfo.first = color;
    this->cardInfo.second = num;
}

//cctor
Card::Card(const Card& other){
    this->cardInfo.first = other.cardInfo.first;
    this->cardInfo.second = other.cardInfo.second;
} 

//destructor
Card::~Card(){}

//assignment op.
Card& Card::operator=(const Card& other){
    if (this != &other) {
        this->cardInfo.first = other.cardInfo.first;
        this->cardInfo.second = other.cardInfo.second;
    }
    return *this;
}

/* Operator Overload */
bool operator==(const Card& a, const Card& b){
    return a.cardInfo.second == b.cardInfo.second && a.cardInfo.first == b.cardInfo.first;
}

bool operator>(const Card& a, const Card& b){
    return a.value() > b.value();
}

bool operator<(const Card& a, const Card& b){
    return a.value() < b.value();
}

/* Accessor */
CardColor Card::getColor() const{
    return this->cardInfo.first;
}

int Card::getNumber() const{
    return this->cardInfo.second;
}

// inherited from ObjectWithValue<dpuble>
double Card::value() const{
    //color will be implicitly casted to int from enum (check the enum CardColor definition in Card.hpp)
    return cardInfo.second * 0.1 + cardInfo.first * 0.03;
} 

/* Setter */
void Card::setNumber(int val){
    this->cardInfo.second = val;
}

void Card::setColor(CardColor clr){
    this->cardInfo.first = clr;
}