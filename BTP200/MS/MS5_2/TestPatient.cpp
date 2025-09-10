//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/2/2024
#include <iostream>
#include "TestPatient.h"

/// <summary>
/// Everytime new TestPatient obj is created the value of this is ++.
/// </summary>
static int nextTestTicket = 1;

namespace seneca 
{
	TestPatient::TestPatient() : Patient(nextTestTicket)
	{
		++nextTestTicket;
	}

	char TestPatient::type() const
	{
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& out) const
	{
		if (&out != &std::cout) 
		{
			Patient::write(out);
		}
		else 
		{
			out << "Contagion TEST\n";
			Patient::write(out);
		}
		return out;
	}

	std::istream& TestPatient::read(std::istream& in)
	{
		Patient::read(in);
		if (&in != &std::cin) 
		{
			nextTestTicket = this->Patient::number() + 1;
		}
		return in;
	}

}