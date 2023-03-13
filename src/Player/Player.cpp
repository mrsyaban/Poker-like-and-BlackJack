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

/* Accessor */
Card Player::getCard(string position) const{
    if (position == "kiri"){
        return items[0];
    } else if (position == "kanan") {
        return items[1];
    } else {
        throw ;
    }
}

int Player::getPoint() const{
    return handPoint;
}

Combo Player::getHighestCombo() const{
    return highestCombo;
}

void Player::getInfo() const {
    cout << "This is "<< nickName << "'s Card" << endl;
}

/* Setter */
void Player::setHighestCombo(Combo c){
    this->highestCombo = c;
}

/* Utility Function*/
void Player::addPoint(int point){
    this->handPoint += point;
}