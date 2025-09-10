/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/26/2024
*/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include <string>
#include <iostream>
#include <sstream>

namespace seneca
{
	class Utilities 
	{
		/// <summary>
		/// Specifies lenght of the token extracted (Used for displaying purposes)
		/// </summary>
		size_t m_widthField{};
	public:
		/// <summary>
		/// Separates the token based on a delim value (All util objs share the same delim val)
		/// </summary>
		static char m_delimiter;

		/// <summary>
		/// gets rid of leading and ending spaces
		/// </summary>
		/// <param name="str">str that needs trimming</param>
		static void trim(std::string& str);
		
		/// <summary>
		/// sets m_widthField to param
		/// </summary>
		/// <param name="newWidth">width</param>
		void setFieldWidth(size_t newWidth);

		/// <summary>
		/// gets m_widthField
		/// </summary>
		/// <returns>m_widthField</returns>
		size_t getFieldWidth() const;

		/// <summary>
		/// extracts token from str 
		/// </summary>
		/// <param name="str">data to be extracted</param>
		/// <param name="next_pos">starting pos of str</param>
		/// <param name="more">bool that is only set to true when token is extracted succesfully (else false)</param>
		/// <returns></returns>
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		
		/// <summary>
		/// sets the delim
		/// </summary>
		/// <param name="newDelimiter">new delim val</param>
		static void setDelimiter(char newDelimiter);

		/// <summary>
		/// returns a copy of the delim
		/// </summary>
		static char getDelimiter();
	};
}

#endif // !SENECA_UTILITIES_H
