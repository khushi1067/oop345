#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "CharacterTpl.h"  // Assuming this includes the definition of CharacterTpl
#include <iostream>
#include <cstring>

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
    private:
        int m_baseDefense;  // Basic defense of character
        int m_baseAttack;   // Basic attack of character
        Ability_t m_ability;  // Special ability of the Barbarian
        Weapon_t m_weapon[2]; // Weapons the character can use

    public:
        // Constructor to initialize the Barbarian with specific attributes
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
            Weapon_t primaryWeapon, Weapon_t secondaryWeapon);

        // Returns the attack amount with weapon enhancements
        int getAttackAmnt() const;

        // Returns the defense amount
        int getDefenseAmnt() const;

        // Creates a clone of the Barbarian instance
        Character* clone() const override;

        // Attacks an enemy character
        void attack(Character* enemy) override;

        // Takes damage, modified by the Barbarian's defense and special ability
        void takeDamage(int dmg) override;
    };

} // namespace seneca



#endif // SENECA_BARBARIAN_H


//#ifndef SENECA_BARBARIAN_H
//#define SENECA_BARBARIAN_H
//
//#include "CharacterTpl.h"  // Assuming this includes the definition of CharacterTpl
//#include <iostream>
//#include <cstring>
//
//namespace seneca {
//
//    template <typename T, typename Ability_t, typename Weapon_t>
//
//    class Barbarian : public CharacterTpl<T> {
//    private:
//
//        //basic defense of character
//        int m_baseDefense;
//
//        //represent basic attack
//        int m_baseAttack;
//
//        //represent special ability
//        Ability_t m_ability;
//
//        //represent weapons that characters can use
//        Weapon_t m_weapon[2];
//
//    public:
//
//        //initialize obj with parameters
//        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
//            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
//            : CharacterTpl<T>(name, healthMax),
//            m_baseAttack(baseAttack),
//            m_baseDefense(baseDefense) {
//            m_weapon[0] = primaryWeapon;
//            m_weapon[1] = secondaryWeapon;
//        }
//
//
//        int getAttackAmnt() const {
//
//            //return damage
//            return m_baseAttack +
//                static_cast<double>(m_weapon[0]) / 2 +
//                static_cast<double>(m_weapon[1]) / 2;
//        }
//
//        //return base defense value
//        int getDefenseAmnt() const {
//            return m_baseDefense;
//        }
//
//        // Create a copy of the current instance
//        Character* clone() const override {
//            return new Barbarian(*this); 
//        }
//
//        //attacks the enemy received as parameter and inflicts damage to it
//        void attack(Character* enemy) {
//
//            //print name -> is attacking [enemy name]. endl
//            std::cout << this->getName() << " is attacking " << enemy->getName() << "." <<std::endl;
//
//            // call function m_ability  pass address of current instance
//            m_ability.useAbility(this);
//
//            //retrive attackamount
//            int damage = getAttackAmnt();
//
//            //m_ability and pass dama in function transformDamageDeakt
//            m_ability.transformDamageDealt(damage);
//
//            //print 
//            std::cout << "    Barbarian deals " << damage << " melee damage!\n";
//            enemy->takeDamage(damage);
//        }
//
//        //modify damage and special ability 
//        void takeDamage(int dmg) {
//
//            //print [NAME] is attacked for [DAMAGE] damage.<endl>
//            //Barbarian has a defense of[DEFENSE].Reducing damage received.<endl>
//            std::cout << this->getName() << " is attacked for " << dmg << " damage.\n";
//            std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received.\n";
//
//            //subtract damage amount from parameter
//            dmg -= getDefenseAmnt();
//
//            //if damage<0
//            if (dmg < 0) {
//                //make damage = 0 (damage should not be -ve
//                dmg = 0; 
//            }
//
//            //call m_ability.transform function pass argument as parameter
//            m_ability.transformDamageReceived(dmg);
//
//            //call base class takedamage function 
//            CharacterTpl<T>::takeDamage(dmg); 
//        }
//    };
//
//} // namespace seneca
//
//#endif // BARBARIAN_H
