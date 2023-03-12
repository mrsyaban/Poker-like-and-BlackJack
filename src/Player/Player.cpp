#include <ctime>
#include "Player.hpp"

/* default constructor*/
// Player::Player(){
//     this->handPoint = 0; // set point to zero
// }

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

InventoryHolder<Card>& Player::operator+(const Card & card) {
    this->items.push_back(card);
    return *this;
}

InventoryHolder<Card>& operator-(const Card & card){
    // this->items.push_back(card) ;
    // return *this;
}

// InventoryHolder<Card>& operator=(InventoryHolder<Card> &);

/* Accessor */
Card Player::getCard(int i) const{
    return items[i];
}

int Player::getPoint() const{
    return handPoint;
}

Combo Player::getHighestCombo() const{
    return highestCombo;
}

/* Setter */
void Player::setHighestCombo(Combo c){
    this->highestCombo = c;
}

/* Utility Function*/
void Player::addPoint(int point){
    this->handPoint += point;
}