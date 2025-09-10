//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/2/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"

/// <summary>
/// Everytime new TriagePatient obj is created the value of this is ++.
/// </summary>
static int nextTriageTicket = 1;

namespace seneca 
{
	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		++nextTriageTicket;
		m_symptoms = nullptr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& out) const
	{
		if (&out == &std::cout)
		{
			out << "TRIAGE\n";
			Patient::write(out);
			out << "Symptoms: " << m_symptoms << std::endl;
		}
		else if (&out == &std::clog) 
		{
			Patient::write(out);
		}
		else 
		{
			Patient::write(out);
			out << ',' << m_symptoms;
		}
		return out;
	}

	std::istream& TriagePatient::read(std::istream& in)
	{
		char temp[511];
		delete[] m_symptoms;
		Patient::read(in);
		if (&in != &std::cin) 
		{
			in.ignore(1000, ',');
			in.get(temp, 511, '\n');
			m_symptoms = new char[strlen(temp) + 1];
			strcpy(m_symptoms, temp);
			nextTriageTicket = this->Patient::number() + 1;
		}
		else 
		{
			std::cout << "Symptoms: ";
			std::cin.get(temp, 511);
			std::cin.ignore();
			m_symptoms = new char[strlen(temp) + 1];
			strcpy(m_symptoms, temp);
		}
		if (in.fail())
		{
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
		return in;
	}
}