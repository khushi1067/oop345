////#pragma once
////#include "characterTpl.h"
////#include "dagger.h"
////#include <iostream>
////
////namespace seneca {
////
////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
////    class Rogue : public CharacterTpl<T> {
////
////    private:
////        int m_baseDefense;
////        int m_baseAttack;
////        FirstAbility_t m_firstAbility;
////        SecondAbility_t m_secondAbility;
////        seneca::Dagger m_weapon; // Rogue always uses a dagger
////
////    public:
////        // Constructor to initialize the Rogue with name, max health, base attack, and defense
////        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
////            : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapon() {}
////
////        // Calculates the total attack amount including weapon damage
////        int getAttackAmnt() const {
////            return m_baseAttack + static_cast<int>(2 * static_cast<double>(m_weapon));
////        }
////
////        // Returns the base defense amount
////        int getDefenseAmnt() const {
////            return m_baseDefense;
////        }
////
////        // Clones the current Rogue instance
////        Character* clone() const override {
////            return new Rogue(*this);
////        }
////
////        // Attack method to inflict damage on an enemy
////        void attack(Character* enemy) override {
////            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
////
////            // Use both abilities on self
////            m_firstAbility.useAbility(this);
////            m_secondAbility.useAbility(this);
////
////            // Calculate damage and enhance it with abilities
////            int damage = getAttackAmnt();
////            m_firstAbility.transformDamageDealt(damage);
////            m_secondAbility.transformDamageDealt(damage);
////
////            std::cout << "    Rogue deals " << damage << " melee damage!" << std::endl;
////
////            // Apply damage to the enemy
////            enemy->takeDamage(damage);
////        }
////
////        // Takes damage with the Rogue's defense and abilities reducing it
////        void takeDamage(int dmg) override {
////            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
////            std::cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
////
////            // Apply base defense reduction
////            dmg -= m_baseDefense;
////            if (dmg < 0) dmg = 0;
////
////            // Use both abilities to reduce damage taken
////            m_firstAbility.transformDamageReceived(dmg);
////            m_secondAbility.transformDamageReceived(dmg);
////
////            // Apply the reduced damage to health
////            CharacterTpl<T>::takeDamage(dmg);
////        }
////    };
////
////} // namespace seneca
////
////
//////#include "Rogue.h"
//////
//////#include "CharacterTpl.h"
//////#include "abilities.h"
//////#include "weapons.h"
//////#include <iostream>
//////
//////namespace seneca {
//////
//////    // Constructor to initialize the Rogue with specific attributes
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
//////        : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {}
//////
//////
//////    // Returns the base attack amount
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
//////        return m_baseAttack;
//////    }
//////
//////    // Returns the base defense amount
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
//////        return m_baseDefense;
//////    }
//////
//////    // Creates a copy of the Rogue instance
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
//////        return new Rogue(*this);
//////    }
//////
//////    // Attacks an enemy character
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
//////        // Print attack message
//////        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
//////
//////        // Use abilities
//////        m_firstAbility.useAbility(this);
//////        m_secondAbility.useAbility(this);
//////
//////        // Get the attack amount and modify it using abilities
//////        int damage = getAttackAmnt();
//////        m_firstAbility.transformDamageDealt(damage);
//////        m_secondAbility.transformDamageDealt(damage);
//////
//////        // Print damage dealt
//////        std::cout << "    Rogue deals " << damage << " damage!" << std::endl;
//////
//////        // Inflict damage on the enemy
//////        enemy->takeDamage(damage);
//////    }
//////
//////    // Takes damage, modified by the Rogue's defense and special abilities
//////    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//////    void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
//////        // Print incoming attack message
//////        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
//////        std::cout << "    Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
//////
//////        // Calculate modified damage with defense
//////        dmg = std::max(0, dmg - getDefenseAmnt());
//////
//////        // Modify damage with abilities
//////        m_firstAbility.transformDamageReceived(dmg);
//////        m_secondAbility.transformDamageReceived(dmg);
//////
//////        // Pass modified damage to base class
//////        CharacterTpl<T>::takeDamage(dmg);
//////    }
//////
//////}  // namespace seneca
//
//
//#ifndef SENECA_ROGUE_H
//#define SENECA_ROGUE_H
//
//#include "characterTpl.h"
//#include "character.h"
//#include "weapons.h"
//#include <iostream>
//
//namespace seneca {
//
//	template <typename T, typename FirstAbility_t, typename SecondAbility_t>
//	class Rogue : public characterTpl<T> {
//	private:
//		int m_baseDefense;
//		int m_baseAttack;
//		FirstAbility_t m_firstAbility;
//		SecondAbility_t m_secondAbility;
//		seneca::Dagger m_weapon;
//
//	public:
//		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) :
//
//			characterTpl<T>(name, healthMax) {
//			m_baseAttack = baseAttack;
//			m_baseDefense = baseDefense;
//		}
//
//		int getAttackAmnt() const {
//			return m_baseAttack + 2 * static_cast<int>(m_weapon);
//
//		}
//		int getDefenseAmnt() const {
//			return m_baseDefense;
//		}
//		Character* clone() const {
//			return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
//		}
//		void attack(Character* enemy) {
//			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
//			m_firstAbility.useAbility(this);
//			m_secondAbility.useAbility(this);
//			int damage = getAttackAmnt();
//			m_firstAbility.transformDamageDealt(damage);
//			m_secondAbility.transformDamageDealt(damage);
//			std::cout << "    Rogue deals " << damage << " melee damage!" << std::endl;
//			enemy->takeDamage(damage);
//		}
//
//
//		void takeDamage(int dmg) {
//			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
//			std::cout << "    Rogue has a defense of " << getDefenseAmnt()
//				<< ". Reducing damage received." << std::endl;
//
//			dmg -= getDefenseAmnt();
//			if (dmg < 0) {
//				dmg = 0;
//			}
//
//			m_firstAbility.transformDamageReceived(dmg);
//			m_secondAbility.transformDamageReceived(dmg);
//			characterTpl<T>::takeDamage(dmg);
//		}
//
//
//
//	};
//
//
//
//
//}
//
//
//
//#endif