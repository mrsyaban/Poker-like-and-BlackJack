#include <ctime>
#include "Player.hpp"

/* default constructor*/
Player::Player(){
    this->handCard = new Card*[2]; // allocate memory of two cards
    this->handPoint = 0; // set point to zero
    this->highestCombo = 0; // set highest combo to zero
}

/* Accessor */
Card* Player::getCard(){
    return this->handCard;
}

Ability Player::getAbility();
int getPoint();


/* Setter */
void Player::setRandomCard(){
    for (int i=1; i<=2; i++){
        srand(time(0));
        int randCard = rand() % InventoryHolder::cardList.size();
        this->handCard[i] = InventoryHolder::cardList[randCard];  
        InventoryHolder::removeCard(randCard);
    }
}

void Player::setRandomAbility(){

}

void Player::setHighestCombo(float highestCombo){
    this->highestCombo = highestCombo;
}


/* Utility Function*/
void Player::addPoint(int point){
    this->handPoint += point;
}