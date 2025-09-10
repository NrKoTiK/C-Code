//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/4/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
using namespace std;

namespace seneca
{
	Patient::Patient(int ticketNum) : m_ticket(ticketNum)
	{
		m_pName = nullptr;
		m_OHIPNum = 0;
	}

	Patient::Patient(const Patient& copyOf_P) : m_ticket(copyOf_P.m_ticket.number())
	{
		m_pName = nullptr;
		m_OHIPNum = 0;
		*this = copyOf_P;
	}

	Patient& Patient::operator=(const Patient& copyOf_P)
	{

		if (this != &copyOf_P)
		{
			delete[] m_pName;
			m_OHIPNum = copyOf_P.m_OHIPNum;
			m_ticket = copyOf_P.m_ticket;
			if (copyOf_P.m_pName != nullptr && copyOf_P.m_pName[0] != '\0')
			{
				m_pName = new char[strlen(copyOf_P.m_pName) + 1];
				strcpy(m_pName, copyOf_P.m_pName);
			}
			else
			{
				m_pName = nullptr;
			}
		}
		return *this;
	}

	Patient::~Patient()
	{
		delete[] m_pName;
	}

	bool Patient::operator==(char pChar) const
	{
		bool same = false;
		if (this->type() == pChar)
		{
			same = true;
		}
		return same;
	}

	bool Patient::operator==(const Patient& patient) const
	{
		bool same = false;
		if (this->type() == patient.type())
		{
			same = true;
		}
		return same;
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Time Patient::time() const
	{
		return m_ticket.time();
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	Patient::operator bool() const
	{
		bool valid = false;
		if (m_pName != nullptr && m_pName[0] != '\0' && strlen(m_pName) <= 50 && (m_OHIPNum >= 100000000 && m_OHIPNum <= 999999999))
		{
			valid = true;
		}
		return valid;
	}

	Patient::operator const char* () const
	{
		return m_pName;
	}

	std::ostream& Patient::write(std::ostream& out) const
	{
		if (&out == &cout)
		{
			if (*this)
			{
				m_ticket.write(out);
				out << endl << m_pName << ", OHIP: " << m_OHIPNum << endl;
			}
			else
			{
				out << "Invalid Patient Record" << endl;
			}
		}
		else if (&out == &clog)
		{
			if (*this)
			{
				out.setf(ios::left);
				out.width(53);
				out.fill('.');
				out << m_pName;
				out << m_OHIPNum;
				out.unsetf(ios::left);

				out.setf(ios::right);
				out.width(5);
				out.fill(' ');
				out << m_ticket.number() << ' ';
				m_ticket.time().write(out);
				//out << endl;
				out.unsetf(ios::right);
			}
			else
			{
				out << "Invalid Patient Record" << endl;
			}
		}
		else
		{
			out << type() << "," << m_pName << "," << m_OHIPNum << ",";
			m_ticket.write(out);
		}
		return out;
	}

	std::istream& Patient::read(std::istream& in)
	{
		char temp[51];
		if (&in == &std::cin)
		{
			cout << "Name: ";
			in.get(temp, 51, '\n');
			delete[] m_pName;
			m_pName = new char[strlen(temp) + 1];
			strcpy(m_pName, temp);
			in.ignore(1000, '\n');

			std::cout << "OHIP: ";
			while (!(in >> m_OHIPNum))
			{
				in.clear();
				in.ignore(1000, '\n');
				cout << "Bad integer value, try again: ";
				if (m_OHIPNum < 100000000 || m_OHIPNum > 999999999)
				{
					in.ignore(1000, '\n');
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				}
			}
			in.ignore(1000, '\n');
		}
		else
		{
			in.get(temp, 51, ',');
			delete[] m_pName;
			m_pName = new char[strlen(temp) + 1];
			strcpy(m_pName, temp);
			in.ignore(1000, ',');

			in >> m_OHIPNum;
			in.ignore(1000, ',');
			m_ticket.read(in);
		}
		if (in.fail())
		{
			delete[] m_pName;
			m_pName = nullptr;
		}
		return in;
	}
}