/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <string>
#include <vector>
#include "Station.h"
#include "Utilities.h"

namespace seneca 
{
	class CustomerOrder 
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		
		/// <summary>
		/// name of customer
		/// </summary>
		std::string m_name{};

		/// <summary>
		/// name of product being assembled
		/// </summary>
		std::string m_product{};

		/// <summary>
		/// count of number of items in cus order
		/// </summary>
		size_t m_cntItem{};

		/// <summary>
		/// its a array of pointers that point to object of type Item.
		/// </summary>
		Item** m_lstItem{};
	public:

		/// <summary>
		/// max field width for display.
		/// </summary>
		static size_t m_widthField;

		CustomerOrder();

		/// <summary>
		/// set obj by extracting all the values from strObj
		/// </summary>
		/// <param name="strObj">str that has station obj</param>
		CustomerOrder(const std::string& strObj);

		CustomerOrder(const CustomerOrder& copyOf_C);
		CustomerOrder& operator=(const CustomerOrder& copyOf_C) = delete;

		CustomerOrder(CustomerOrder&& copyOf_C) noexcept;
		CustomerOrder& operator=(CustomerOrder&& copyOf_C) noexcept;

		~CustomerOrder();

		/// <summary>
		/// returns true if all the items in the order have been filled false otherwise
		/// </summary>
		/// <returns>true or false</returns>
		bool isOrderFilled() const;

		/// <summary>
		/// returns true if if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
		/// </summary>
		/// <param name="itemName">checks if item exists in the array</param>
		/// <returns>true or false</returns>
		bool isItemFilled(const std::string& itemName) const;

		/// <summary>
		/// fills one item in the current order that the station specified
		/// </summary>
		/// <param name="station">a station object that sets a object</param>
		/// <param name="os">display the execution</param>
		void fillItem(Station& station, std::ostream& os);

		/// <summary>
		/// display function
		/// </summary>
		/// <param name="os">output stream</param>
		void display(std::ostream& os) const;
	};

}

#endif // !SENECA_CUSTOMERORDER_H

