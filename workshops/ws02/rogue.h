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
            return m_baseAttack + 2 * static_cast<int>(m_weapon);
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
            //return new Rogue(*this);
            return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);

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


//#pragma once
//#ifndef SENECA_ROGUE_H
//#define SENECA_ROGUE_H
//
//#include "CharacterTpl.h"
//#include "abilities.h"
//#include "weapons.h"
//#include <iostream>
//
//namespace seneca {
//
//    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//    class Rogue : public CharacterTpl<T> {
//    private:
//        int m_baseDefense;       // Basic defense value
//        int m_baseAttack;        // Basic attack value
//        FirstAbility_t m_firstAbility;  // First special ability
//        SecondAbility_t m_secondAbility; // Second special ability
//
//    public:
//        // Constructor to initialize the Rogue with specific attributes
//        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
//
//        // Returns the base attack amount
//        int getAttackAmnt() const;
//
//        // Returns the base defense amount
//        int getDefenseAmnt() const;
//
//        // Creates a copy of the Rogue instance
//        Character* clone() const override;
//
//        // Attacks an enemy character
//        void attack(Character* enemy) override;
//
//        // Takes damage, modified by the Rogue's defense and special abilities
//        void takeDamage(int dmg) override;
//    };
//
//}  // namespace seneca
//
//#include "Rogue.cpp"  // Include the implementation for the template class
//
//#endif // SENECA_ROGUE_H
//
//
////#pragma once
////#ifndef SENECA_ROGUE_H
////#define SENECA_ROGUE_H
////
////#include "characterTpl.h"
////#include "abilities.h"
////#include "weapons.h"
////#include <iostream>
////
////namespace seneca {
////
////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
////
////    //rouge derived from characterTpl<T>
////
////    //type T store health
////    class Rogue : public CharacterTpl<T> {
////
////        
////        //represent basic defense
////        int m_baseDefense;
////        //represent basic attack
////        int m_baseAttack;
////
////        //ability
////        FirstAbility_t m_firstAbility;
////        SecondAbility_t m_secondAbility;
////
////        //Dagger::m_weapon;
////
////    public:
////        //initialize obj with parameters
////        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
////            : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {}
////
////        int getAttackAmnt() const {
////            //return damage 
////            return m_baseAttack;
////        }
////
////        int getDefenseAmnt() const {
////            //return defense
////            return m_baseDefense;
////        }
////
////        Character* clone() const override {
////            //create copy of current instance & return address of client
////            return new Rogue(*this);
////        }
////
////        void attack(Character* enemy) override {
////            //attack enemy receives as parameter
////            
////            //print [NAME] is attacking [ENEMY_NAME].<endl>
////            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
////
////            //call ability pass current instance
////            m_firstAbility.useAbility(this);
////            m_secondAbility.useAbility(this);
////
////            //gets damage value by using getAttackAmnt function
////            int damage = getAttackAmnt();
////
////            //calculate damage
////            m_firstAbility.transformDamageDealt(damage);
////            m_secondAbility.transformDamageDealt(damage);
////
////            //print  Rogue deals [ENHANCED_DAMAGE] melee damage!<endl>
////            std::cout << "    Rogue deals " << damage << " damage!" << std::endl;
////
////            //apply damage to enemy call takeDamage function on parameter
////            enemy->takeDamage(damage);
////        }
////
////        //modify damage received using defense capabilities, special abilities
////        void takeDamage(int dmg) override {
////
////            //print  [NAME] is attacked for [DAMAGE] damage.<endl>
////            //Rogue has a defense of[DEFENSE].Reducing damage received.<endl>
////            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
////            std::cout << "    Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
////           
////            //sub -> parameter - damage amount   value cannot be -ve 
////            dmg = std::max(0, dmg - getDefenseAmnt());
////
////            //class m_firstAbility pass parameter as argument
////            m_firstAbility.transformDamageReceived(dmg);
////            m_secondAbility.transformDamageReceived(dmg);
////
////
////            CharacterTpl<T>::takeDamage(dmg);
////        }
////    };
////
////}  // namespace seneca
////
////#endif