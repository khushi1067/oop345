#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include "abilities.h"

#include "barbarian.h"
#include "character.h"
#include"characterTpl.h"
#include "guild.h"
#include "health.h"
#include "rogue.h"
#include "team.h"
#include "weapons.h"

#include <iostream>

namespace seneca {

    template <typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        
        //basic attack
        int m_baseAttack;

        //basic defense
        int m_baseDefense;

        //template
        Weapon_t m_weapon;

    public:

        //initializes
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
            : CharacterTpl<seneca::SuperHealth>(name, healthMax),
            m_baseAttack(baseAttack),
            m_baseDefense(baseDefense),
            m_weapon(weapon) {}

        //retyurn damage
        int getAttackAmnt() const {

            // 1.3 \times BASE\_ATTACK
            return static_cast<int>(1.3 * m_baseAttack);
        }

        //return the defense of this archer
        int getDefenseAmnt() const {

            //  1.2 \times BASE\_DEFENSE
            return static_cast<int>(1.2 * m_baseDefense);
        }

        //dynamically creates a copy 
        Character* clone() const override {

            //returns its address to the client.
            return new Archer(*this);
        }

        //attacks the enemy received as parameter and inflicts
        void attack(Character* enemy) override {

            //print -[NAME] is attacking [ENEMY_NAME].<endl>
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

            //retrive damage call getAttackAmnt()
            int damage = getAttackAmnt();

            //print -         Archer deals [ENHANCED_DAMAGE] ranged damage!<endl>
            std::cout << "    Archer deals " << damage << " ranged damage!" << std::endl;

            //apply damage call takeDamage()
            enemy->takeDamage(damage);
        }

        //modify the damage received using the defense capabilities, update the health in base class.
        void takeDamage(int dmg) override {

            //print - [NAME] is attacked for [DAMAGE] damage.<endl>
            //            Archer has a defense of[DEFENSE].Reducing damage received.<endl>
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
           
            //subtract the defense amount from the parameter.  
            //max 0 value cannot be less than 0
            dmg = std::max(0, dmg - getDefenseAmnt());

            //call takedamage from base class and update damage
            CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
        }
    };

}  // namespace seneca

#endif

