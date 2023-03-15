#include <iostream>
#include "Game.hpp"
#include "../Ability/Ability.hpp"
#include "../Player/Player.hpp"
#include "../IO/IO.hpp"
#include "../Combo/SearchCombo.hpp"
using namespace std;

Game::Game() {
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

vector<pair<Player&, bool>>& Game::getPlayers(){
    return this->players;
}

Deck<Card>& Game::getCardDeck(){
    return this->cardDeck;
}

Deck<Ability*>& Game::getAbilityDeck(){
    return (this->abilityDeck);
}

Table& Game::getTable(){
    return this->table;
}

Point& Game::getPoint(){
    return this->point;
}

bool& Game::getReverseInfo(){
    return this->isReversed;
}

int& Game::getPlayerTurn(){
    return this->playerTurn;
}

int& Game::getRound(){
    return this->round;
}

int& Game::getCurrentPlayer(){
    return this->currentPlayer;
}

/* Setter */
void Game::incCurrentPlayer() {
    currentPlayer++;
    currentPlayer %= 7;
}

void Game::decCurrentPlayer() {
    currentPlayer--;
    currentPlayer %= 7;
}

void Game::addPlayer(){
    IO io;
    vector<string> inputNick = io.inputPlayerName();
    for (auto itr=inputNick.begin(); itr != inputNick.end(); itr++){
        Player& p = *(new Player(*itr)) ;
        pair<Player&, bool> element(p, false);
        players.push_back(element);
    }
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
        p_itr->first.setAbility(*(getAbilityDeck().getTopItems()));
        this->abilityDeck.getItems().erase(this->abilityDeck.getTopItemsIterator());
    }
}

bool Game::gameEnded() {
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
        if (p_itr->first.getPoint() >= 4294967296.00) {
            return true;
        }
    }

    return false;
}

void Game::start() {
    IO io;
    string mainMenu;
    io.splashScreen();
    try {
        mainMenu = io.mainMenu();
    } catch (baseException& e){
        cout << e.what() << endl;
    }

    while (mainMenu == "1"){
        // inisialisasi player
        addPlayer();

        this->currentPlayer = 0;
        while (!gameEnded()) {
            point = Point();
            Deck<Card> deck;
            Deck<Ability*> deckAbility;
            this->cardDeck = deck;
            this->abilityDeck = deckAbility;
            dealToTable();
            dealToPlayers();
            // cards already given to the table and players
            while (!gameEnded()) {
                for (int i = 0; i < 7; i++) {
                    nextTurn();
                }
            }

            // do {
            //     // BAGIAN I/O
            //     // io.printTable(table);
                
                
            //     // execute command
                

            //     nextTurn();
            //     // this->table.openCard();
            //     // if (this->getRound() == 2) {
            //     //     dealAbilityToPlayers();
            //     // }
            // } while (this->getRound() <= 6);

            // // find score and compare
            // double maxScore = 0;
            // int playerWithMaxScore;
            // int playerCtr = -1;

            // for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
            //     playerCtr++;
            //     SearchCombo highestCombo(p_itr->first, this->getTable());
            //     p_itr->first.setHighestCombo(highestCombo.getHighestCombo());
                
            //     if (maxScore < p_itr->first.getHighestCombo().value()) {
            //         maxScore = p_itr->first.getHighestCombo().value();
            //         playerWithMaxScore = playerCtr;
            //     }
            // }

            // // add points to the winner
            // Player winner = (getPlayers().begin() + playerWithMaxScore)->first;
            // winner.addPoint(point.getValue());
        }
        mainMenu = io.mainMenu();        
    }

    io.printThankYou();
}

void Game::nextPlayer() {
    if (isReversed) {
        decCurrentPlayer();
    } else {
        incCurrentPlayer();
    }
}

void Game::nextTurn() {

    IO io;

    if (playerTurn != 7) {
        // status player yang udah jalan adalah true  (1) untuk ronde ganjil (mod 2 == 1)
        // status player yang udah jalan adalah false (0) untuk ronde genap  (mod 2 == 0)
        while (players[currentPlayer].second % 2 == round % 2) {
            nextPlayer();
        }

        // TODO
        int command = -1;
        while (command == -1) {
            try {
                command = inputToCommand.at(io.turnInput(((this->players.begin() + this->currentPlayer)->first).getNickname()));
            } catch (baseException& e) {
                cout << e.what() << endl;
            }
        }

        switch (command) {
            case 1:
                // execute next
                cout << "next" << endl;
            default:
                cout << "" << endl;
        }
        // currentPlayer jalan, manggil command (??)

        // setelah playernya jalan, statusnya ditoggle
        players[currentPlayer].second = !players[currentPlayer].second;

        playerTurn++;
        nextPlayer();

    } else {
        // udah jalan semua, set playerTurn = 0, nextRound
        playerTurn = 0;
        nextRound();
    }

}

void Game::nextRound() {
    IO io;
    if (this->round < 6) {
        io.printTable(table);
        round++;
        this->table.openCard();
        if (this->getRound() == 2) {
            dealAbilityToPlayers();
        }

        nextPlayer();
    } else {
        // TODO
        // udah selesai 6 ronde, cari pemenang (??)
        // find score and compare
        double maxScore = 0;
        int playerWithMaxScore;
        int playerCtr = -1;

        for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++) {
            playerCtr++;
            SearchCombo highestCombo(p_itr->first, this->getTable());
            p_itr->first.setHighestCombo(highestCombo.getHighestCombo());
            
            if (maxScore < p_itr->first.getHighestCombo().value()) {
                maxScore = p_itr->first.getHighestCombo().value();
                playerWithMaxScore = playerCtr;
            }
        }

        // add points to the winner
        Player winner = (getPlayers().begin() + playerWithMaxScore)->first;
        winner.addPoint(point.getValue());
        if (!gameEnded()) {
            // TODO init new match
        }
    }
}

// return vector sisa urutan eksekusi saat ini (setelah reverse)
vector<string> Game::getRemainingReversedPlayer() {
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
vector<string> Game::getReversedPlayer() {
    vector<string> res;
    int i = currentPlayer-1;
    while (i % 7 != currentPlayer) {
        res.push_back(players[i].first.getNickname());
        i--;
    }
    return res;
}

void Game::setReverseInfo(bool r) {
    this->isReversed = r;
}