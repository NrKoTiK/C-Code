/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H
#include <vector>
#include <fstream>
#include "Workstation.h"

namespace seneca 
{
	class LineManager 
	{
		/// <summary>
		/// Collection of workstation for current assembly line.
		/// </summary>
		std::vector<Workstation*> m_activateLine{};

		/// <summary>
		/// total number of customer order objs
		/// </summary>
		size_t m_cntCustomerOrder{};
	
		/// <summary>
		/// points to the first active station on the current assembly line
		/// </summary>
		Workstation* m_firstStation{};

	public:
		/// <summary>
		/// file that has all the active stations and the collections of workstations available for configuring the assembly line
		/// </summary>
		/// <param name="file">name of file to extract data from</param>
		/// <param name="stations">all the diff stations</param>
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		
		/// <summary>
		/// re-orders the workstations that are present in the instance variable
		/// </summary>
		void reorderStations();

		/// <summary>
		/// preforms one iteration on all workstations in the current assembly line 
		/// </summary>
		/// <param name="os">output stream</param>
		/// <returns>true or false based on success</returns>
		bool run(std::ostream& os);

		/// <summary>
		/// display
		/// </summary>
		/// <param name="os">output</param>
		void display(std::ostream& os) const;
	};
}

#endif // !SENECA_LINEMANAGER_H
