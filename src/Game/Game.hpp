#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Game {
    private:
        // map<Player&, bool> players; // idenya player bisa diakses lewat map, int adalah urutan player
        // Deck<Card> deckCard;
        // Deck<Ability> abilityDeck;
        // Table table;
        // Point point;
        // bool isReversed;
        // int playerTurn;
        // int round;
        // currentPlayer& player;

    public:
        Game(); // initNewMatch()
        ~Game();
        
        // void initNewMatch(){
            // reset deckCard, point, table, isReversed, playerTurn, round
            // balikin semua kartu player ke deck  
        // }

        // void start(){
            // while (!gameEnd){
                // udah 6 ronde
                // initNewMatch();
            //}
        // }
        
};

#endif