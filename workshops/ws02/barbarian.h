// barbarian.h
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"
#include "character.h"
#include <iostream>

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>


    class Barbarian : public CharacterTpl<T> {
    private:
       // basic defense
        int m_baseDefense;
        //basic attack
        int m_baseAttack;
        //ability
        Ability_t m_ability;
        //weapn 
        Weapon_t m_weapons[2]; 

       

    public:
        // Constructor to initialize the Barbarian with specific attributes

      /*  Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {
            m_weapons[0] = primaryWeapon;
            m_weapons[1] = secondaryWeapon;
        }*/

        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpl<T>(name, healthMax),
            m_baseDefense(baseDefense), 
            m_baseAttack(baseAttack) {
            m_weapons[0] = primaryWeapon;
            m_weapons[1] = secondaryWeapon;
        }


        // Returns the damage the barbarian can do in an attack
        int getAttackAmnt() const {
            //returns the damage 
            //  BASE\_ATTACK + \frac{WEAPON_1\_DAMAGE}{2} + \frac{WEAPON_2\_DAMAGE}{2}
            return m_baseAttack + (static_cast<double>(m_weapons[0]) / 2) +
                (static_cast<double>(m_weapons[1]) / 2);
        }

        int getDefenseAmnt() const {
        // Returns the base defense value
            return m_baseDefense;
        }

        Character* clone() const override {
        // Clones the current instance and returns its address
            return new Barbarian(*this); 
        }

        // attacks the enemy received as parameter and inflicts damage to it
        void attack(Character* enemy) override {
            //print     [NAME] is attacking [ENEMY_NAME].<endl>
            std::cout << this->getName() << " is attacking " << enemy->getName() << ".\n";
            
            // Use special ability on self
            m_ability.useAbility(this); 

            //retrieve the damage
            int damage = getAttackAmnt();

            // Enhance damage
            m_ability.transformDamageDealt(damage); 

            //print  Barbarian deals [ENHANCED_DAMAGE] melee damage!<endl>

            std::cout << "    Barbarian deals " << damage << " melee damage!\n";

            // Apply damage to the enemy
            enemy->takeDamage(damage); 
        }

        // Takes damage and modifies it based on defense and ability
        void takeDamage(int dmg) override {

            //print  [NAME] is attacked for [DAMAGE] damage.<endl>
           //            Barbarian has a defense of[DEFENSE].Reducing damage received.<endl>
            std::cout << this->getName() << " is attacked for " << dmg << " damage.\n";
            std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received.\n";

            //blocak damage by subtracting
            // Subtract defense from damage
            dmg -= getDefenseAmnt();

            //value cannot be less than 0
            if (dmg < 0) dmg = 0; 

            // Use ability to reduce damage
            m_ability.transformDamageReceived(dmg); 

            // Call base class method to update health
            CharacterTpl<T>::takeDamage(dmg); 
        }
    };

} // namespace seneca

#endif // SENECA_BARBBARIAN_H


//#ifndef SENECA_BARBARIAN_H
//#define SENECA_BARBARIAN_H
//
//#include "abilities.h"
//#include "archer.h"
//
//#include "character.h"
//#include"characterTpl.h"
//#include "guild.h"
//#include "health.h"
//#include "rogue.h"
//#include "team.h"
//#include "weapons.h" 
//#include <iostream>
//#include <cstring>
//
//namespace seneca {
//
//    //templates
//    template <typename T,
//        typename Ability_t, 
//        typename Weapon_t>
//
//    class Barbarian : public CharacterTpl<T> {
//    private:
//        //basic defense
//        int m_baseDefense;
//        //basic attack
//        int m_baseAttack;
//        //ability
//        Ability_t m_ability;
//        //weapn 
//        Weapon_t m_weapon[2]; 
//
//
//    public:
//        // Constructor to initialize
//        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
//            Weapon_t primaryWeapon, Weapon_t secondaryWeapon) 
//            :          
//            CharacterTpl<T>(name, healthMax),
//            m_baseAttack(baseAttack),
//            m_baseDefense(baseDefense) {
//            m_weapon[0] = primaryWeapon;
//            m_weapon[1] = secondaryWeapon;
//        }
//
//        int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
//            return m_baseAttack + static_cast<int>(m_weapon[0]) / 2 + static_cast<int>(m_weapon[1]) / 2;
//        }
//
//        // Returns the attack amount with weapon enhancements
//        int getAttackAmnt() const;
//
//        // Returns the defense amount
//        int getDefenseAmnt() const;
//
//        // Creates a clone of the Barbarian instance
//        Character* clone() const override;
//
//        // Attacks an enemy character
//        void attack(Character* enemy) override;
//
//        // Takes damage, modified by the Barbarian's defense and special ability
//        void takeDamage(int dmg) override;
//    };
//
//} // namespace seneca
//
//
//
//#endif // SENECA_BARBARIAN_H
//
//
////#ifndef SENECA_BARBARIAN_H
////#define SENECA_BARBARIAN_H
////
////#include "CharacterTpl.h"  // Assuming this includes the definition of CharacterTpl
////#include <iostream>
////#include <cstring>
////
////namespace seneca {
////
////    template <typename T, typename Ability_t, typename Weapon_t>
////
////    class Barbarian : public CharacterTpl<T> {
////    private:
////
////        //basic defense of character
////        int m_baseDefense;
////
////        //represent basic attack
////        int m_baseAttack;
////
////        //represent special ability
////        Ability_t m_ability;
////
////        //represent weapons that characters can use
////        Weapon_t m_weapon[2];
////
////    public:
////
////        //initialize obj with parameters
////        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
////            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
////            : CharacterTpl<T>(name, healthMax),
////            m_baseAttack(baseAttack),
////            m_baseDefense(baseDefense) {
////            m_weapon[0] = primaryWeapon;
////            m_weapon[1] = secondaryWeapon;
////        }
////
////
////        int getAttackAmnt() const {
////
////            //return damage
////            return m_baseAttack +
////                static_cast<double>(m_weapon[0]) / 2 +
////                static_cast<double>(m_weapon[1]) / 2;
////        }
////
////        //return base defense value
////        int getDefenseAmnt() const {
////            return m_baseDefense;
////        }
////
////        // Create a copy of the current instance
////        Character* clone() const override {
////            return new Barbarian(*this); 
////        }
////
////        //attacks the enemy received as parameter and inflicts damage to it
////        void attack(Character* enemy) {
////
////            //print name -> is attacking [enemy name]. endl
////            std::cout << this->getName() << " is attacking " << enemy->getName() << "." <<std::endl;
////
////            // call function m_ability  pass address of current instance
////            m_ability.useAbility(this);
////
////            //retrive attackamount
////            int damage = getAttackAmnt();
////
////            //m_ability and pass dama in function transformDamageDeakt
////            m_ability.transformDamageDealt(damage);
////
////            //print 
////            std::cout << "    Barbarian deals " << damage << " melee damage!\n";
////            enemy->takeDamage(damage);
////        }
////
////        //modify damage and special ability 
////        void takeDamage(int dmg) {
////
////            //print [NAME] is attacked for [DAMAGE] damage.<endl>
////            //Barbarian has a defense of[DEFENSE].Reducing damage received.<endl>
////            std::cout << this->getName() << " is attacked for " << dmg << " damage.\n";
////            std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received.\n";
////
////            //subtract damage amount from parameter
////            dmg -= getDefenseAmnt();
////
////            //if damage<0
////            if (dmg < 0) {
////                //make damage = 0 (damage should not be -ve
////                dmg = 0; 
////            }
////
////            //call m_ability.transform function pass argument as parameter
////            m_ability.transformDamageReceived(dmg);
////
////            //call base class takedamage function 
////            CharacterTpl<T>::takeDamage(dmg); 
////        }
////    };
////
////} // namespace seneca
////
////#endif // BARBARIAN_H
