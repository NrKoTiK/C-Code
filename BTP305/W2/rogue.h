/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"

namespace seneca 
{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		SecondAbility_t m_secondAbility;
		seneca::Dagger m_weapon;

	public:

		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);

		int getAttackAmnt() const override;

		int getDefenseAmnt() const override;

		Character* clone() const override;

		void attack(Character* enemy) override;

		void takeDamage(int dmg) override;
	
	};

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) : CharacterTpl<T>(name, healthMax)
	{
		m_baseAttack = baseAttack;
		m_baseDefense = baseDefense;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const
	{
		double maxDmg = static_cast<double>(m_baseAttack) + 2.0 * static_cast<double>(m_weapon);
		return static_cast<int>(maxDmg);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const
	{
		return m_baseDefense;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const
	{
		return new Rogue(*this);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy)
	{
		std::cout << Character::getName() << " is attacking " << enemy->getName() << ".\n";
		m_firstAbility.useAbility(this);
		m_secondAbility.useAbility(this);
		int dmgDonebyChar = this->getAttackAmnt();
		m_firstAbility.transformDamageDealt(dmgDonebyChar);
		m_secondAbility.transformDamageDealt(dmgDonebyChar);
		std::cout << "    Rogue deals " << dmgDonebyChar << " melee damage!\n";
		enemy->takeDamage(dmgDonebyChar);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg)
	{
		std::cout << Character::getName() << " is attacked for " << dmg << " damage.\n";
		std::cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage recieved.\n";
		if (dmg <= 0)
		{
			dmg = 0;
		}
		else
		{
			dmg -= m_baseDefense;
		}
		m_firstAbility.transformDamageReceived(dmg);
		m_secondAbility.transformDamageReceived(dmg);
		CharacterTpl<T>::takeDamage(dmg);
	}
}


#endif // !SENECA_ROGUE_H
