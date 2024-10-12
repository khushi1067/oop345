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


////#ifndef SENECA_ARCHER_H
////#define SENECA_ARCHER_H
////
////#include "characterTpl.h"
////#include "weapons.h"
////#include <iostream>
////
////namespace seneca {
////
////    // Archer class inherits from CharacterTpl with SuperHealth type
////    template <typename Weapon_t>
////    class Archer : public CharacterTpl<seneca::SuperHealth> {
////        int m_baseAttack;    // Basic attack power of the Archer
////        int m_baseDefense;   // Basic defense of the Archer
////        Weapon_t m_weapon;   // The weapon this character can use in battle
////
////    public:
////        // Constructor initializing the Archer with provided values
////        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
////
////        // Get the attack amount with enhanced damage
////        int getAttackAmnt() const;
////
////        // Get the defense amount with enhanced defense
////        int getDefenseAmnt() const;
////
////        // Clone the current Archer object
////        Character* clone() const override;
////
////        // Attack the enemy and inflict damage
////        void attack(Character* enemy) override;
////
////        // Take damage, reducing by defense before updating health
////        void takeDamage(int dmg) override;
////    };
////
////}  // namespace seneca
////
////#include "archer.cpp"
////
////#endif
//
//
//
//#ifndef SENECA_ARCHER_H
//#define SENECA_ARCHER_H
//
//#include "characterTpl.h"
//#include "weapons.h"
//#include "health.h"
//#include "barbarian.h"
//#include "guild.h"
//#include "rogue.h"
//#include <iostream>
//
//namespace seneca {
//
//    template <typename Weapon_t>
//    class Archer : public CharacterTpl<seneca::SuperHealth> {
//        int m_baseAttack;
//        int m_baseDefense;
//        Weapon_t m_weapon;
//
//    public:
//        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
//            : CharacterTpl<seneca::SuperHealth>(name, healthMax),
//            m_baseAttack(baseAttack),
//            m_baseDefense(baseDefense),
//            m_weapon(weapon) {}
//
//        int getAttackAmnt() const {
//            return static_cast<int>(1.3 * m_baseAttack);
//        }
//
//        int getDefenseAmnt() const {
//            return static_cast<int>(1.2 * m_baseDefense);
//        }
//
//        Character* clone() const override {
//            return new Archer(*this);
//        }
//
//        void attack(Character* enemy) override {
//            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
//            int damage = getAttackAmnt();
//            std::cout << "    Archer deals " << damage << " ranged damage!" << std::endl;
//            enemy->takeDamage(damage);
//        }
//
//        void takeDamage(int dmg) override {
//            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
//            std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
//            dmg = std::max(0, dmg - getDefenseAmnt());
//            CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
//        }
//    };
//
//}  // namespace seneca
//
//#endif
//
//
