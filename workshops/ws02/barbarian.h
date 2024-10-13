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

