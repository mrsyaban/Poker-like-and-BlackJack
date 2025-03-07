#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Point/Point.hpp"
#include "../Combo/Combo.hpp"
#include <string>

class Ability;

class Player : public InventoryHolder<Card> {
    private:
        const string nickName;
        Ability* handAbility;
        Combo highestCombo;
    
    protected:
        Point handPoint;

    public:
        Player(string); // ctor

        /* Operator Overloading*/
        friend bool operator<(const Player& p1, const Player& p2);
        friend bool operator>(const Player& p1, const Player& p2);
        friend bool operator==(const Player& p1, const Player& p2);

        /* Accessor */
        string getNickname() const;
        Ability* getAbility() const;
        virtual Point getPoint() const;
        Combo getHighestCombo() const;
        void getInfo() const;
        Card getCard(int) const;

        /* Setter */
        void setHighestCombo(Combo);
        void setAbility(Ability&);
        void setAbilityAvailability(bool);
        void dealToPlayer(InventoryHolder<Card>&);

        /* Utility Function*/
        void addPoint(long long);

};

#endif