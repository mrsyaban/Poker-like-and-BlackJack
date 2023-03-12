#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include "../Combo/Combo.hpp"
#include <string>


class Player : public InventoryHolder {
    private:
        string nickName;
        Ability handAbility;
        int handPoint;
        Combo highestCombo;

    public:
        Player(); // ctor

        /* Operator Overloading*/
        friend bool operator<(const Player& p1, const Player& p2);
        friend bool operator>(const Player& p1, const Player& p2);
        InventoryHolder& operator+(const Card &);
        InventoryHolder& operator-(const Card &);
        InventoryHolder& operator=(InventoryHolder &);

        /* Accessor */
        Card getCard(int) const;
        int getPoint() const;
        Combo getHighestCombo() const;

        /* Setter */
        void setHighestCombo(float );

        /* Utility Function*/
        void addPoint(int );

};

#endif