#include <iostream>
#include "Game.hpp"
#include "../Ability/Ability.hpp"
#include "../Player/Player.hpp"
#include "../IO/IO.hpp"
#include "../Combo/SearchCombo.hpp"
using namespace std;

Game::Game()
{
    // this->gameStart = true;
    // // ctor player
    // for (int i = 1; i <= 7; i++) {
    //     this->players.insert(pair<Player, int>(new Player(), i));
    // }
    // Point p(64);
    // point = p;
}

Game::~Game()
{
}

vector<pair<Player &, bool>> &Game::getPlayers()
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

void Game::initNewMatch()
{
    IO io;

    // inisialisasi player
    round = 1;
    playerTurn = 0;
    // table = Table();

    // this->currentPlayer = 0;

    point = Point();
    Deck<Card> deck;
    Deck<Ability *> deckAbility;
    this->cardDeck = deck;
    this->abilityDeck = deckAbility;
    dealToTable();
    dealToPlayers();

    // this->table.openCard();
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
    IO io;
    string mainMenu;
    io.splashScreen();
    try
    {
        mainMenu = io.mainMenu();
    }
    catch (baseException &e)
    {
        cout << e.what() << endl;
    }

    while (mainMenu == "1")
    {
        addPlayer();
        initNewMatch();
        isReversed = false;
        currentPlayer = 0;
        // // inisialisasi player
        // addPlayer();
        // round = 1;
        // playerTurn = 0;
        // isReversed = false;
        // // table = Table();

        // this->currentPlayer = 0;

        // point = Point();
        // Deck<Card> deck;
        // Deck<Ability *> deckAbility;
        // this->cardDeck = deck;
        // this->abilityDeck = deckAbility;
        // dealToTable();
        // dealToPlayers();

        // // this->table.openCard();
        // io.printTable(table);

        while (!gameEnded())
        {

            nextTurn();
        }
        cout << "udah menang ----------" << endl;
        mainMenu = io.mainMenu();
    }

    io.printThankYou();
}

void Game::nextPlayer()
{
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

    IO io;

    if (playerTurn != 7)
    {
        cout << "a" << endl;
        cout << "PLAYER TURN : " << playerTurn << endl;
        // status player yang udah jalan adalah true  (1) untuk ronde ganjil (mod 2 == 1)
        // status player yang udah jalan adalah false (0) untuk ronde genap  (mod 2 == 0)
        while (players[currentPlayer].second % 2 == round % 2)
        {
            cout << "RONDE a : " << round << endl;
            nextPlayer();
        }

        // TODO
        int command = -1;
        while (command == -1)
        {
            cout << "c" << endl;
            cout << currentPlayer << endl;
            try
            {
                command = inputToCommand.at(io.turnInput(((this->players.begin() + this->currentPlayer)->first).getNickname()));
            }
            catch (baseException &e)
            {
                cout << e.what() << endl;
            }
            cout << "asda" << endl;
        }

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
            cout << "next" << endl;
            nxt.Execute(*this);
            break;
        case 2:
            cout << "half" << endl;
            h.Execute(*this);
            break;
        case 3:
            cout << "double" << endl;
            cout << point.getValue() << endl;
            d.Execute(*this);
            cout << point.getValue() << endl;
            break;
        case 4:
            cout << "reroll" << endl;
            rr.Execute(*this);
            break;
        case 5:
            cout << "quadruple" << endl;
            qd.Execute(*this);
            break;
        case 6:
            cout << "quarter" << endl;
            qtr.Execute(*this);
            break;
        case 7:
            cout << "reverse" << endl;
            rv.Execute(*this);
            break;
        case 8:
            cout << "swap card" << endl;
            swp.Execute(*this);
            break;
        case 9:
            cout << "switch" << endl;
            swt.Execute(*this);
            break;
        case 10:
            cout << "abilityless" << endl;
            abl.Execute(*this);
            break;
        default:
            break;
        }
        // currentPlayer jalan, manggil command (??)

        // setelah playernya jalan, statusnya ditoggle
        players[currentPlayer].second = !players[currentPlayer].second;

        cout << "d" << endl;
        playerTurn++;
        nextPlayer();
        cout << "PLAYERTURN : " << playerTurn << endl;
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
        cout << "RONDE : " << round << endl;
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
        cout << "ronde (harusnya udah 6) : " << round << endl;
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
            cout << "RONDE SEKARANG : " << round << endl;
            // TODO init new match
            point = Point();
            Deck<Card> deck;
            Deck<Ability *> deckAbility;
            this->cardDeck = deck;
            this->abilityDeck = deckAbility;
            dealToTable();
            dealToPlayers();
        }
        initNewMatch();
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