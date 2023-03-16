#include "BlackJack.hpp"
#include <iostream>
using namespace std;

Point BlackjackPlayer::getPoint(){
    return this->handPoint;
}

int BlackjackPlayer::getTotalCard(){
    int max = 0;
    for (auto playerCard: this->getItems()){
        max += getBJValue.at(cardToBJCard.at(playerCard.getNumber()));
    }
    
    return max;
}

Blackjack::Blackjack() {
    this->dealer = Table();
    Point poin(0);
    this->pricePool = poin;
}

void BlackjackPlayer::hit(InventoryHolder& deck) {
    this->add(deck);
}

void Blackjack::hit() {
    this->dealer.add(this->deck);
}

void Blackjack::start(){
    Deck<Card> deck;
    this->deck = deck;
    
    hit();
    hit();
    this->dealer.openCard();

    this->bjPlayer.hit(this->deck);
    this->bjPlayer.hit(this->deck);

    // minta input hit atau stand

    while(bjPlayer.getTotalCard() < 21){
        string command;
        // hit
        if (command == "1"){
            hit();
        } else {
            // buat while dealer sampe bust/melebihi kartu player
        }
    }
    
}
