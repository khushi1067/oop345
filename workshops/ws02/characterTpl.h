


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
        int m_healthMax{}; // Maximum health
        T m_health{};      // Current health

    public:
        // Constructor to initialize character name and maximum health
        CharacterTpl(const char* name, int healthMax)
            : Character(name) {

            m_healthMax = healthMax;
            m_health = healthMax;
        }

        // Reduces the current health by the damage amount
        void takeDamage(int dmg) override {
            m_health -= dmg;
            if (m_health <= 0) {
                m_health = 0;
                std::cout << "    " << getName() << " has been defeated!" << std::endl;
            }
            else {
                std::cout << "    " << getName() << " took " << dmg
                    << " damage, " << getHealth()
                    << " health remaining." << std::endl;
            }
        }

        // Returns current health, assuming T can be cast to int
        int getHealth() const override {
            /*return (m_health);*/
            return static_cast<int>(m_health);
        }

        // Returns maximum health
        int getHealthMax() const override {
            return m_healthMax;
        }

        // Sets the current health, assuming T can accept an int assignment
        void setHealth(int health) override {
            m_health = (health);
            // Ensure health doesn't go below 0
           /* if (m_health < 0) {
                m_health = static_cast<int>(0);
            }*/
        }

        // Sets the maximum health and resets current health
        void setHealthMax(int health) override {
            m_healthMax = health;
            m_health = m_healthMax;

            //setHealth(health); // Reset current health to the new maximum
        }
    };

} // namespace seneca

#endif // SENECA_CHARACTERTPL_H

