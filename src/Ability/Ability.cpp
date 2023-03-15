#include <iostream>
#include <vector>
#include "Ability.hpp"
#include "../Game/Game.hpp"
#include "../Exception/exception.h"

using namespace std;

/* Ability Abstract class */
Ability::Ability(string type)
{
    available = true;
    this->type = type;
}

/* Getter */
bool Ability::getAvail() const
{
    return this->available;
}

/* Setter */
void Ability::setAvail(bool avail)
{
    this->available = avail;
}

/* Re-roll Ability */
ReRoll::ReRoll() : Ability("Reroll") {}

void ReRoll::Execute(Game& g) {
    Player * owner = &((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    owner->deleteall();
    owner->add(g.getCardDeck());
    owner->add(g.getCardDeck());

    IO io;
    io.printAbilitySuccess(*owner);
}

/* Quadruple Ability */
Quadruple::Quadruple() : Ability("Quadruple") {}

void Quadruple::Execute(Game &g){
    g.getPoint().Quadruple();
    
    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printAbilitySuccess(owner, g.getPoint());
}

/* Quarter Ability */
Quarter::Quarter() : Ability("Quarter") {}

void Quarter::Execute(Game &g){
    g.getPoint().Quarter();
    
    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printAbilitySuccess(owner, g.getPoint());
}

/* Reverse Direction Ability */
ReverseDirection::ReverseDirection() : Ability("Reverse") {}

void ReverseDirection::Execute(Game &g)
{
    g.setReverseInfo(true);

    IO io;
    Player& owner = (g.getPlayers().begin() + g.getCurrentPlayer())->first;
    io.printAbilitySuccess(owner, g.getRemainingReversedPlayer(), g.getReversedPlayer());
}

/* Swap Card Ability */
SwapCard::SwapCard(): Ability("Swap") {}

void SwapCard::Execute(Game& g) {
    IO io;
    Player& owner = (g.getPlayers().begin() + g.getCurrentPlayer())->first;

    // select Player
    vector<Player>& listPlayer = io.selectPlayer(owner, g.getPlayers());
    Player& player1 = listPlayer[0];
    Player& player2 = listPlayer[1];

    // select Card
    int cardPlayer1 = io.selectCard(player1.getNickname());
    int cardPlayer2 = io.selectCard(player2.getNickname());

    // swap
    if (cardPlayer1 == 1) {
        player1.puttoback();
    }
    if (cardPlayer2 == 1) {
        player2.puttoback();
    }
    player1.exchange(player2);
    
    // print successfull message
    vector<string> output = {player1.getNickname(), player2.getNickname()};
    io.printAbilitySuccess(owner, output);
}

/* Switch Card Ability */
Switch::Switch(): Ability("Switch") {}

void Switch::Execute(Game& g) {
    IO io;
    Player& owner = (g.getPlayers().begin() + g.getCurrentPlayer())->first;
    
    vector<Player>& target = io.selectPlayer(owner, g.getPlayers());
    Player& other = target[0];

    owner.exchange(other);
    owner.exchange(other);

    vector<string> output = {target[0].getNickname()};
    io.printAbilitySuccess(owner, output);
}

/* Abilityless Ability */
Abilityless::Abilityless(): Ability("Abilityless") {}

void Abilityless::Execute(Game& g) {
    Player playerChosen = selectPlayer(g);
    bool allAvail = true;
    int n = g.getPlayers().size(), i = 0;

    while (allAvail && i < n) {
        if (g.getPlayers()[i].first.getAbility()->getAvail() == true && g.getPlayers()[i] != g.getPlayers()[g.getCurrentPlayer()]) {
            i++;
        } else {
            allAvail = false;
        }
    }

    if (allAvail == true) {
        if (playerChosen.getAbility()->getAvail() == true) {
            playerChosen.getAbility()->setAvail(false);
            cout << "Kartu ability " << playerChosen.getNickname() << " telah dimatikan" << endl;
        } else if (playerChosen.getAbility()->getAvail() == true) {
            cout << "Kartu ability " << playerChosen.getNickname() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia" << endl;
        }
    } else {
        g.getPlayers()[g.getCurrentPlayer()].first.getAbility()->setAvail(false);
        cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu" 
             << "\nkena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan"
             << "\nkartu ini sia-sia" << endl;
    }
}