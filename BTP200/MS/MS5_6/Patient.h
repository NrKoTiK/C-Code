//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/2/2024
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace seneca
{
	class Patient : public IOAble
	{
		/// <summary>
		/// dynamic char array for name (CAN NOT EXCEED 50 CHAR LIMIT IF IT DOES THEN TRUNCAT THE NAME)
		/// </summary>
		char* m_pName;

		/// <summary>
		/// int that stores Ontario Health insurance plan (NUMBER THAT IS EXACTLY 9 DIGITS
		/// CAN NOT BE MORE OR LESS)
		/// </summary>
		int m_OHIPNum;

		/// <summary>
		/// Ticket obj to represent patients ticket line up (HAS ALL INFO ABOUT TICKET DETAILS
		/// SUCH AS	POSITION IN Q, ARRIVAL TIME & PRIORITY LVL)
		/// </summary>
		Ticket m_ticket;

	public:

		/// <summary>
		/// Initializes the obj by creating the ticket obj
		/// </summary>
		/// <param name="ticket">used to initialize</param>
		Patient(int ticketNum);

		/// <summary>
		/// Copy constructor 
		/// </summary>
		/// <param name="copyOf_P">another patient obj</param>
		Patient(const Patient& copyOf_P);

		/// <summary>
		/// Copy Assignment
		/// </summary>
		/// <param name="copyOf_P">another patient obj</param>
		/// <returns>the current instance</returns>
		Patient& operator=(const Patient& copyOf_P);

		/// <summary>
		/// destruct obj
		/// </summary>
		~Patient();

		/// <summary>
		/// returns a single character that identifies a type of patient
		/// </summary>
		/// <returns>a character</returns>
		virtual char type() const = 0;

		/// <summary>
		/// Compare the current obj to a single char 
		/// </summary>
		/// <param name="pChar">single char to be compared with</param>
		/// <returns>true if type() == pChar esle false</returns>
		bool operator==(char pChar) const;

		/// <summary>
		/// Compare the current obj to another obj (patient)
		/// </summary>
		/// <param name="patient">another patient obj</param>
		/// <returns>true if *this == patient else false</returns>
		bool operator==(const Patient& patient) const;

		/// <summary>
		/// function sets time of the patient ticket to the current time
		/// </summary>
		void setArrivalTime();

		/// <summary>
		/// gets patients arrival time
		/// </summary>
		/// <returns>the samr arrival time</returns>
		Time time() const;

		/// <summary>
		/// returns the patients ticket number
		/// </summary>
		/// <returns></returns>
		int number() const;

		/// <summary>
		/// validates the obj
		/// </summary>
		operator bool() const;

		/// <summary> 
		/// if patient is a casted to a const char* then
		/// </summary>
		/// <returns>the addr of the patients name</returns>
		operator const char* () const;

		std::ostream& write(std::ostream& out) const override;

		std::istream& read(std::istream& in) override;

	};
}
#endif // !SENECA_PATIENT_H
