#include <iostream>
#include "Game.hpp"
using namespace std;

Game::Game() : currentPlayer(players.begin()->first) {
    // this->gameStart = true;
    // // ctor player
    // for (int i = 1; i <= 7; i++) {
    //     this->players.insert(pair<Player, int>(new Player(), i));
    // }
    // Point p(64);
    // point = p;
}

Game::~Game(){

}

void Game::addPlayer(){
    string nick = IO::retrieveInput();
    Player player(nick);
    pair<Player&, bool> element(player, false);
    players.push_back(element);
}

void Game::dealToTable() {
    this->table.dealToTable(this->cardDeck);
}

void Game::dealToPlayers() {
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
        p_itr->first.dealToPlayer(this->cardDeck);
    }
}

void Game::dealAbilityToPlayers() {
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
        p_itr->first.dealAbilityToPlayer(this->abilityDeck);
    }
}

bool Game::gameEnded() {
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
        if (p_itr->first.getPoint() >= 4294967296) {
            return true;
        }
    }

    return false;
}

void Game::start() {
    while (!gameEnded()) {
        Deck<Card> deck;
        Deck<Ability> deckAbility;
        this->cardDeck = deck;
        this->abilityDeck = deckAbility;
        dealToTable();
        dealToPlayers();
        // cards already given to the table and players
        do {
            // BAGIAN I/O
            nextRound();
            this->table.openCard();
            if (this->getRound() == 2) {
                dealAbilityToPlayers();
            }
        } while (this->getRound() <= 6);

        // compare score

        // add points to the winner
    }
}