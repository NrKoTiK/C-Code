/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 10/13/2024
*/

#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include <string>
#include "character.h"

namespace seneca 
{
	class Guild 
	{
		int m_CharCnt{};
		Character** m_colChars{};
		std::string m_teamName{};

	public:
		Guild() = default;

		Guild(const char* name);

		Guild(const Guild& copyOf_G);

		Guild& operator=(const Guild& copyOf_G);

		Guild(Guild&& copyOf_G) noexcept;

		Guild& operator=(Guild&& copyOf_G) noexcept;

		~Guild();

		void addMember(Character* c);

		void removeMember(const std::string& c);

		Character* operator[](size_t idx) const;

		void showMembers() const;
	};

}

#endif // !SENECA_GUILD_H
