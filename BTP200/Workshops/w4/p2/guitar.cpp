//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 2/13/2024

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "guitar.h"
#include "guitarString.h"

using namespace std;
namespace seneca 
{
	Guitar::Guitar(const char* model)
	{
		if(model != nullptr && model[0] != '\0')
		{
			strcpy(m_model, model);
		}
		else 
		{
			m_model[0] = '\0';
		}
		m_strings = nullptr;
		m_cntStrings = 0;
	}
	Guitar::Guitar(const GuitarString* strings, int cntStrings, const char* model) : Guitar(model)
	{
		// *this = Guitar(model);
		if (m_model[0] != '\0' && strings != nullptr)
		{
			m_cntStrings = cntStrings;
			m_strings = new GuitarString[cntStrings];
			for (int i = 0; i < cntStrings; i++) 
			{
				m_strings[i] = strings[i];
			}
		}
	}
	Guitar::~Guitar()
	{
		if (m_strings != nullptr) 
		{
			delete[] m_strings;
			m_strings = nullptr;
		}
		m_model[0] = '\0';
	}
	Guitar& Guitar::reString(const GuitarString* strings, int cntStrings)
	{
		if (m_strings != nullptr) 
		{
			delete[] m_strings;
			m_strings = nullptr;
		}
		m_cntStrings = cntStrings;
		GuitarString* newStringArr = new GuitarString[m_cntStrings];
		for (int i = 0; i < m_cntStrings; ++i) 
		{
			newStringArr[i] = strings[i];
		}
		m_strings = newStringArr;
		return *this;
	}
	Guitar& Guitar::reString(GuitarString& aString, int idx)
	{
		m_strings[idx] = aString;
		return *this;
	}
	Guitar& Guitar::deString()
	{
		if (m_strings != nullptr) 
		{
			delete[] m_strings;
			m_strings = nullptr;
			m_cntStrings = 0;
		}
		return *this;
	}
	bool Guitar::isStrung() const
	{
		bool strungin = false;
		if (m_cntStrings > 0) 
		{
			strungin = true;;
		}
		return strungin;
	}
	std::ostream& Guitar::display(std::ostream& out) const
	{
		if (m_strings == nullptr && m_model[0] == '\0')
		{
			out << "Empty guitar object!\n";
		}
		else if (m_model[0] != '\0')
		{
			out << "Guitar Model: " << m_model << '\n';
			if (m_strings == nullptr)
			{
				out << "Guitar cannot be used yet because it has no strings.\n";
			}
			else
			{
				out << "Strings:\n";
				for (int i = 0; i < m_cntStrings; i++)
				{
					out << " #" << i + 1 << ". " << m_strings[i].getMaterial() << " (" << m_strings[i].getGauge() << "mm)\n";
				}
			}
		}
		return out;
	}
}