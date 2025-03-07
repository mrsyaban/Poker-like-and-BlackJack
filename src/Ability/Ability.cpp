#include <iostream>
#include "Ability.hpp"
#include "../Game/Game.hpp"
#include "../Ability/Ability.hpp"
#include "../IO/IO.hpp"
#include "../Exception/exception.h"

using namespace std;

/* Ability Abstract class */
Ability::Ability(string type)
{
    available = true;
    this->type = type;
}

string Ability::getType() const
{
    return type;
}

/* Util */
void Ability::checkAbilityError(Game& g) 
{
    if (g.getRound() < 2) {
        AbilityNotHaveException e;
        throw e;
    }

    if (g.getPlayers()[g.getCurrentPlayer()].first.getAbility()->getAvail()) {
        Player& playerOnTurn = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);

        if (playerOnTurn.getAbility()->getType() !=  this->getType()) {
            AbilityNotHaveException e;
            throw e;
        }
    } else {
        AbilityNotAvailableException e;
        throw e;
    }
}

/* Getter */
bool Ability::getAvail() const
{
    return this->available;
}

/* Setter */
void Ability::setAvail(bool avail)
{
    this->available = avail;
}

/* Re-roll Ability */
ReRoll::ReRoll() : Ability("Re-Roll") {}

void ReRoll::Execute(Game& g) {
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }

    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    owner.deleteall();
    owner.add(g.getCardDeck());
    owner.add(g.getCardDeck());

    IO io;
    io.printAbilitySuccess(owner);
    owner.setAbilityAvailability(false);
}

/* Quadruple Ability */
Quadruple::Quadruple() : Ability("Quadruple") {}

void Quadruple::Execute(Game &g){
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    g.getPoint().Quadruple();
    
    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printAbilitySuccess(owner, g.getPoint());
    owner.setAbilityAvailability(false);
}

/* Quarter Ability */
Quarter::Quarter() : Ability("Quarter") {}

void Quarter::Execute(Game &g){
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    g.getPoint().Quarter();
    
    // print success message
    Player& owner = ((g.getPlayers().begin() + g.getCurrentPlayer())->first);
    IO io;
    io.printAbilitySuccess(owner, g.getPoint());
    owner.setAbilityAvailability(false);
}

/* Reverse Direction Ability */
ReverseDirection::ReverseDirection() : Ability("Reverse") {}

void ReverseDirection::Execute(Game &g)
{
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    g.setReverseInfo(true);

    IO io;
    Player& owner = (g.getPlayers()[g.getCurrentPlayer()].first);
    io.printAbilitySuccess(owner, g.getRemainingReversedPlayer(), g.getReversedPlayer());
    owner.setAbilityAvailability(false);
}

/* Swap Card Ability */
SwapCard::SwapCard(): Ability("Swap") {}

void SwapCard::Execute(Game& g) {
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    IO io;

    Player& owner = (g.getPlayers()[g.getCurrentPlayer()].first);
    vector<Player *> listPlayer;
    // select Player
    bool playerSelected = false;
    while (!playerSelected) {
        try {
            listPlayer = io.selectPlayer(owner, g.getPlayers(), g.getPlayers()[g.getCurrentPlayer()].first.getNickname());
            playerSelected = true;
        } catch(PlayerException& e) {
            cout << e.what() << endl;
            continue;
        }
    }

    Player& player1 = *listPlayer[0];
    Player& player2 = *listPlayer[1];

    bool check = false;
    int cardPlayer1, cardPlayer2;

    while (!check) {
        try {
            // select Card
            cardPlayer1 = io.selectCard(player1.getNickname());
            cardPlayer2 = io.selectCard(player2.getNickname());
            check = true;
        } catch(NumberInputException& e) {
            cout << e.what() << endl;
            continue;
        }
    }
    
    // swap
    if (cardPlayer1 == 1) {
        player1.puttoback();
    }
    if (cardPlayer2 == 1) {
        player2.puttoback();
    }
    player1.exchange(player2);
    
    // print successfull message
    vector<string> output = {player1.getNickname(), player2.getNickname()};
    io.printAbilitySuccess(owner, output);
    owner.setAbilityAvailability(false);
}

/* Switch Card Ability */
Switch::Switch(): Ability("Switch") {}

void Switch::Execute(Game& g) {
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    IO io;

    Player& owner = (g.getPlayers()[g.getCurrentPlayer()].first);
    
    vector<Player *> target;
    // select Player
    bool playerSelected = false;
    while (!playerSelected) {
        try {
            target = io.selectPlayer(owner, g.getPlayers(), g.getPlayers()[g.getCurrentPlayer()].first.getNickname());
            playerSelected = true;
        } catch(PlayerException& e) {
            cout << e.what() << endl;
            continue;
        }
    }
    
    Player& other = *target[0];

    owner.exchange(other);
    owner.exchange(other);

    vector<string> output = {target[0]->getNickname()};
    io.printAbilitySuccess(owner, output);
    owner.setAbilityAvailability(false);
}

/* Abilityless Ability */
Abilityless::Abilityless(): Ability("Abilityless") {}

void Abilityless::Execute(Game& g) {
    try {
        checkAbilityError(g);
    } catch (AbilityNotAvailableException& e) {
        cout << e.what() << endl;
        throw e;
        return;
    } catch (AbilityNotHaveException& e) {
        cout << e.what() << this->getType() << endl;
        throw e;
        return;
    }
    
    IO io;

    Player& owner = (g.getPlayers()[g.getCurrentPlayer()].first);
    
    /* Select Player */
    vector<Player *> inputPlayer;
    // select Player
    bool playerSelected = false;
    while (!playerSelected) {
        try {
            inputPlayer = io.selectPlayer(owner, g.getPlayers(), g.getPlayers()[g.getCurrentPlayer()].first.getNickname());
            playerSelected = true;
        } catch(PlayerException& e) {
            cout << e.what() << endl;
            continue;
        }
    }
    Player& playerChosen = *inputPlayer[0];

    bool allAvail = true;
    int n = g.getPlayers().size(), i = 0;

    while (allAvail && i < n) {
        if (g.getPlayers()[i].first.getAbility()->getAvail() == true && g.getPlayers()[i] != g.getPlayers()[g.getCurrentPlayer()]) {
            i++;
        } else {
            allAvail = false;
        }
    }

    // at least one player's ability available
    if (!allAvail) {
        vector<string> nick = {playerChosen.getNickname()};
        // Ability success
        if (playerChosen.getAbility()->getAvail()) {
            playerChosen.getAbility()->setAvail(false);
            io.printAbilitySuccess(owner, nick);
            owner.setAbilityAvailability(false);
        
        // chosen player's Ability Card has been used
        } else {
            io.printAbilityless(playerChosen.getNickname());
            owner.setAbilityAvailability(false);
        }
    
    // All ability non available
    } else {
        g.getPlayers()[g.getCurrentPlayer()].first.getAbility()->setAvail(false);
        io.printAbilityless("");
        owner.setAbilityAvailability(false);
    }
}