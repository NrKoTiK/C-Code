/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include <string>
#include "character.h"


namespace seneca 
{
	class Team 
	{
		/// <summary>
		/// Count of Characters.
		/// </summary>
		int m_CharCnt{};

		/// <summary>
		/// Dynamic Array that manages collections of pointers of type Characters
		/// </summary>
		Character** m_ColChars{};
		std::string m_teamName{};
	public:

		Team() = default;

		Team(const char* name);

		Team(const Team& copyOf_T);

		Team& operator=(const Team& copyOf_T);

		Team(Team&& copyOf_T) noexcept;

		Team& operator=(Team&& copyOf_T) noexcept;

		~Team();

		void addMember(const Character* c);

		void removeMember(const std::string& c);

		Character* operator[](size_t idx) const;

		void showMembers() const;
	};
}

#endif // !SENECA_TEAM_H
