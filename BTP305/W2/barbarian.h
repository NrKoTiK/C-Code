/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"


namespace seneca
{
	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt = 2>
	class Barbarian : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		
		/// <summary>
		/// Should be a Ability_t Type.
		/// </summary>
		Ablity_t m_ability;

		/// <summary>
		/// This should be a Weapon_t type.
		/// </summary>
		Weapon_t m_weapon[wCnt];

	public:

		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);

		int getAttackAmnt() const override;

		int getDefenseAmnt() const override;

		Character* clone() const override;

		void attack(Character* enemy) override;

		void takeDamage(int dmg) override;
	};

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline Barbarian<T, Ablity_t, Weapon_t, wCnt>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) : CharacterTpl<T>(name, healthMax)
	{
		m_baseDefense = baseDefense;
		m_baseAttack = baseAttack;
		m_ability = {};
		m_weapon[0] = primaryWeapon;
		m_weapon[1] = secondaryWeapon;
	}

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline int Barbarian<T, Ablity_t, Weapon_t, wCnt>::getAttackAmnt() const
	{	
		double maxDmg = static_cast<double>(m_baseAttack) + (static_cast<double>(m_weapon[0]) / 2) + (static_cast<double>(m_weapon[1]) / 2);
		return static_cast<int>(maxDmg);
	}

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline int Barbarian<T, Ablity_t, Weapon_t, wCnt>::getDefenseAmnt() const
	{
		return m_baseDefense;
	}

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline Character* Barbarian<T, Ablity_t, Weapon_t, wCnt>::clone() const
	{
		return new Barbarian(*this);
	}

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline void Barbarian<T, Ablity_t, Weapon_t, wCnt>::attack(Character* enemy)
	{
		std::cout << this->getName() << " is attacking " << enemy->getName() << ".\n";
		m_ability.useAbility(this);
		int dmgDoneByChar = this->getAttackAmnt();
		m_ability.transformDamageDealt(dmgDoneByChar);
		std::cout << "    Barbarian deals " << dmgDoneByChar << " melee damage!\n";
		enemy->takeDamage(dmgDoneByChar);
	}

	template<typename T, typename Ablity_t, typename Weapon_t, int wCnt>
	inline void Barbarian<T, Ablity_t, Weapon_t, wCnt>::takeDamage(int dmg)
	{
		std::cout << this->getName() << " is attacked for " << dmg << " damage.\n";
		std::cout << "    Barbarian has a defense of " << m_baseDefense << ". Reducing damage received.\n";
		if (dmg < 0) 
		{
			dmg = 0;
		}
		else 
		{
			dmg -= m_baseDefense;	
		}
		m_ability.transformDamageReceived(dmg);
		CharacterTpl<T>::takeDamage(dmg);
	}
}
#endif // !SENECA_BARBARIAN_H
