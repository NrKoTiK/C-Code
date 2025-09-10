/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#include "guild.h"

namespace seneca 
{
	Guild::Guild(const char* name)
	{
		m_colChars = nullptr;
		m_CharCnt = 0;
		m_teamName = name;
	}
	Guild::Guild(const Guild& copyOf_G)
	{
		*this = copyOf_G;
	}
	Guild& Guild::operator=(const Guild& copyOf_G)
	{
		if (this != &copyOf_G)
		{
			delete[] m_colChars;
			m_CharCnt = copyOf_G.m_CharCnt;
			m_teamName = copyOf_G.m_teamName;
			if (copyOf_G.m_colChars != nullptr) 
			{
				m_colChars = new Character * [copyOf_G.m_CharCnt];

				for (auto i = 0; i < m_CharCnt; ++i)
				{
					m_colChars[i] = copyOf_G.m_colChars[i];
				}
			}
			else 
			{
				m_colChars = nullptr;
			}
		}
		return *this;
	}
	Guild::Guild(Guild&& copyOf_G) noexcept
	{
		m_colChars = nullptr;
		*this = std::move(copyOf_G);
	}
	Guild& Guild::operator=(Guild&& copyOf_G) noexcept
	{
		if (this != &copyOf_G)
		{
			delete[] m_colChars;

			m_CharCnt = copyOf_G.m_CharCnt;
			m_teamName = copyOf_G.m_teamName;

			m_colChars = copyOf_G.m_colChars;
			copyOf_G.m_colChars = nullptr;
			copyOf_G.m_CharCnt = 0;
			copyOf_G.m_teamName = {};
		}
		return *this;
	}
	Guild::~Guild()
	{
		delete[] m_colChars;
	}
	void Guild::addMember(Character* c)
	{
		bool found = false;
		for (int i = 0; i < m_CharCnt && found == false; ++i)
		{
			if (m_colChars[i]->getName() == c->getName())
			{
				found = true;
			}
		}
		if (found == false)
		{
			Character** tmpArr = new Character * [m_CharCnt + 1];
			for (auto i = 0; i < m_CharCnt; ++i)
			{
				tmpArr[i] = m_colChars[i];
			}
			delete[] m_colChars;
			tmpArr[m_CharCnt] = c;
			tmpArr[m_CharCnt]->setHealthMax(tmpArr[m_CharCnt]->getHealthMax() + 300);
			m_colChars = tmpArr;
			++m_CharCnt;
		}
	}
	void Guild::removeMember(const std::string& c)
	{
		int indexR = -1;
		bool found = false;
		for (auto i = 0; i < m_CharCnt && found == false; ++i)
		{
			if (m_colChars[i]->getName() == c)
			{
				indexR = i;
				found = true;
			}
		}
		if (found == true) 
		{
			Character** tmpArr = new Character * [m_CharCnt - 1];
			for (auto i = 0; i < indexR; ++i)
			{
				tmpArr[i] = m_colChars[i];
			}
			for (auto i = indexR + 1; i < m_CharCnt; ++i)
			{
				tmpArr[i - 1] = m_colChars[i];
			}
			m_colChars[indexR]->setHealthMax(m_colChars[indexR]->getHealthMax() - 300);
			delete[] m_colChars;
			m_colChars = tmpArr;
			--m_CharCnt;
		}
	}
	Character* Guild::operator[](size_t idx) const
	{
		if (idx < static_cast<size_t>(m_CharCnt))
		{
			return m_colChars[idx];
		}
		else
		{
			return nullptr;
		}
	}
	void Guild::showMembers() const
	{
		int cnt = 0;
		if (m_teamName.empty())
		{
			std::cout << "No guild." << std::endl;
		}
		else
		{
			std::cout << "[Guild] " << m_teamName << std::endl;
			for (int i = 0; i < m_CharCnt; ++i)
			{
				std::cout << "    " << ++cnt << ": " << *m_colChars[i] << std::endl;
			}
		}
	}
}



