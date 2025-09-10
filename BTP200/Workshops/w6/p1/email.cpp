//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/3/2024h

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "email.h"

using namespace std;
namespace seneca 
{
	Email::Email()
	{
		m_fromName[0] = '\0';
		m_fromAddress[0] = '\0';
		m_dateReceived[0] = '\0';
		m_subject = nullptr;
	}

	Email::Email(const Email& copyOf_E)
	{
		//Set Dynamic to null.
		m_subject = nullptr;
		*this = copyOf_E;
	}

	Email& Email::operator=(const Email& copyOf_E)
	{
		//Validate
		if (this != &copyOf_E)
		{
			//Clean Up
			delete[] m_subject;

			//Shallow Copy
			strcpy(m_fromName, copyOf_E.m_fromName);
			strcpy(m_fromAddress, copyOf_E.m_fromAddress);
			strcpy(m_dateReceived, copyOf_E.m_dateReceived);
			
			//Deep Copy
			if (copyOf_E.m_subject != nullptr && copyOf_E.m_subject[0] != '\0') 
			{
				m_subject = new char[strlen(copyOf_E.m_subject) + 1];
				strcpy(m_subject, copyOf_E.m_subject);
			}
			else
			{
				m_subject = nullptr;
			}
		}
		return *this;
	}

	Email::~Email()
	{
		delete[] m_subject;
	}

	bool Email::load(std::istream& in)
	{
		bool ifGood = false;
		char buffer[1000];
		in.getline(m_fromAddress, 1000, ',');
		in.getline(m_fromName, 1000, ',');
		in.getline(buffer, 1000, ',');
		in.getline(m_dateReceived, 1000, '\n');
		
		if (in.good()) 
		{
			delete[] m_subject;
			m_subject = new char[strlen(buffer) + 1];
			strcpy(m_subject, buffer);
			ifGood = true;
		}
		else 
		{
			*this = Email();
		}
		return ifGood;
	}

	std::ostream& operator<<(std::ostream& out, const Email& email)
	{	
		if (email.m_fromAddress[0] != '\0')
		{
			int startidx = 11;
			char onlyTime[10 + 1];
			strncpy(onlyTime, email.m_dateReceived + startidx, 10);
			onlyTime[10] = '\0';

			out.setf(ios::right);
			out.width(20);
			out << email.m_fromName << "  ";
			out.unsetf(ios::right);
			
			out.setf(ios::left);
			out.width(40);
			out << email.m_fromAddress << "  ";
			out.unsetf(ios::left);
			
			//FIX THIS OUTPUT DOES NOT MATCH RN
			out.setf(ios::left);
			out.width(15);
			out << onlyTime << "  ";
			out.unsetf(ios::left);

			out << email.m_subject << endl;
		}
		return out;
	}
}

