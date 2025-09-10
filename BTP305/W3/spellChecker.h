/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace seneca 
{
	class SpellChecker 
	{
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		static int m_cnt[6];
	public:
		
		/// <summary>
		/// reads file and store values in the designated arrays
		/// </summary>
		/// <param name="filename">name of file</param>
		SpellChecker(const char* filename);

		/// <summary>
		/// searches parameter and replaces the misspelled word with correct version
		/// Also counts amount of times misspelled word has been replaced 
		/// </summary>
		/// <param name="text">misspelled word</param>
		void operator()(std::string& text);

		/// <summary>
		/// displays how the count of replacement
		/// </summary>
		/// <param name="out"></param>
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SENECA_SPELLCHECKER_H
