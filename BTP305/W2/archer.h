/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "weapons.h"
#include "health.h"

namespace seneca
{
	template<typename Weapon_t>
	class Archer : public CharacterTpl<seneca::SuperHealth> 
	{
		int m_baseDefense;
		int m_baseAttack;
		Weapon_t m_weapon;
	
	public:

		Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);

		int getAttackAmnt() const override;

		int getDefenseAmnt() const override;

		Character* clone() const override;

		void attack(Character* enemy) override;

		void takeDamage(int dmg) override;
	};
	
	template<typename Weapon_t>
	inline Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) : CharacterTpl<seneca::SuperHealth>(name, healthMax)
	{
		m_baseAttack = baseAttack;
		m_baseDefense = baseDefense;
		m_weapon = weapon;
	}

	template<typename Weapon_t>
	inline int Archer<Weapon_t>::getAttackAmnt() const
	{
		double maxDmg =  static_cast<double>(m_baseAttack) * 1.3;
		return static_cast<int>(maxDmg);
	}

	template<typename Weapon_t>
	inline int Archer<Weapon_t>::getDefenseAmnt() const
	{
		double defense = static_cast<double>(m_baseDefense) * 1.2;
		return static_cast<int>(defense);
	}

	template<typename Weapon_t>
	inline Character* Archer<Weapon_t>::clone() const
	{
		return new Archer(*this);
	}

	template<typename Weapon_t>
	inline void Archer<Weapon_t>::attack(Character* enemy)
	{
		std::cout << this->getName() << " is attacking " << enemy->getName() << ".\n";
		int dmgDonebyChar = this->getAttackAmnt();
		std::cout << "    Archer deals " << dmgDonebyChar << " ranged damage!\n";
		enemy->takeDamage(dmgDonebyChar);
	}

	template<typename Weapon_t>
	inline void Archer<Weapon_t>::takeDamage(int dmg)
	{
		std::cout << this->getName() << " is attacked for " << dmg << " damage.\n";
		std::cout << "    Archer has a defense of " << m_baseDefense << ". Reducing damage received.\n";
		if (dmg <= 0)
		{
			dmg = 0;
		}
		else 
		{
			dmg -= m_baseDefense;
		}
		CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
	}
}

#endif // !SENECA_ARCHER_H
