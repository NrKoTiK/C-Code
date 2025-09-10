//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/27/2024
#include <iostream>
#include "Ticket.h"
using namespace std;
namespace seneca
{
	Ticket::Ticket()
	{
		m_number = 0;
		m_time = 0;
	}
	Ticket::Ticket(int number)
	{
		m_number = number;
	}

	Time Ticket::time() const
	{
		return m_time;
	}

	int Ticket::number() const
	{
		return m_number;
	}

	void Ticket::resetTime()
	{
		m_time.reset();
	}

	std::ostream& Ticket::write(std::ostream& out) const
	{
		if (&out != &cout)
		{
			out << m_number << "," << m_time;
		}

		else
		{
			out << "Ticket No: " << m_number << ", Issued at: " << m_time;
		}
		return  out;
	}
	std::istream& Ticket::read(std::istream& in)
	{
		in >> m_number;
		in.ignore();
		return in >> m_time;
	}
}
