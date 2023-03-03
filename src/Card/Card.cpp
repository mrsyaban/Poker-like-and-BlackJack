/*
    Card class implementation
*/

#include "Card.hpp"

//ctor
Card::Card(CardColor color, int num){
    this->color = color;
    this->number = num;
}

//cctor
Card::Card(const Card& other){
    this->color = other.color;
    this->number = other.number;
} 

//destructor
Card::~Card(){}

//assignment op.
Card& Card::operator=(const Card& other){
    if (this != &other) {
        this->color = other.color;
        this->number = other.number;
    }
    return *this;
}

/* Operator Overload */
bool operator==(Card& a, Card& b){
    return a.number == b.number && a.color == b.color;
}

bool operator>(Card& a, Card& b){
    return a.value() > b.value();
}

bool operator<(Card& a, Card& b){
    return a.value() < b.value();
}

/* Accessor */
CardColor Card::getColor(){
    return this->color;
}

int Card::getNumber(){
    return this->number;
}

// inherited from ObjectWithValue<dpuble>
double Card::value(){
    //color will be implicitly casted to int from enum (check the enum CardColor definition in Card.hpp)
    return number * 0.1 + color * 0.03;
} 

/* Setter */
void Card::setNumber(int val){
    this->number = val;
}

void Card::setColor(CardColor clr){
    this->color = clr;
}