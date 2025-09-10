//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/26/2024
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "LibraryItem.h"

namespace seneca
{
	class Book : public LibraryItem
	{
		char* m_author;

	public:
		
		/// <summary>
		/// initialize Book obj with book
		/// </summary>
		/// <param name="m_author">name of author that needs to be initialized</param>
		Book(const char* title, const int year, const char* m_author);

		/// <summary>
		/// copy data from obj to current (MAKE SURE TO CALL BASE CLASS CONSTRUCTOR)
		/// </summary>
		/// <param name="copyOf_B">some obj</param>
		Book(const Book& copyOf_B);

		/// <summary>
		/// copy assignment to copy from some obj to current
		/// </summary>
		/// <param name="copyOf_B">some obj</param>
		/// <returns>current instance</returns>
		Book& operator=(const Book& copyOf_B);

		/// <summary>
		/// destroy obj
		/// </summary>
		~Book();

		/// <summary>
		/// display function displays title year and author
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		std::ostream& display(std::ostream& out = std::cout) const override;

		/// <summary>
		/// Checks for non null author names and checks to see if authorname is alphabetic order
		/// (USE STRCMP())
		/// </summary>
		/// <param name="other">comparing current author name to other obj name</param>
		/// <returns>true if name in current instance is before name in obj</returns>
		bool operator>(const Book& other) const;
	};
}

#endif // !SENECA_BOOK_H