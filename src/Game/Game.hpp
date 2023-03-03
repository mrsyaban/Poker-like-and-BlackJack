#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Game {
    private:
        map<Player, int> players; // idenya player bisa diakses lewat map, int adalah urutan player
        bool gameStart;
        
    public:
        Game();
        ~Game();
};

#endif