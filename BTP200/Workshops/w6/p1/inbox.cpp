//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/3/2024

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "inbox.h"
#include "email.h"

namespace seneca 
{
	Inbox::Inbox()
	{
		m_emails = nullptr;
		m_cntEmails = 0;
	}

	Inbox::Inbox(const Inbox& copyOf_I)
	{
		//Set Dynamic to null.
		m_emails = nullptr;
		*this = copyOf_I;
	}

	Inbox& Inbox::operator=(const Inbox& copyOf_I)
	{
		//Validate
		if (this != &copyOf_I) 
		{
			//Clean Up
			delete[] m_emails;
			
			//Shallow Copy
			m_cntEmails = copyOf_I.m_cntEmails;
			
			//Deep Copy
			if (copyOf_I.m_emails != nullptr) 
			{
				m_emails = new Email[m_cntEmails];
				for (int i = 0; i < m_cntEmails; ++i) 
				{
					m_emails[i] = copyOf_I.m_emails[i];
				}
			}
			else 
			{
				m_emails = nullptr;
			}
		}
		return *this;
	}

	Inbox::~Inbox()
	{
		delete[] m_emails;
	}

	Inbox& Inbox::operator+=(const Email& email)
	{
		Email* tmp = new Email[m_cntEmails + 1];
		for (int i = 0; i < m_cntEmails; ++i) 
		{
			tmp[i] = m_emails[i];
		}
		delete[] m_emails;
		tmp[m_cntEmails] = email;
		m_emails = tmp;
		++m_cntEmails;
		return *this;
	}

	Inbox Inbox::operator+(const Email& email) const
	{
		Inbox newInbox = *this;
		newInbox += email;
		return newInbox;
	}
	
	//For the load() and save() function I used <fstream> class
	//I was given the idea from Copilot AI. 
	// The implementation is all done by me.
	void Inbox::load(const char* filename)
	{
		
		if (filename != nullptr && filename[0] != '\0') 
		{
			std::ifstream file(filename);
			if (file.is_open()) 
			{
				while (file.good()) 
				{
					Email email;
					if (email.load(file)) 
					{
						*this += email;
					}
					else 
					{
						break;
					}
				}
			}
			file.close();
		}
	}

	void Inbox::save(const char* filename) const
	{
		if (filename != nullptr && filename[0] != '\0') 
		{
			std::ofstream file(filename);
			if (file.is_open()) 
			{
				for (int i = 0; i < m_cntEmails; ++i) 
				{
					file << m_emails[i];
				}
			}
			file.close();
		}
	}

	std::ostream& operator<<(std::ostream& out, const Inbox& inbox)
	{
		for (int i = 0; i < inbox.m_cntEmails; ++i) 
		{
			out << inbox.m_emails[i];
		}
		return out;
	}

}