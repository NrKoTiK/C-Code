//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/2/2024
#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H
#include "Patient.h"

namespace seneca 
{
	class TriagePatient : public Patient
	{
		/// <summary>
		/// Symptoms of a patient !!(CAN NOT EXCEED 512 BYTE LIMIT)!!
		/// will ignore if goes over buffer limit
		/// </summary>
		char* m_symptoms;

	public:

		/// <summary>
		/// Sets char* to nullptr & passes global var as parameter to base class constructor
		/// </summary>
		TriagePatient();

		/// <summary>
		/// Take m_symptoms out of scope.
		/// </summary>
		~TriagePatient();

		/// <summary>
		/// returns a single character that identifies a type of patient (Only returns T)
		/// </summary>
		/// <returns>a character</returns>
		char type() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		std::ostream& write(std::ostream& out) const override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="in">input stream</param>
		/// <returns>in</returns>
		std::istream& read(std::istream& in) override;
	};
}
#endif // !SENECA_TRIAGEPATIENT_H
