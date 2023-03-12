#include <ctime>
#include "Player.hpp"

/* default constructor*/
Player::Player(){
    this->handPoint = 0; // set point to zero
}

/* Operator Overloading */
bool operator<(const Player& p1,const Player& p2){
    if (p1.highestCombo.value() < p2.highestCombo.value()){
        return true;
    } else {
        return false;
    }
}

bool operator>(const Player& p1, const Player& p2) {
    if (p1.highestCombo.value() > p2.highestCombo.value()){
        return true;
    } else {
        return false;
    }
}

InventoryHolder& Player::operator+(const Card & card) {
    this->cards.push_back(card);
    return *this;
}

InventoryHolder& operator-(const Card & card){
    this->cards.push_back(card) ;
    return *this;
}

InventoryHolder& operator=(InventoryHolder &);

/* Accessor */
Card Player::getCard(int i) const{
    return cards[i];
}

int Player::getPoint() const{
    return handPoint;
}

Combo Player::getHighestCombo() const{
    return highestCombo;
}

/* Setter */
void Player::setHighestCombo(float highestCombo){
    this->highestCombo = highestCombo;
}

/* Utility Function*/
void Player::addPoint(int point){
    this->handPoint += point;
}