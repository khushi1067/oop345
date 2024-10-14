

#pragma once
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H

#include "abilities.h"
#include "archer.h"
#include "barbarian.h"
#include "character.h"
#include"characterTpl.h"
#include "guild.h"
#include "health.h"


#include "team.h"
#include "weapons.h"
#include <iostream>

namespace seneca {

    template <typename T,
        typename FirstAbility_t,
        typename SecondAbility_t>

    class Rogue : public CharacterTpl<T> {

    private:
        //basic defense
        int m_baseDefense;
        // Basic attacks
        int m_baseAttack;

        //special abilities
        FirstAbility_t m_firstAbility;
        SecondAbility_t m_secondAbility;

        seneca::Dagger m_weapon;   //////////////////////////

    public:
        // Constructor to initialize 
       /* Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
            : CharacterTpl<T>(name, healthMax),
            m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {}*/

            //public:
                // Constructor to initialize 
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
            : CharacterTpl<T>(name, healthMax) {
            m_baseDefense = baseDefense; // Initialize in the declared order
            m_baseAttack = baseAttack;
        }



        // Returns the base attack amount
        // 
        // Check if Dagger has proper conversion 
        int getAttackAmnt() const {
            return m_baseAttack + 2 * static_cast<int>(m_weapon) + 1;
        }

        //int getAttackAmnt() const {
        //    //BASE\_ATTACK + 2 \times WEAPON\_DAMAGE
        //    return m_baseAttack + static_cast<int>(2 * static_cast<double>(m_weapon));
        //}

        // Returns the base defense amount
        int getDefenseAmnt() const {
            return m_baseDefense;
        }

        // Creates a copy of the Rogue instance
        Character* clone() const override {
            return new Rogue(*this);
            //return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);

        }

        // Attacks an enemy character
        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

            // Use abilities
            m_firstAbility.useAbility(this);
            m_secondAbility.useAbility(this);

            // Get the attack amount and modify it using abilities
            int damage = getAttackAmnt();
            m_firstAbility.transformDamageDealt(damage);
            m_secondAbility.transformDamageDealt(damage);

            // Print damage dealt
            std::cout << "    Rogue deals " << damage << " damage!" << std::endl;

            // Inflict damage on the enemy
            enemy->takeDamage(damage);
        }

        // Takes damage, modified by the Rogue's defense and special abilities
        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;

            // Calculate modified damage with defense
            dmg = std::max(0, dmg - getDefenseAmnt());

            // Modify damage with abilities
            m_firstAbility.transformDamageReceived(dmg);
            m_secondAbility.transformDamageReceived(dmg);

            // Pass modified damage to base class
            CharacterTpl<T>::takeDamage(dmg);
        }
    };

}  // namespace seneca

#endif // SENECA_ROGUE_H
