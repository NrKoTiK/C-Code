//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/26/2024
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>

namespace seneca
{
	class LibraryItem
	{
		/// <summary>
		/// dynamic addr of the title
		/// </summary>
		char* m_title;

		/// <summary>
		/// int to rep publication year
		/// </summary>
		int m_year;

	public:

		/// <summary>
		/// default constructor
		/// </summary>
		LibraryItem();

		/// <summary>
		/// Initialize obj with the provided parameter (validate)
		/// </summary>
		/// <param name="title">some title to be stored into obj</param>
		/// <param name="year">some year to be stored into obj</param>
		LibraryItem(const char* title, const int year);

		/// <summary>
		/// copy constructor
		/// </summary>
		/// <param name="copyOf_L">some obj to be copied</param>
		LibraryItem(const LibraryItem& copyOf_L);

		/// <summary>
		/// copy assignment ope
		/// </summary>
		/// <param name="copyOf_L">another obj to be copied</param>
		/// <returns>the current instance</returns>
		LibraryItem& operator=(const LibraryItem& copyOf_L);

		/// <summary>
		/// destroy obj
		/// </summary>
		virtual ~LibraryItem();

		/// <summary>
		/// Displays the title and year using output stream
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		virtual std::ostream& display(std::ostream& out = std::cout) const;
	};
}
#endif // !SENECA_LIBRARYITEM_H


