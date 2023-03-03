#include <iostream>
#include "Game.hpp"
using namespace std;

Game::Game() {
    this->gameStart = true;
    // ctor player
    for (int i = 1; i <= 7; i++) {
        this->players.insert(pair<Player, int>(new Player(), i));
    }
}

Game::~Game(){

}