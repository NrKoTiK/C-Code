/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"

namespace seneca 
{
	template<typename T>
	class CharacterTpl : public Character 
	{
		int m_healthMax;
		T m_health;

	public:

		CharacterTpl(const char* name, int maxHealth);

		void takeDamage(int dmg) override;

		int getHealth() const override;

		int getHealthMax() const override;

		void setHealth(int health) override;

		void setHealthMax(int health) override;
	};

	template<typename T>
	inline CharacterTpl<T>::CharacterTpl(const char* name, int maxHealth) : Character(name)
	{
		m_health = maxHealth;
		m_healthMax = maxHealth;
	}
	template<typename T>
	inline void CharacterTpl<T>::takeDamage(int dmg)
	{
		m_health -= dmg;
		if (m_health <= 0)
		{
			m_health = 0;
			std::cout << "    " << this->getName() << " has been defeated!\n";
		}
		else
		{
			std::cout << "    " << this->getName() << " took " << dmg << " damage, " << m_health << " health remaining.\n";
		}
	}
	template<typename T>
	inline int CharacterTpl<T>::getHealth() const
	{
		return static_cast<int>(m_health);
	}
	template<typename T>
	inline int CharacterTpl<T>::getHealthMax() const
	{
		return m_healthMax;
	}
	template<typename T>
	inline void CharacterTpl<T>::setHealth(int health)
	{
		m_health = health;
	}
	template<typename T>
	inline void CharacterTpl<T>::setHealthMax(int health)
	{
		m_healthMax = health;
		m_health = health;
	}
}

#endif // !SENECA_CHARACTERTPL_H
