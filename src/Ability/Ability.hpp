#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "../Game/Game.hpp"

#include <iostream>
using namespace std;

class Ability { 
    private:
        bool available;
        // static int& playerTurn;
        // static bool& isReversed;
        // static Player& players[7];
        // static Deck& deck;
        // static Point& point;
    public:
        Ability();
        ~Ability();
        void initData(Game&);
        virtual void Execute() = 0;
};

class ReRoll: public Ability {
    private:
        
    public:
        ReRoll();
        ~ReRoll();
        void Execute(); // lihat situasi
};

class Quadruple: public Ability {
    private:

    public:
        Quadruple();
        void Execute(); // lihat situasi
};

class ReverseDirection: public Ability {
    private:

    public:
        ReverseDirection();
        void Execute(); // lihat situasi
};

class SwapCard: public Ability {
    private:

    public:
        SwapCard();
        void Execute(); // lihat situasi
};

class Switch: public Ability {
    private:

    public:
        Switch();
        void Execute(); // lihat situasi
};

class Abilityless: public Ability {
    private:

    public:
        Abilityless();
        void Execute(); // lihat situasi
};

#endif