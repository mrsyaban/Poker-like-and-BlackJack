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

void Game::start() {
    while (!end) {
        Deck<Card> deck;
        this->cardDeck = deck;
        dealToTable();
        dealToPlayers();
        // cards already given to the table and players
        do {
            // BAGIAN I/O
            nextRound();
        } while (this->getRound() <= 6);

        // compare score

        // add points to the winner
    }
}