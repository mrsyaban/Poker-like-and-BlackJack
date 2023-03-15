#ifndef GAME_HPP
#define GAME_HPP

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Deck/Deck.hpp"
#include "../Point/Point.hpp"
// #include "../Ability/Ability.hpp"
// #include "../Table/Table.hpp"
// #include "../IO/IO.hpp"
#include "../Combo/SearchCombo.hpp"

#include <iostream>
#include <map>
#include <string>
using namespace std;

class IO;
class Ability;
class Table;

/* Mapping command to int */
const map<string, int> inputToCommand = {
        {"NEXT", 1},
        {"HALF", 2},
        {"DOUBLE", 3},
        {"RE-ROLL", 4},
        {"QUADRUPLE", 5},
        {"QUARTER", 6},
        {"REVERSE", 7},
        {"SWAP CARD", 8},
        {"SWITCH", 9},
        {"ABILITYLESS", 10}
};

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
        int currentPlayer;

    public:
        Game(); // init all needed objects, init status player false;
        ~Game();
        // initNewMatch()

        /* Accessor, may only be called by class that act directly in the game */
        /* The returned reference may be altered */
        vector<pair<Player&, bool>>& getPlayers(){
            return this->players;
        }

        Deck<Card>& getCardDeck(){
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

        int getCurrentPlayer(){
            return this->currentPlayer;
        }

        /* Setter */
        void addPlayer();
        void incCurrentPlayer() {
            currentPlayer++;
            currentPlayer %= 7;
        }

        void decCurrentPlayer() {
            currentPlayer--;
            currentPlayer %= 7;
        }
        
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
        
        void nextPlayer() {
            if (isReversed) {
                decCurrentPlayer();
            } else {
                incCurrentPlayer();
            }
        }
        
        void nextTurn() {

            nextPlayer();

            if (playerTurn != 7) {
                // status player yang udah jalan adalah true  (1) untuk ronde ganjil (mod 2 == 1)
                // status player yang udah jalan adalah false (0) untuk ronde genap  (mod 2 == 0)
                while (players[currentPlayer].second % 2 == round % 2) {
                    nextPlayer();
                }

                // TODO
                // currentPlayer jalan, manggil command (??)

                // setelah playernya jalan, statusnya ditoggle
                players[currentPlayer].second = !players[currentPlayer].second;

                playerTurn++;

            } else {
                // udah jalan semua, set playerTurn = 0, nextRound
                playerTurn = 0;
                nextRound();
            }
        }

        void nextRound() {
            if (this->round < 6) {
                round++;
                nextPlayer();
            } else {
                // TODO
                // udah selesai 6 ronde, cari pemenang (??)
            }
        }

        // return vector sisa urutan eksekusi saat ini (setelah reverse)
        vector<string> getRemainingReversedPlayer() {
            vector<string> res;
            int i = currentPlayer-1;
            while (i % 7 != currentPlayer) {
                if (players[i].second % 2 != round % 2) {
                    res.push_back(players[i].first.getNickname());
                }
                i--;
            }
            return res;
        }

        // return vector buat urutan eksekusi ronde berikutnya (setelah reverse)
        vector<string> getReversedPlayer() {
            vector<string> res;
            int i = currentPlayer-1;
            while (i % 7 != currentPlayer) {
                res.push_back(players[i].first.getNickname());
                i--;
            }
            return res;
        }

        /* SETTER */
        void dealToTable();
        void dealToPlayers();
        void dealAbilityToPlayers();

        void setReverseInfo(bool r) {
            this->isReversed = r;
        }

        /* GETTER */
        bool gameEnded();
};

#endif