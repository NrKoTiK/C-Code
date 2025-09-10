//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/4/2024
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include "Patient.h"

namespace seneca 
{
	class TestPatient : public Patient
	{
	public:
		/// <summary>
		/// Default Constructor to add static var
		/// </summary>
		TestPatient();

		/// <summary>
		/// returns a single character that identifies a type of patient (Only returns C)
		/// </summary>
		/// <returns>a character</returns>
		char type() const override;

		/// <summary>
		/// if ostream is &cout it will insert "Contagion TEST" into the ostream 
		/// obj and goes to newline
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		std::ostream& write(std::ostream& out) const override;

		/// <summary>
		/// call read function of the base class Patient.
		/// if &in is not &cin (is not reading from file)
		/// then it should set the nextTestTicket to the ticket number of the patient + 1 
		/// </summary>
		/// <param name="in">input stream</param>
		/// <returns>in</returns>
		std::istream& read(std::istream& in) override;
	};
}
#endif // !SENECA_TESTPATIENT_H
