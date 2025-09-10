/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/26/2024
*/
#include "Utilities.h"

namespace seneca 
{
	char Utilities::m_delimiter = {};

	void Utilities::trim(std::string& str)
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string rs{};
		/// If cant find then set to std::string::npos
		size_t delimiter_pos = str.find(m_delimiter, next_pos);
		if (next_pos >= str.length()) 
		{
			more = false; 
			throw more;
		}
		else if (next_pos == delimiter_pos) 
		{
			more = false;
			throw more;
		}
		else if (delimiter_pos == std::string::npos)
		{
			rs = str.substr(next_pos);
			next_pos = str.length();
			more = false;
		}
		else 
		{	
			rs = str.substr(next_pos, delimiter_pos - next_pos);
			next_pos = delimiter_pos + 1; 
			more = true;
		}
		trim(rs);
		m_widthField = (rs.length() > m_widthField) ? rs.length() : m_widthField;
		return rs;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}