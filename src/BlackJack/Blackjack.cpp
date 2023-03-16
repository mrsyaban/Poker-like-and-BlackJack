#include "BlackJack.hpp"
#include <iostream>
using namespace std;

BlackjackPlayer::BlackjackPlayer(string nick): Player(nick) {
    // nothing
}

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
    Point poin(0);
    this->pricePool = poin;
    BlackjackPlayer player("");
    this->bjPlayer.push_back(player);
}

void BlackjackPlayer::hit(InventoryHolder& deck) {
    this->add(deck);
}

void Blackjack::hit() {
    this->dealer.add(this->deck);
}

void Blackjack::start(){
    IO io;
    Deck<Card> deck;
    Table dealer;
    bool stand = false;

    this->dealer = dealer;
    this->deck = deck;
    
    hit();
    hit();
    this->dealer.openCard();

    auto player = this->bjPlayer.begin();
    player->hit(this->deck);
    player->hit(this->deck);

    // minta input hit atau stand
    io.printBJ(this->dealer, this->pricePool);

    while(player->getTotalCard() < 21 && !stand){
        string command;
        // hit
        if (command == "1"){
            hit();
        } else {
            stand = true;
            // buat while dealer sampe bust/melebihi kartu player
        }
    }
    
}
