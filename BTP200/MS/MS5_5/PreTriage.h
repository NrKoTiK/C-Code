//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/4/2024
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Time.h"
#include "Patient.h"


const static int g_maxNumLineUp = 100;

namespace seneca 
{

	class PreTriage 
	{
		/// <summary>
		/// Wait time for Contagion Patient
		/// </summary>
		Time m_avgTimeC;
		
		/// <summary>
		/// Wait time for Triage Patient
		/// </summary>
		Time m_avgTimeT;

		/// <summary>
		/// Patients in Line.
		/// </summary>
		Patient* m_PinLine[g_maxNumLineUp];

		/// <summary>
		/// char array to hold filename
		/// </summary>
		char* m_DFileName;

		/// <summary>
		/// The Actual number of patients in the line up. !!(CAN NOT EXCEED maxNumLineUp)!!
		/// </summary>
		int m_numOfP;

		/// <summary>
		/// gets wait time for a patient.
		/// </summary>
		/// <param name="wTime"></param>
		/// <returns></returns>
		Time getWaitTime(const Patient& wTime) const;

		/// <summary>
		/// sets avgWaitTime for a patient. (CHECK GIT FOR FORMULA) 
		/// </summary>
		/// <param name="avgWaitTimeofP">patient ticket time</param>
		void setAverageWaitTime(const Patient& avgWaitTimeofP);

		/// <summary>
		/// checks for the type of patient recieved in parameter
		/// </summary>
		/// <param name="pType">type of patient (C or T)</param>
		/// <returns>the index of where type matches the array of patient obj else returns -1 if nun found</returns>
		int indexOfFirstInLine(const char pType) const;

		/// <summary>
		/// Loads avg wait time and the patient records from the data file and stores them into the m_PinLine arr.
		/// </summary>
		void load();

		/// <summary>
		/// Saves data
		/// </summary>
		void save() const;

		/// <summary>
		/// registers patient
		/// </summary>
		void registerp();

		/// <summary>
		/// admits patient
		/// </summary>
		void admit();

		/// <summary>
		/// prints report on patient currently in lineup 
		/// </summary>
		void lineup() const;
	public:

		/// <summary>
		/// obj is created when filename is assigned. Sets triage Time obj to 5 and contagion to 15.
		/// </summary>
		/// <param name="fileName">Name of File</param>
		PreTriage(const char* fileName);

		/// <summary>
		/// Saves the data, Iterates over the patient lineup and deletes 1 by 1 and deletes any other dynamic memory.
		/// </summary>
		~PreTriage();

		/// <summary>
		/// Runs the PreTriage main application
		/// </summary>
		void run();
	};
}

#endif // !SENECA_PRETRIAGE_H
