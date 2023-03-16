#include "BlackJack.hpp"
#include <iostream>
using namespace std;

BlackjackPlayer::BlackjackPlayer(string nick): Player(nick) {
    // nothing
    this->handPoint.setValue(100);
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

vector<Card>& BlackjackPlayer::getCards(){
    return this->getItems();
}

void BlackjackPlayer::addPoint(int win){
    int cur = getPoint().getValue();    
    this->handPoint.setValue(cur+win);
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

int Blackjack::getTotalCard() {
    int max = 0;
    for (unsigned int i = 0; i < this->dealer.getItems().size(); i++){
        max += getBJValue.at(cardToBJCard.at((this->dealer.getCard(i)).getNumber()));
    }
    
    return max;
}

void Blackjack::setPrice(int bet){
    this->pricePool.setValue(bet*2);
}


void Blackjack::start(){
    IO io;
    bool end = false;

    while (!end) {
        Deck<Card> deck;
        Table dealer;
        int bet = 0;
        bool stand = false;

        this->dealer = dealer;
        this->deck = deck;
        
        while (bet == 0) {
            try {
                bet = io.inputBet(this->bjPlayer[0].getPoint().getValue());
            } catch (BaseException& e) {
                cout << e.what() << endl;
            }
        }
        this->setPrice(bet);

        hit();
        hit();
        this->dealer.openCard();

        BlackjackPlayer& player = this->bjPlayer[0];
        player.hit(this->deck);
        player.hit(this->deck);

        // minta input hit atau stand
        io.printBJ(this->dealer, this->pricePool);

        while(player.getTotalCard() < 21 && !stand){
            string command = "";
            while (command == "") {
                try {
                    command = io.inputBJ(player.getCards(), player.getTotalCard());
                } catch (BaseException& e) {
                    cout << e.what() << endl;
                }
            }

            if (command == "HIT"){
                player.hit(this->deck);
                io.printBJ(this->dealer, this->pricePool);
            } else {
                stand = true;
            }
        }

        if (player.getTotalCard() > 21) {
            io.printBust();
        } else if (player.getTotalCard() == 21) {
            io.printStrike();
        } else {
            while(getTotalCard() < player.getTotalCard() && getTotalCard() <= 21) {
                hit();
                this->dealer.openCard();
                io.printBJ(this->dealer, this->pricePool);
            }

            io.printEndBJ(player.getTotalCard(), getTotalCard());

            if (getTotalCard() < player.getTotalCard()) {
                player.addPoint(this->pricePool.getValue());
            } else if (getTotalCard() == player.getTotalCard()) {
                player.addPoint(this->pricePool.getValue()/2);
            }
        }
    }


}
