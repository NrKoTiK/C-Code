/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <string>


namespace seneca 
{
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};	

	class Dictionary 
	{
		/// <summary>
		/// Collection of words (m_word)
		/// </summary>
		Word* m_Collword;

		size_t m_Colcnt;

	public:
		Dictionary();

		Dictionary(const char* filename);

		~Dictionary();
		
		Dictionary(const Dictionary& copy_OfD);
		
		Dictionary& operator=(const Dictionary& copy_OfD);

		Dictionary(Dictionary&& copy_OfD);

		Dictionary& operator=(Dictionary&& copy_OfD);

		void searchWord(const char* word);
	};

}

#endif // !SENECA_DICTIONARY_H

