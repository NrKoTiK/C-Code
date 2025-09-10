/*
NAME: Ahmad Syed
STUDENTID: 102437233
EMAIL: asyed113@myseneca.ca
WORKSHOP 5 PART 1
DATE: 2/19/2024
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "hero.h"
#include "ability.h"

namespace seneca 
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_abilities = nullptr;
		m_cntAbilities = 0;
		m_level = 1;
	}
	Hero::Hero(const char* name, const Ability* abilities, int cntAbilities)
	{
		if (name != nullptr && name[0] != '\0') 
		{
			strcpy(m_name, name);
		}
		if (cntAbilities > 0) 
		{
			m_cntAbilities = cntAbilities;
			m_abilities = new Ability[m_cntAbilities];
			for (int i = 0; i < m_cntAbilities; ++i) 
			{
				m_abilities[i] = abilities[i];
			}
			m_level = 1;
		}
	}
	Hero::~Hero()
	{
		if (m_abilities != nullptr)
		{
			delete[] m_abilities;
		}
		m_name[0] = '\0';
		m_cntAbilities = 0;
		m_level = 1;
	}
	Hero::operator const char* () const
	{
		return m_name;
	}
	Hero::operator int() const
	{
		int totalStrngth = 0;
		int sumOfAbility = 0;
		for (int i = 0; i < m_cntAbilities; ++i) 
		{
			sumOfAbility += m_abilities[i].getAbltyStr();
		}
		return totalStrngth = sumOfAbility * m_level;
	}
	Hero& Hero::operator+=(const Ability& ability)
	{
		Ability* tmp = new Ability[m_cntAbilities + 1];
		for (int i = 0; i < m_cntAbilities; ++i) 
		{
			tmp[i] = m_abilities[i];
		}
		delete[] m_abilities;
		tmp[m_cntAbilities] = ability;
		m_abilities = tmp;
		++m_cntAbilities;
		return *this;
	}
	Hero& Hero::operator+=(int lvlChange)
	{
		if (lvlChange < 0) 
		{
			if (m_level + lvlChange <= 1) 
			{
				m_level = 1;
				return *this;
			}
			else 
			{
				m_level += lvlChange;
			}
		}
		else 
		{
			m_level += lvlChange;
		}
		return *this;
	}
	Hero& Hero::operator++()
	{
		++m_level;
		return *this;
	}
	void Hero::display() const
	{
		std::cout << m_name << " (lvl: " << m_level << ", str: " << operator int() << ')' << std::endl;
		for (int i = 0; i < m_cntAbilities; ++i) 
		{
			std::cout << "  - " << m_abilities[i].getAbility() << " (" << m_abilities[i].getAbltyStr() << ")" << std::endl;
		}
	}

	bool operator<(const Hero& h1, const Hero& h2)
	{
		return h1.operator int() < h2.operator int();
	}
	bool operator>(const Hero& h1, const Hero& h2)
	{
		return h1.operator int() > h2.operator int();
	}
	void operator>>(const Ability& ability, Hero& hero)
	{
		hero += ability;
	}
	void operator<<(Hero& hero, const Ability& ability)
	{
		hero += ability;
	}
}