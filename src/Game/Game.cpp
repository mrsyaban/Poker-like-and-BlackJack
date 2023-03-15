#include <iostream>
#include "Game.hpp"
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
        p_itr->first.setAbility(this->abilityDeck.getTopItems());
        this->abilityDeck.getItems().erase(this->abilityDeck.getTopItemsIterator());
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
    // inisialisasi player
    for (int i = 0; i < 7; i++) {
        addPlayer();
    }


    while (!gameEnded()) {
        point = Point();
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
    }
}