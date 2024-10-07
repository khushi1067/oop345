#include "Rogue.h"

#include "CharacterTpl.h"
#include "abilities.h"
#include "weapons.h"
#include <iostream>

namespace seneca {

    // Constructor to initialize the Rogue with specific attributes
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
        : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {}


    // Returns the base attack amount
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
        return m_baseAttack;
    }

    // Returns the base defense amount
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
        return m_baseDefense;
    }

    // Creates a copy of the Rogue instance
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
        return new Rogue(*this);
    }

    // Attacks an enemy character
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
        // Print attack message
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
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
        // Print incoming attack message
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

}  // namespace seneca
