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
	Ability::Ability()
	{
		m_ability[0] = '\0';
		m_abltyStrngth = 0;
	}
	seneca::Ability::Ability(const char* abilityName, int abltyStrngth)
	{
		m_abltyStrngth = abltyStrngth;
		if (abilityName != nullptr && abilityName[0] != '\0') 
		{
			strcpy(m_ability, abilityName);
		}
	}
	const char* Ability::getAbility() const
	{
		return m_ability;
	}
	int Ability::getAbltyStr() const
	{
		return m_abltyStrngth;
	}
}