#include "abilities.h"

namespace seneca
{
	// the ability is activated. The damage done will be increased
	// and the damage received will be reduced.
	void Bersek::useAbility(seneca::Character*)
	{
		--m_cooldown;
		if (m_cooldown <= 0)
		{
			std::cout << "    Bersek is activated for the next 6 seconds. Cooldown is 10 seconds.\n";
			m_activeTime = 6;
			m_cooldown = 10;
		}
	}

	// modifies the damage dealt on others
	void Bersek::transformDamageDealt(int& dmg)
	{
		--m_activeTime;
		if (m_activeTime > 0)
		{
			std::cout << "    Bersek is active; increasing damage dealt from ["
				<< dmg << "] to [" << dmg * 2 << "].\n";
			dmg *= 2;
		}
	}

	// modifies the damage received
	void Bersek::transformDamageReceived(int& dmg)
	{
		--m_activeTime;
		if (m_activeTime > 0)
		{
			std::cout << "    Bersek is active; reducing damage received from ["
				<< dmg << "] to [" << dmg / 2 << "].\n";
			dmg /= 2;
		}
	}

	// fireball doesn't operate on self; do nothing
	void Fireball::useAbility(seneca::Character*)
	{
		// no operation
	}

	// modifies the damage dealt on others
	void Fireball::transformDamageDealt(int& dmg)
	{
		--m_cooldown;
		if (m_cooldown == 0)
		{
			std::cout << "    Fireball has been triggered; increasing damage dealt by 500.\n";
			dmg += 500; // increases damage by 500
			m_cooldown = 20; // cannot be used again for the next 20 turns
		}
	}

	// fireball doesn't change the damage received; do nothing
	void Fireball::transformDamageReceived(int&)
	{
		// no operation
	}

	// heal maxes out the health
	void Heal::useAbility(seneca::Character* src)
	{
		--m_cooldown;
		if (m_cooldown <= 0)
		{
			std::cout << "    Heal is activated; setting health at ["
				<< src->getHealthMax() << "].\n";
			src->setHealth(src->getHealthMax());
			m_cooldown = 10;
		}
	}

	// Heal doesn't change the damage dealt; do nothing
	void Heal::transformDamageDealt(int&)
	{
		// no operation
	}

	// Heal doesn't change the damage received; do nothing
	void Heal::transformDamageReceived(int&)
	{
		// no operation
	}
}
