#include <iostream>
#include "Ability.hpp"
#include "../Game/Game.hpp"
#include "../Exception/exception.h"

using namespace std;

Ability::Ability(string type)
{
    available = true;
    this->type = type;
}

Player& Ability::selectPlayer(Game& g) {
    cout << "Silahkan pilih player (sementara): " << endl;
    int i = 1;
    for (auto p_itr = g.getPlayers().begin(); p_itr != g.getPlayers().end(); p_itr++) {
        cout << i << ". " << p_itr->first.getNickname() << endl;
        i++;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > g.getPlayers().size()) {
        // throw new InvalidInputException();
    } else {
        auto p_itr = g.getPlayers().begin();
        for (int i = 1; i < choice; i++) {
            p_itr++;
        }
        return p_itr->first;
    }
}

ReRoll::ReRoll() : Ability("Reroll") {
    
}

void ReRoll::Execute(Game& g) {
    Player temp = selectPlayer(g);
    temp.deleteall();
    temp.add(g.getCardDeck());
}

Quadruple::Quadruple() : Ability("Quadruple") {}

void Quadruple::Execute(Game &g)
{
    g.getPoint().Quadruple();
}

Quarter::Quarter() : Ability("Quarter") {}

void Quarter::Execute(Game &g)
{
    g.getPoint().Quarter();
}

ReverseDirection::ReverseDirection() : Ability("Reverse") {}

void ReverseDirection::Execute(Game &g)
{
}

SwapCard::SwapCard(): Ability("Swap") {
    
}

void SwapCard::Execute(Game& g) {
    Player temp1 = selectPlayer(g);
    Player temp2 = selectPlayer(g);

    string kartuPertama;
    string kartuKedua;

    cout << "Silahkan masukkan kartu untuk player pertama: (kiri atau kanan)" << endl;
    cin >> kartuPertama;
    cout << "Silahkan masukkan kartu untuk player kedua: (kiri atau kanan)" << endl;
    cin >> kartuKedua;

    if (kartuPertama == "kanan") {
        temp1.puttoback();
    }

    if (kartuKedua == "kanan") {
        temp2.puttoback();
    }

    temp1.exchange(temp2);
}

// Switch::Switch(): Ability("Switch") {
    
// }

void Switch::Execute(Game& g) {
    Player temp1 = selectPlayer(g);
    Player temp2 = selectPlayer(g);

    temp1.exchange(temp2);
    temp1.exchange(temp2);
}

// Abilityless::Abilityless(): Ability("Abilityless") {

// }

// Abilityless::~Abilityless() {
//     Ability::~Ability();
// }

// void Abilityless::Execute() {

// }