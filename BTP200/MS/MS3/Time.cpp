//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/27/2024
#include <iostream>
#include "Time.h"
#include "Utils.h"

using namespace std;

namespace seneca 
{
	Time::Time(unsigned int min)
	{
		if (min > 0) 
		{
			m_mins = min;
		}
	}

	Time& Time::reset()
	{
		m_mins = U.getTime();
		return *this;
	}

	std::ostream& Time::write(std::ostream& out) const
	{
		unsigned int hours = m_mins / 60;
		unsigned int minutes = m_mins % 60;

		if (hours < 10) 
		{
			out << '0';
		}
		out << hours << ':';
		if (minutes < 10) 
		{
			out << '0';
		}
		out << minutes;

		return out;
	}

	std::istream& Time::read(std::istream& in)
	{
		unsigned int hours = 0;
		unsigned int minutes = 0;
		in >> hours;
		if (in.good()) 
		{
			if (in.peek() == ':')
			{
				in.ignore();
				in >> minutes;
				if (in.good()) 
				{
					m_mins = hours * 60;
					m_mins += minutes;
				}
			}
			else 
			{
				in.setstate(ios::failbit);
			}
		}
		return in;
	}
	Time::operator unsigned int() const
	{
		return m_mins;
	}
	Time& Time::operator*=(int val)
	{
		m_mins *= val;
		return *this;
	}
	Time& Time::operator-=(const Time& D)
	{
		if (m_mins < D.m_mins) 
		{
			m_mins = (m_mins - D.m_mins) + 1440;
		}
		else 
		{
			m_mins = m_mins - D.m_mins;
		}
		return *this;
	}
	Time Time::operator-(const Time& T) const
	{
		Time result = *this;
		result -= T;
		return result;
	}
	std::ostream& operator<<(std::ostream& out, const Time& aTime)
	{
		aTime.write(out);
		return out;
	}
	std::istream& operator>>(std::istream& in, Time& aTime)
	{
		aTime.read(in);
		return in;
	}
}
