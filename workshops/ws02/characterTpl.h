#pragma once
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include "character.h"
#include <iostream>

namespace seneca {

    template <typename T>

    //class characterTpl derived from character
    class CharacterTpl : public Character {
    private:

        //max health
        int m_healthMax; 
        
        //current health
        T m_health;    

    public:
        // Constructor - initialize character 
        CharacterTpl(const char* name, int healthMax)
            : Character(name), m_healthMax(healthMax), m_health(static_cast<T>(healthMax)) {}

        // reduce current health 
        void takeDamage(int dmg) override {
            //reduce health using -=
            m_health -= static_cast<T>(dmg); 
            
            //if died(health<0)
            if (m_health <= 0) {
                std::cout << getName() << " has been defeated!" << std::endl;
                m_health = 0; 
            }
            //if alive
            else {
                std::cout << getName() << " took " << dmg
                    << " damage, " << getHealth()
                    << " health remaining." << std::endl;
            }
        }

        // Returns current health
        int getHealth() const override {
            return static_cast<int>(m_health); 
        }

        // Returns maximum health
        int getHealthMax() const override {
            return m_healthMax; 
        }

        // Sets current health 
        void setHealth(int health) override {
            m_health = static_cast<T>(health); 
        }

        // Sets the maximum health and current health to that value
        void setHealthMax(int health) override {
            m_healthMax = health; 
            m_health = static_cast<T>(health); 
        }

        /*
        // Override for getting attack amount
        int getAttackAmnt() const override {
            // Placeholder value; should be defined based on character type
            return 10; // Example attack amount
        }

        // Override for getting defense amount
        int getDefenseAmnt() const override {
            // Placeholder value; should be defined based on character type
            return 5; // Example defense amount
        }

        // Clone method for creating a copy of the character
        Character* clone() const override {
            return new CharacterTpl<T>(*this); // Create a copy of the character
        }

        // Override for attacking another character
        void attack(Character* enemy) override {
            // Implement attack logic here (not specified in the prompt)
            std::cout << getName() << " attacks " << enemy->getName() << "!" << std::endl;
            enemy->takeDamage(getAttackAmnt()); // Example damage application
        }
        */
    };

} // namespace seneca

#endif // SENECA_CHARACTERTPL_H
