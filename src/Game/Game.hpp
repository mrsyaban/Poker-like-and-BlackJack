#ifndef GAME_HPP
#define GAME_HPP

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Deck/Deck.hpp"
#include "../Point/Point.hpp"
#include "../Ability/Ability.hpp"
#include "../Table/Table.hpp"
#include "../IO/IO.hpp"

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Game {
    private:
        vector<pair<Player&, bool>> players; // idenya player bisa diakses lewat map, int adalah urutan player
        Deck<Card> cardDeck;
        Deck<Ability> abilityDeck;
        Table table;
        Point point;
        bool isReversed;
        int playerTurn;
        int round;
        Player& currentPlayer;

    public:
        Game(); // init all needed objects;
        ~Game();
        // initNewMatch()

        /* Accessor, may only be called by class that act directly in the game */
        /* The returned reference may be altered */
        vector<pair<Player&, bool>>& getPlayers(){
            return this->players;
        }

        Deck<Card> getCardDeck(){
            return this->cardDeck;
        }

        Deck<Ability> getAbilityDeck(){
            return this->abilityDeck;
        }

        Table getTable(){
            return this->table;
        }

        Point& getPoint(){
            return this->point;
        }

        bool& getReverseInfo(){
            return this->isReversed;
        }

        int& getPlayerTurn(){
            return this->playerTurn;
        }

        int& getRound(){
            return this->round;
        }

        Player& getCurrentPlayer(){
            return this->currentPlayer;
        }

        /* Setter */
        void addPlayer();
        
        void initNewMatch(){
            // reset deckCard, point, table, isReversed, playerTurn, round
            // balikin semua kartu player ke deck  
        }

        void start();
            // cout << "Game started" << endl;
            // cout << "Init point : " << point.getValue() << endl;
            // Quadruple ability;
            // ability.Execute(*this);
            // cout << "New point : " << point.getValue() << endl;

            // while (!gameEnd){
            //     udah 6 ronde
            //     initNewMatch();
            // }

        /* SETTER */
        void dealToTable();
        void dealToPlayers();
};

#endif