/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/27/2024
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Utilities.h"

namespace seneca 
{
	class Station 
	{
		/// <summary>
		/// id of item
		/// </summary>
		int m_id{};

		/// <summary>
		/// name of item
		/// </summary>
		std::string m_itemName{};

		/// <summary>
		/// description of item
		/// </summary>
		std::string m_itemDesc{};
		
		/// <summary>
		/// item serial number
		/// </summary>
		unsigned int m_serialNum{};
		
		/// <summary>
		/// item currently in stock
		/// </summary>
		unsigned int m_currStock{};

	public:
		/// <summary>
		/// number of chars required to print string to screen (set to 0)
		/// </summary>
		static size_t m_widthField;

		/// <summary>
		/// everytime new id is created increment and set that value to m_id
		/// </summary>
		static int id_generator;

		/// <summary>
		/// set obj by extracting all the values from the strObj
		/// </summary>
		/// <param name="strObj">str that has all station obj</param>
		Station(const std::string& strObj);

		/// <summary>
		/// gets the item name
		/// </summary>
		/// <returns>return item name</returns>
		const std::string& getItemName() const;

		/// <summary>
		/// returns the next serial number to be used on the assembly line and increments m_serialNumber
		/// </summary>
		size_t getNextSerialNumber();
	
		/// <summary>
		/// gets the item quantity
		/// </summary>
		/// <returns>returns currStock</returns>
		size_t getQuantity() const;

		/// <summary>
		/// subtracts 1 from the quantity (SHOULD NOT BE NEGATIVE)
		/// </summary>
		void updateQuantity();

		/// <summary>
		/// display function
		/// </summary>
		/// <param name="os">output stream</param>
		/// <param name="full">if false (insert [ID | NAME | SERIAL | ]) : If true (insert [ID | NAME | SERIAL | QUANTITY | ])</param>
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SENECA_STATION_H
