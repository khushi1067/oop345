#pragma once
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include "character.h"
#include <iostream>
#include <limits> 

namespace seneca {

    template <typename T>
    class CharacterTpl : public Character {

    private:
        int m_healthMax; // Maximum health
        T m_health;      // Current health

    public:
        // Constructor to initialize character name and maximum health
        CharacterTpl(const char* name, int healthMax)
            : Character(name) {

            m_healthMax = healthMax;
            m_health = healthMax;
        }

        // Reduces the current health by the damage amount
        void takeDamage(int dmg) override {
            // Subtract damage from current health
            m_health -= dmg;

            // Check if the character is defeated
            if (getHealth() <= 0) {
                m_health = 0; // Ensure health doesn't go negative
                std::cout << getName() << " has been defeated!" << std::endl;
            }
            else {
                std::cout << getName() << " took " << dmg
                    << " damage, " << getHealth()
                    << " health remaining." << std::endl;
            }
        }

        // Returns current health, assuming T can be cast to int
        int getHealth() const override {
            return (m_health);
        }

        // Returns maximum health
        int getHealthMax() const override {
            return m_healthMax;
        }

        // Sets the current health, assuming T can accept an int assignment
        void setHealth(int health) override {
            m_health = health;
            // Ensure health doesn't go below 0
            if (m_health < 0) {
                m_health = 0;
            }
        }

        // Sets the maximum health and resets current health
        void setHealthMax(int health) override {
            m_healthMax = health;
            setHealth(health); // Reset current health to the new maximum
        }
    };

} // namespace seneca

#endif // SENECA_CHARACTERTPL_H


//
//
//
//#pragma once
//#ifndef SENECA_CHARACTERTPL_H
//#define SENECA_CHARACTERTPL_H
//
//#include "character.h"
//#include <iostream>
//#include <limits> 
//
//namespace seneca {
//
//    template <typename T>
//    class CharacterTpl : public Character {
//
//    private:
//        int m_healthMax; // Maximum health
//        T m_health;      // Current health
//
//    public:
//        // Constructor to initialize character name and maximum health
//        CharacterTpl(const char* name, int healthMax)
//            : Character(name), m_healthMax(healthMax), m_health(static_cast<T>(healthMax)) {}
//
//        // Reduces the current health by the damage amount
//        void takeDamage(int dmg) override {
//            // Subtract damage from current health
//            m_health -= static_cast<T>(dmg); 
//
//            // Check if the character is defeated
//            if (getHealth() <= 0) {
//                std::cout << getName() << " has been defeated!" << std::endl;
//                // Ensure health doesn't go negative
//                m_health = static_cast<int>(0); 
//            } else {
//                std::cout << getName() << " took " << dmg
//                          << " damage, " << getHealth()
//                          << " health remaining." << std::endl;
//            }
//        }
//
//        // Returns current health, assuming T can be cast to int
//        int getHealth() const override {
//            return static_cast<int>(m_health);
//        }
//
//        // Returns maximum health
//        int getHealthMax() const override {
//            return m_healthMax;
//        }
//
//        // Sets the current health
//        void setHealth(int health) override {
//            m_health = static_cast<int>(health);
//        }
//
//        // Sets the maximum health and resets current health
//        void setHealthMax(int health) override {
//            m_healthMax = health;
//            m_health = static_cast<int>(health);
//        }
//
//    };
//
//} // namespace seneca
//
//#endif // SENECA_CHARACTERTPL_H
//
//
////
//////#pragma once
//////#ifndef SENECA_CHARACTERTPL_H
//////#define SENECA_CHARACTERTPL_H
//////
//////#include "character.h"
//////#include <iostream>
//////
//////namespace seneca {
//////
//////    template <typename T>
//////    class CharacterTpl : public Character {
//////    private:
//////        int m_healthMax;
//////        T m_health;
//////
//////    public:
//////        CharacterTpl(const char* name, int healthMax)
//////            : Character(name), m_healthMax(healthMax), m_health(static_cast<T>(healthMax)) {}
//////
//////        void takeDamage(int dmg) override {
//////            // Reduce current health; ensure T can handle this operation
//////            m_health -= static_cast<T>(dmg);
//////
//////            if (m_health <= 0) {
//////                std::cout << getName() << " has been defeated!" << std::endl;
//////                m_health = 0;
//////            }
//////            else {
//////                std::cout << getName() << " took " << dmg
//////                    << " damage, " << getHealth()
//////                    << " health remaining." << std::endl;
//////            }
//////        }
//////
//////        int getHealth() const override {
//////
//////            // Ensure T can be converted to int safely
//////            return static_cast<T>(m_health);
//////        }
//////
//////        int getHealthMax() const override {
//////            return m_healthMax;
//////        }
//////
//////        void setHealth(int health) override {
//////            // Ensure T can handle this operation
//////            m_health = static_cast<T>(health);
//////        }
//////
//////        void setHealthMax(int health) override {
//////            m_healthMax = health;
//////            m_health = static_cast<T>(health);
//////        }
//////
//////        // Uncomment and implement as needed
//////        
//////        int getAttackAmnt() const override {
//////            return 10; // Example attack amount
//////        }
//////
//////        int getDefenseAmnt() const override {
//////            return 5; // Example defense amount
//////        }
//////
//////        Character* clone() const override {
//////            return new CharacterTpl<T>(*this);
//////        }
//////
//////        void attack(Character* enemy) override {
//////            std::cout << getName() << " attacks " << enemy->getName() << "!" << std::endl;
//////            enemy->takeDamage(getAttackAmnt());
//////        }
//////        
//////    };
//////
//////} // namespace seneca
//////
//////#endif // SENECA_CHARACTERTPL_H
