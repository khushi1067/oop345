//#include "archer.h"
//#include "characterTpl.h"
//#include "weapons.h"
//
//#include <iomanip>
//#include <iostream>
//namespace seneca {
//
//    // Constructor initializing the Archer with provided values
//    template <typename Weapon_t>
//    Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
//        : CharacterTpl<seneca::SuperHealth>(name, healthMax),
//        m_baseAttack(baseAttack),
//        m_baseDefense(baseDefense),
//        m_weapon(weapon) {}
//
//    // Get the attack amount with enhanced damage
//    template <typename Weapon_t>
//    int Archer<Weapon_t>::getAttackAmnt() const {
//        return static_cast<int>(1.3 * m_baseAttack);
//    }
//
//    // Get the defense amount with enhanced defense
//    template <typename Weapon_t>
//    int Archer<Weapon_t>::getDefenseAmnt() const {
//        return static_cast<int>(1.2 * m_baseDefense);
//    }
//
//    // Clone the current Archer object
//    template <typename Weapon_t>
//    Character* Archer<Weapon_t>::clone() const {
//        return new Archer(*this);
//    }
//
//    // Attack the enemy and inflict damage
//    template <typename Weapon_t>
//    void Archer<Weapon_t>::attack(Character* enemy) {
//        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
//        int damage = getAttackAmnt();
//        std::cout << "    Archer deals " << damage << " ranged damage!" << std::endl;
//        enemy->takeDamage(damage);
//    }
//
//    // Take damage, reducing by defense before updating health
//    template <typename Weapon_t>
//    void Archer<Weapon_t>::takeDamage(int dmg) {
//        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
//        std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
//        dmg = std::max(0, dmg - getDefenseAmnt());
//        CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
//    }
//
//}  // namespace seneca
//
//
////#include "archer.h"
////#include "weapons.h"
////
////#include <iostream>
////
////namespace seneca {
////
////    template <typename Weapon_t>
////    Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
////        : CharacterTpl<seneca::SuperHealth>(name, healthMax),
////        m_baseAttack(baseAttack),
////        m_baseDefense(baseDefense),
////        m_weapon(weapon) {}
////
////    int Archer<Weapon_t>::getAttackAmnt() const {
////        return static_cast<int>(1.3 * m_baseAttack);
////    }
////
////    int Archer<Weapon_t>::getDefenseAmnt() const {
////        return static_cast<int>(1.2 * m_baseDefense);
////    }
////
////    Character* Archer<Weapon_t>::clone() const {
////        return new Archer(*this);
////    }
////
////    void Archer<Weapon_t>::attack(Character* enemy) {
////        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
////        int damage = getAttackAmnt();
////        std::cout << "    Archer deals " << damage << " ranged damage!" << std::endl;
////        enemy->takeDamage(damage);
////    }
////
////    void Archer<Weapon_t>::takeDamage(int dmg) {
////        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
////        std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
////        dmg = std::max(0, dmg - getDefenseAmnt());
////        CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
////    }
////
////}  // namespace seneca
