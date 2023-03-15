#include <iostream>
#include "Game.hpp"
#include "../Ability/Ability.hpp"
#include "../Player/Player.hpp"
#include "../IO/IO.hpp"
#include "../Combo/SearchCombo.hpp"
using namespace std;

Game::Game()
{
    // nothing
}

Game::~Game()
{
    // nothing
}

/** 
 * Accessor, may only be called by class that act directly in the game and change the game state
 * Return reference to the object, so it can be altered
 * e.g. : Action, Ability, IO, etc.
 */
vector<pair<Player&, bool>> &Game::getPlayers()
{
    return this->players;
}

Deck<Card> &Game::getCardDeck()
{
    return this->cardDeck;
}

Deck<Ability *> &Game::getAbilityDeck()
{
    return (this->abilityDeck);
}

Table &Game::getTable()
{
    return this->table;
}

Point &Game::getPoint()
{
    return this->point;
}

bool &Game::getReverseInfo()
{
    return this->isReversed;
}

int &Game::getPlayerTurn()
{
    return this->playerTurn;
}

int &Game::getRound()
{
    return this->round;
}

int &Game::getCurrentPlayer()
{
    return this->currentPlayer;
}
/* End of Accessor */


/* Setter */
void Game::incCurrentPlayer()
{
    currentPlayer++;
    currentPlayer %= 7;
}

void Game::decCurrentPlayer()
{
    currentPlayer--;
    currentPlayer %= 7;
}

void Game::initNewMatch(bool isRandom)
{
    /* Create new match*/
    IO io;

    // init all needed objects
    round = 1;
    playerTurn = 0;
    point = Point(); // default point : 64
    Deck<Card> deck; // create new randomized card deck
    Deck<Ability*> deckAbility; // create new randomized ability deck
    this->cardDeck = deck; // assign to cardDeck
    this->abilityDeck = deckAbility; // assign to abilityDeck

    // share all the cards to players and table
    dealToTable();
    dealToPlayers();
    cout << this->cardDeck.getTopItems().getNumber() << this->cardDeck.getTopItems().getColor() ;

    // print table
    io.printTable(table);
}


void Game::addPlayer()
{
    IO io;
    vector<string> inputNick = io.inputPlayerName();
    for (auto itr = inputNick.begin(); itr != inputNick.end(); itr++)
    {
        Player &p = *(new Player(*itr));
        pair<Player &, bool> element(p, false);
        players.push_back(element);
    }
}

void Game::dealToTable()
{
    this->table.dealToTable(this->cardDeck);
}

void Game::dealToPlayers()
{
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++)
    {
        p_itr->first.dealToPlayer(this->cardDeck);
    }
}

void Game::dealAbilityToPlayers()
{
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++)
    {
        p_itr->first.setAbility(*(getAbilityDeck().getTopItems()));
        this->abilityDeck.getItems().erase(this->abilityDeck.getTopItemsIterator());
    }
}

bool Game::gameEnded()
{
    for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++)
    {
        if (p_itr->first.getPoint() >= 4294967296.00)
        {
            return true;
        }
    }

    return false;
}

void Game::start()
{
    // init menu 
    IO io;
    string mainMenu;
    io.splashScreen();

    // read input
    try
    {
        mainMenu = io.mainMenu();
    }
    catch (BaseException &e)
    {
        std::cout << e.what() << endl;
    }

    while (mainMenu == "1")
    {
        /** 
         * Initialize all needed attributes 
         * On first start only
        */
        addPlayer(); // create player
        isReversed = false; // set reverse info to false
        currentPlayer = 0; // set current player to 0

        /* Every time get into new match */
        initNewMatch(); // create table, card deck, ability deck, deal card to table and player

        while (!gameEnded())
        {
            /* Run game until someone wins */
            nextTurn();
        }
        // TODO : print winner
        mainMenu = io.mainMenu();
    }

    io.printThankYou();
}

void Game::nextPlayer()
{
    /* Go to next player (based on direction) */
    if (isReversed)
    {
        decCurrentPlayer();
    }
    else
    {
        incCurrentPlayer();
    }
}

void Game::nextTurn()
{
    /**
     * Next turn is the main function that will be called on each turn
     * call this function until gameEnded() return true
    */

    // init io
    IO io;

    if (playerTurn != 7)
    {
        /**
         * Player status (check the definition of players : vector<pair<Player&, bool>>)
         * Player that has played in the round is labelled true (1) for odd round (mod 2 == 1)
         * Player that has played in the round is labelled false (0) for even round (mod 2 == 0)
        */
        while (players[currentPlayer].second % 2 == round % 2)
        {
            /* Go to next player until player that hasn't played found */
            nextPlayer();
        }

        // init command
        int command = -1;
        while (command == -1)
        {
            try
            {
                string action_cmd = io.turnInput(((this->players.begin() + this->currentPlayer)->first));
                command = inputToCommand.at(action_cmd);
            }
            catch (BaseException &e)
            {
                std::cout << e.what() << endl;
            }
        }

        /* All possible action */
        Next nxt;
        Half h;
        ReRoll rr;
        Double d;
        Quadruple qd;
        Quarter qtr;
        ReverseDirection rv;
        SwapCard swp;
        Switch swt;
        Abilityless abl;

        switch (command)
        {
        case 1:
            // execute next
            std::cout << "next" << endl;
            nxt.Execute(*this);
            break;
        case 2:
            std::cout << "half" << endl;
            h.Execute(*this);
            break;
        case 3:
            std::cout << "double" << endl;
            std::cout << point.getValue() << endl;
            d.Execute(*this);
            std::cout << point.getValue() << endl;
            break;
        case 4:
            std::cout << "reroll" << endl;
            rr.Execute(*this);
            break;
        case 5:
            std::cout << "quadruple" << endl;
            qd.Execute(*this);
            break;
        case 6:
            std::cout << "quarter" << endl;
            qtr.Execute(*this);
            break;
        case 7:
            std::cout << "reverse" << endl;
            rv.Execute(*this);
            break;
        case 8:
            std::cout << "swap card" << endl;
            swp.Execute(*this);
            break;
        case 9:
            std::cout << "switch" << endl;
            swt.Execute(*this);
            break;
        case 10:
            std::cout << "abilityless" << endl;
            abl.Execute(*this);
            break;
        default:
            break;
        }

        // sToggle player status
        players[currentPlayer].second = !players[currentPlayer].second;

        std::cout << "d" << endl;
        playerTurn++;
        nextPlayer();
        std::cout << "PLAYERTURN : " << playerTurn << endl;
        // nextRound();
    }
    else
    {
        // udah jalan semua, set playerTurn = 0, nextRound
        playerTurn = 0;
        nextRound();
    }
}

void Game::nextRound()
{
    IO io;
    if (this->round < 6)
    {
        round++;
        std::cout << "RONDE : " << round << endl;
        this->table.openCard();
        io.printTable(table);
        if (this->getRound() == 2)
        {
            dealAbilityToPlayers();
        }

        nextPlayer();
    }
    else
    {
        // TODO
        // udah selesai 6 ronde, cari pemenang (??)
        // find score and compare
        std::cout << "ronde (harusnya udah 6) : " << round << endl;
        double maxScore = 0;
        int playerWithMaxScore;
        int playerCtr = -1;

        for (auto p_itr = getPlayers().begin(); p_itr != getPlayers().end(); p_itr++)
        {
            playerCtr++;
            SearchCombo searchCombo(p_itr->first, this->getTable());
            p_itr->first.setHighestCombo(searchCombo.getHighestCombo());

            if (maxScore < p_itr->first.getHighestCombo().value())
            {
                maxScore = p_itr->first.getHighestCombo().value();
                playerWithMaxScore = playerCtr;
            }
        }

        // add points to the winner
        Player &winner = (getPlayers().begin() + playerWithMaxScore)->first;
        winner.addPoint(point.getValue());
        if (!gameEnded())
        {
            std::cout << "RONDE SEKARANG : " << round << endl;
            // TODO init new match
            point = Point();
            Deck<Card> deck;
            Deck<Ability *> deckAbility;
            this->cardDeck = deck;
            this->abilityDeck = deckAbility;
            dealToTable();
            dealToPlayers();
        }
        initNewMatch(true);
    }
}

// return vector sisa urutan eksekusi saat ini (setelah reverse)
vector<string> Game::getRemainingReversedPlayer()
{
    vector<string> res;
    int i = currentPlayer - 1;
    while (i % 7 != currentPlayer)
    {
        if (players[i].second % 2 != round % 2)
        {
            res.push_back(players[i].first.getNickname());
        }
        i--;
    }
    return res;
}

// return vector buat urutan eksekusi ronde berikutnya (setelah reverse)
vector<string> Game::getReversedPlayer()
{
    vector<string> res;
    int i = currentPlayer - 1;
    while (i % 7 != currentPlayer)
    {
        res.push_back(players[i].first.getNickname());
        i--;
    }
    return res;
}

void Game::setReverseInfo(bool r)
{
    this->isReversed = r;
}