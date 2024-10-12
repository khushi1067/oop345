//#include "Barbarian.h"
//
//
//#include "characterTpl.h"
//#include "weapons.h"
//#include <iostream>
//#include <iomanip>
//
//
//namespace seneca {
//
//    // Constructor to initialize the Barbarian with specific attributes
//    template <typename T, typename Ability_t, typename Weapon_t>
//   /* Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
//        Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
//        : CharacterTpl<T>(name, healthMax),
//        m_baseAttack(baseAttack),
//        m_baseDefense(baseDefense) {
//        m_weapon[0] = primaryWeapon;
//        m_weapon[1] = secondaryWeapon;
//    }*/
//
//    // Returns the attack amount with weapon enhancements
//    template <typename T, typename Ability_t, typename Weapon_t>
//  /*  int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
//        return m_baseAttack + static_cast<int>(m_weapon[0]) / 2 + static_cast<int>(m_weapon[1]) / 2;
//    }*/
//
//    // Returns the defense amount
//    template <typename T, typename Ability_t, typename Weapon_t>
//    int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
//        return m_baseDefense;
//    }
//
//    // Creates a clone of the Barbarian instance
//    template <typename T, typename Ability_t, typename Weapon_t>
//    Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
//        return new Barbarian(*this);
//    }
//
//    // Attacks an enemy character
//    template <typename T, typename Ability_t, typename Weapon_t>
//    void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
//        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
//
//        // Use the special ability of the Barbarian
//        m_ability.useAbility(this);
//
//        int damage = getAttackAmnt();
//        m_ability.transformDamageDealt(damage);
//
//        std::cout << "    Barbarian deals " << damage << " melee damage!" << std::endl;
//        enemy->takeDamage(damage);
//    }
//
//    // Takes damage, modified by the Barbarian's defense and special ability
//    template <typename T, typename Ability_t, typename Weapon_t>
//    void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
//        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
//        std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
//
//        dmg -= getDefenseAmnt();
//        if (dmg < 0) {
//            dmg = 0;
//        }
//
//        m_ability.transformDamageReceived(dmg);
//        CharacterTpl<T>::takeDamage(dmg);
//    }
//
//} // namespace seneca
