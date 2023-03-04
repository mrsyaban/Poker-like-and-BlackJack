#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"

class Player : public InventoryHolder {
    private:
        Card** handCard;
        Ability handAbility; // TO BE CONFIRMED
        int handPoint;
        float highestCombo;

    public:
        /*
        Assume:
        cardList in inventory holder is static with protected specifier
        */
        Player(); //ctor

        /* Accessor */
        Card* getCard();
        Ability getAbility();
        int getPoint();

        /* Setter */
        void setRandomCard();
        void setRandomAbility();
        void setHighestCombo(float );

        /* Utility Function*/
        void addPoint(int );
};

#endif