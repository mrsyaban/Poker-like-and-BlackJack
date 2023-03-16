#include "Player.hpp"
#include "../Ability/Ability.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

/* default constructor*/
Player::Player(string nick) : nickName(nick) {
    Point p(0);
    this->handPoint = p; // set point to zero
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

bool operator==(const Player& p1, const Player& p2){
    if (p1.getNickname() == p2.getNickname()){
        return true;
    } else {
        return false;
    }
}

/* Accessor */

Point Player::getPoint() const{
    return handPoint;
}

Combo Player::getHighestCombo() const{
    return highestCombo;
}

void Player::getInfo() const {
    cout << "This is "<< nickName << "'s Card" << endl;
}

string Player::getNickname() const {
    return this->nickName;
}

Ability* Player::getAbility() const {
    return handAbility;
}

Card Player::getCard(int i) const{
    return this->items[i];
}

/* Setter */
void Player::setHighestCombo(Combo c){
    this->highestCombo = c;
}

void Player::setAbility(Ability& ability){
    handAbility = &ability;
}

void Player::setAbilityAvailability(bool status) {
    handAbility->setAvail(status);
}

void Player::dealToPlayer(InventoryHolder<Card>& deck) {
    this->deleteall();
    this->add(deck);
    this->add(deck);
}

/* Utility Function*/
void Player::addPoint(long long point){
    this->handPoint.Add(point);
}