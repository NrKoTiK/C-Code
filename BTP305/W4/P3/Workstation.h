/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include <deque>
#include <stack>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca 
{
	/// <summary>
	/// Holds orders to be placed onto the assembly line at the first station
	/// </summary>
	extern std::deque<CustomerOrder> g_pending;
	
	/// <summary>
	/// Holds orders that have been removed from the last station and are completely filled
	/// </summary>
	extern std::deque<CustomerOrder> g_completed;
	
	/// <summary>
	/// Holds orders that have been removed from the last station could not be complete
	/// </summary>
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station
	{
		/// <summary>
		/// These are orders that have been placed on this station to receive service (or already received service)
		/// </summary>
		std::deque<CustomerOrder> m_orders{};

		/// <summary>
		/// a pointer to the next Workstation on the assembly line.
		/// </summary>
		Workstation* m_pNextStation{};
	public:

		/// <summary>
		/// It calls the base class
		/// </summary>
		/// <param name="strObj">string that builds the obj</param>
		Workstation(const std::string strObj);

		/// <summary>
		/// fills order from the front if CustomerOrders are in q; Otherwise nothing
		/// </summary>
		/// <param name="os"></param>
		void fill(std::ostream& os);

		/// <summary>
		/// Moves order to the front of the q
		/// </summary>
		/// <returns>true or false based on success</returns>
		bool attemptToMoveOrder();

		/// <summary>
		/// Stores the addy of param to the instance pointer [SET PARAM TO NULLPTR]
		/// </summary>
		/// <param name="station">give addy to instance pointer</param>
		void setNextStation(Workstation* station);

		/// <summary>
		/// addy of next workstatio
		/// </summary>
		/// <returns>the addy</returns>
		Workstation* getNextStation() const;

		/// <summary>
		/// display
		/// </summary>
		/// <param name="os">output stream</param>
		void display(std::ostream& os) const;

		/// <summary>
		/// moves the param to the back of the q
		/// </summary>
		/// <param name="newOrder">a new order to be moved at the end of q</param>
		/// <returns>current instance</returns>
		Workstation& operator+=(CustomerOrder&& newOrder);
	};

}

#endif // !SENECA_WORKSTATION_H
