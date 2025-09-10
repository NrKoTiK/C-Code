/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "dictionary.h"
#include "settings.h"

namespace seneca 
{
	Dictionary::Dictionary() : m_Collword{}, m_Colcnt{} {	}
	Dictionary::Dictionary(const char* filename)
	{
		std::ifstream fs(filename);
		m_Colcnt = 0;
		m_Collword = nullptr;
		std::string pos{};
		int currCurr = fs.tellg();

		if (fs.is_open())
		{	
			while (!fs.eof())
			{
				fs.ignore(1000000, '\n');
				++m_Colcnt;
			}
			m_Collword = new Word[m_Colcnt + 1];
			
			fs.clear(std::ios::goodbit);
			fs.seekg(currCurr);

			for (size_t i = 0; i < m_Colcnt; ++i) 
			{
				getline(fs, m_Collword[i].m_word, ',');
				getline(fs, pos, ',');
				getline(fs, m_Collword[i].m_definition, '\n');

				if (pos == "n.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Noun;
				}
				else if (pos == "n. pl.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Noun;
				}
				else if (pos == "adv.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Adverb;
				}
				else if (pos == "a.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Adjective;
				}
				else if (pos == "v.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Verb;
				}
				else if (pos == "v. i.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Verb;
				}
				else if (pos == "v. t.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Verb;
				}
				else if (pos == "v. t. & i.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Verb;
				}
				else if (pos == "prep.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Preposition;
				}
				else if (pos == "pron.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Pronoun;
				}
				else if (pos == "conj.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Conjunction;
				}
				else if (pos == "interj.")
				{
					m_Collword[i].m_pos = PartOfSpeech::Interjection;
				}
				else
				{
					m_Collword[i].m_pos = PartOfSpeech::Unknown;
				}
			}
		}
		else 
		{
			return;
		}
		fs.close();
	}

	Dictionary::~Dictionary()
	{
		delete[] m_Collword;
	}
	Dictionary::Dictionary(const Dictionary& copy_OfD)
	{
		m_Collword = nullptr;
		*this = copy_OfD;
	}
	Dictionary& Dictionary::operator=(const Dictionary& copy_OfD)
	{
		if (this != &copy_OfD) 
		{
			delete[] m_Collword;
			m_Colcnt = copy_OfD.m_Colcnt;

			if (copy_OfD.m_Collword != nullptr) 
			{
				m_Collword = new Word[copy_OfD.m_Colcnt];
				for (size_t i = 0; i < copy_OfD.m_Colcnt; ++i) 
				{
					m_Collword[i] = copy_OfD.m_Collword[i];
				}
			}
			else 
			{
				m_Collword = nullptr;
			}
		}
		return *this;
	}
	Dictionary::Dictionary(Dictionary&& copy_OfD)
	{
		m_Collword = nullptr;
		*this = std::move(copy_OfD);
	}
	Dictionary& Dictionary::operator=(Dictionary&& copy_OfD)
	{
		if (this != &copy_OfD)
		{
			delete[] m_Collword;

			m_Colcnt = copy_OfD.m_Colcnt;

			m_Collword = copy_OfD.m_Collword;
			copy_OfD.m_Collword = nullptr;
			copy_OfD.m_Colcnt = 0;
		}
		return *this;
	
	}
	void Dictionary::searchWord(const char* word)
	{
		bool found = false;
		size_t wordLength = strlen(word);
		for (size_t i = 0; i < m_Colcnt; ++i) 
		{
			if (m_Collword[i].m_word == word) 
			{
				if (!found) 
				{
					std::cout << m_Collword[i].m_word;
					found = true;
				}

				//created a std::string object consisting of wordLength spaces and filled it up with ' '.
				else 
				{
					std::cout << std::string(wordLength, ' ');
				}
				if (g_settings.m_verbose && m_Collword[i].m_pos != PartOfSpeech::Unknown) {
					std::cout << " - ";

					switch (m_Collword[i].m_pos)
					{
					case PartOfSpeech::Noun:
						std::cout << "(noun) ";
						break;
					case PartOfSpeech::Pronoun:
						std::cout << "(pronoun) ";
						break;
					case PartOfSpeech::Adjective:
						std::cout << "(adjective) ";
						break;
					case PartOfSpeech::Adverb:
						std::cout << "(adverb) ";
						break;
					case PartOfSpeech::Verb:
						std::cout << "(verb) ";
						break;
					case PartOfSpeech::Preposition:
						std::cout << "(preposition) ";
						break;
					case PartOfSpeech::Conjunction:
						std::cout << "(conjunction) ";
						break;
					case PartOfSpeech::Interjection:
						std::cout << "(interjection) ";
						break;
					default:
						break;
					}
				}
				else 
				{
					std::cout << " - ";
				}
				std::cout << m_Collword[i].m_definition << std::endl;

				if (!g_settings.m_show_all) 
				{
					return;
				}
			}
		}
		if (!found) 
		{
			std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
		}
	}
}
