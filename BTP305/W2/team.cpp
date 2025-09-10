/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#include <iostream>
#include "team.h"

namespace seneca 
{
	Team::Team(const char* name) : m_teamName{ name }
	{
		m_ColChars = nullptr;
		m_CharCnt = 0;
	}
	Team::Team(const Team& copyOf_T) 
	{
		*this = copyOf_T;
	}
	Team& Team::operator=(const Team& copyOf_T)
	{
		if (this != &copyOf_T) 
		{
			for (int i = 0; i < m_CharCnt; ++i) 
			{
				delete m_ColChars[i];
			}
			delete[] m_ColChars;
			m_CharCnt = copyOf_T.m_CharCnt;
			m_teamName = copyOf_T.m_teamName;

			if (copyOf_T.m_ColChars != nullptr) 
			{
				m_ColChars = new Character*[copyOf_T.m_CharCnt];
				for (auto i = 0; i < m_CharCnt; ++i) 
				{
					m_ColChars[i] = copyOf_T.m_ColChars[i]->clone();
				}
			}
			else 
			{
				m_ColChars = nullptr;
			}
		}
		return *this;
	}
	Team::Team(Team&& copyOf_T) noexcept
	{
		*this = std::move(copyOf_T);
	}
	Team& Team::operator=(Team&& copyOf_T) noexcept
	{
		if (this != &copyOf_T) 
		{
			// Loop to dealloc all the pointers in the array.
			for (auto i = 0; i < m_CharCnt; ++i)
			{
				delete m_ColChars[i];
			}
			delete[] m_ColChars;

			m_CharCnt = copyOf_T.m_CharCnt;
			m_teamName = copyOf_T.m_teamName;

			m_ColChars = copyOf_T.m_ColChars;
			copyOf_T.m_ColChars = nullptr;
			copyOf_T.m_CharCnt = 0;
			copyOf_T.m_teamName = {};
		}
		return *this;
	}
	Team::~Team()
	{
		for (auto i = 0; i < m_CharCnt; ++i) 
		{
			delete m_ColChars[i];
		}
		delete[] m_ColChars;
	}

	void Team::addMember(const Character* c)
	{
		bool found = false;
		for (int i = 0; i < m_CharCnt && found == false; ++i) 
		{
			if (m_ColChars[i]->getName() == c->getName())
			{
				found = true;
			}
		}
		if (found == false) 
		{
			Character** tmpArr = new Character * [m_CharCnt + 1];
			for (auto i = 0; i < m_CharCnt; ++i)
			{
				tmpArr[i] = m_ColChars[i];
			}
			delete[] m_ColChars;
			// Calls clone function to add all the clones of Character as the Character class cant be initialized (abstract class)
			tmpArr[m_CharCnt] = c->clone();
			m_ColChars = tmpArr;
			++m_CharCnt;
		}
	}
	void Team::removeMember(const std::string& c)
	{
		// Index that needs to be removed. Assigned to -1 to ensure that if no name match found then we can exit safely.
		int indexR = -1;
		bool found = false;
		for (auto i = 0; i < m_CharCnt && found == false; ++i) 
		{
			if (m_ColChars[i]->getName() == c) 
			{
				indexR = i;
				found = true;;
			}
		}
		if (found == true) 
		{
			delete m_ColChars[indexR];

			// This loop starts at the index where the character was removed from and shifts the entire array to fill that gap.
			for (auto i = indexR; i < m_CharCnt - 1; ++i)
			{
				m_ColChars[i] = m_ColChars[i + 1];
			}
			--m_CharCnt;
		}
	}
	Character* Team::operator[](size_t idx) const
	{
		if (idx < static_cast<size_t>(m_CharCnt)) 
		{
			return m_ColChars[idx];
		}
		else 
		{
			return nullptr;
		}
	}
	void Team::showMembers() const
	{
		int cnt = 0;
		if (m_teamName.empty())
		{
			std::cout << "No team." << std::endl;
		}
		else 
		{
			std::cout << "[Team] " << m_teamName << std::endl;
			for (int i = 0; i < m_CharCnt; ++i)
			{
				std::cout << "    " << ++cnt << ": " << *m_ColChars[i] << std::endl;
			}
		}
	}
}
