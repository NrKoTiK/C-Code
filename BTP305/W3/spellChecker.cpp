/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#include "spellChecker.h"
namespace seneca 
{
	int SpellChecker::m_cnt[6] = { 0,0,0,0,0,0 };
	SpellChecker::SpellChecker(const char* filename)
	{
		/*
			teh          the
			modiffied    modified
			begim        begin
			famillies    families
			Dork         Dark
			hibrid       hybrid
		*/
		std::fstream file(filename, std::ios::in);
		if (file.is_open()) 
		{
			file.seekg(std::ios::beg);
			int i = 0;
			while (!file.eof() && i < 6)
			{
				std::getline(file, m_badWords[i], ' ');
				while (file.peek() == ' ') 
				{
					file.ignore();
				}
				std::getline(file, m_goodWords[i], '\n');
				++i;
			}
		}
		else 
		{
			std::cout << "Bad file name!\n";
		}
		file.close();
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; ++i) 
		{
			size_t pos = 0;
			while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) 
			{
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				pos += m_goodWords[i].length();
				++m_cnt[i];
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (int i = 0; i < 6; ++i) 
		{
			out << std::setw(15) << m_badWords[i] << ": " << m_cnt[i] << " replacements\n";
		}
	}
}
