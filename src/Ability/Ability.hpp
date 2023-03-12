#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
using namespace std;

class Ability { 
    private:
        bool available;

    public:
        Ability();
        ~Ability();
        virtual void executeAbility() = 0;
};

class ReRoll: public Ability {
    private:

    public:
        ReRoll();
        ~ReRoll();
        void executeAbility(); // lihat situasi
};

class Quadruple: public Ability {
    private:

    public:
        Quadruple();
        void executeAbility(); // lihat situasi
};

class ReverseDirection: public Ability {
    private:

    public:
        ReverseDirection();
        void executeAbility(); // lihat situasi
};

class SwapCard: public Ability {
    private:

    public:
        SwapCard();
        void executeAbility(); // lihat situasi
};

class Switch: public Ability {
    private:

    public:
        Switch();
        void executeAbility(); // lihat situasi
};

class Abilityless: public Ability {
    private:

    public:
        Abilityless();
        void executeAbility(); // lihat situasi
};

#endif