#ifndef GAME_HPP
#define GAME_HPP

#include "../Card/Card.hpp"
#include "../Deck/Deck.hpp"
#include "../Point/Point.hpp"
#include "../Table/Table.hpp"
#include "../Player/Player.hpp"
#include "../Ability/Ability.hpp"
#include "../Action/Action.hpp"
#include "../IO/IO.hpp"
#include "../GameEngine/GameEngine.hpp"

#include <iostream>
#include <map>
#include <string>
using namespace std;

/* Mapping command to int */
const map<string, int> inputToCommand = {
    {"NEXT", 1},
    {"HALF", 2},
    {"DOUBLE", 3},
    {"RE-ROLL", 4},
    {"QUADRUPLE", 5},
    {"QUARTER", 6},
    {"REVERSE", 7},
    {"SWAPCARD", 8},
    {"SWITCH", 9},
    {"ABILITYLESS", 10}
};

class Game
{
private:
    vector<pair<Player &, bool>> players; // idenya player bisa diakses lewat map, int adalah urutan player
    Deck<Card> cardDeck;
    Deck<Ability *> abilityDeck;
    Table table;
    Point point;
    bool isReversed;
    int playerTurn;
    int round;
    int currentPlayer;

public:
    Game(); // init all needed objects, init status player false;
    ~Game();

    /* Accessor, may only be called by class that act directly in the game */
    /* The returned reference may be altered */
    vector<pair<Player &, bool>> &getPlayers();
    Deck<Card> &getCardDeck();
    Deck<Ability *> &getAbilityDeck();
    Table &getTable();
    Point &getPoint();
    bool &getReverseInfo();
    int &getPlayerTurn();
    int &getRound();
    int &getCurrentPlayer();

    /* Setter */
    void addPlayer();
    void incCurrentPlayer();
    void decCurrentPlayer();

    void initNewMatch();

    void start();
    void startBlackJack();
    void nextPlayer();
    void nextTurn();
    void nextRound();

    // return vector sisa urutan eksekusi saat ini (setelah reverse)
    vector<string> getRemainingReversedPlayer();

    // return vector buat urutan eksekusi ronde berikutnya (setelah reverse)
    vector<string> getReversedPlayer();

    /* SETTER */
    void dealToTable();
    void dealToPlayers();
    void dealAbilityToPlayers();

    void setReverseInfo(bool r);

    /* GETTER */
    bool gameEnded();
};

#endif