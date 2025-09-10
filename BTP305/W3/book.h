/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iomanip>
#include <iostream>
#include <sstream>
#include "settings.h"
#include "mediaItem.h"

namespace seneca
{
	class Book : public MediaItem
	{
		/// <summary>
		/// Used string because its a array of characters and string is designed for that purpose
		/// ----The Author of Book
		/// </summary>
		std::string m_author{};
		
		/// <summary>
		/// ----Country published
		/// </summary>
		std::string m_country{};

		/// <summary>
		/// Used double because to handle large numbers (just in case)
		/// ----Price of Book
		/// </summary>
		double m_price{};

		Book(const std::string title, const unsigned short year, const std::string summary, const std::string author, const std::string country, const double price);

	public:
		void display(std::ostream& out) const override;

        /// <summary>
        /// Reads from file details about object book
        /// </summary>
        /// <param name="strBook">The parameter contains a single line of text extracted from the file books.csv (CHECK REPO FOR FORMAT)</param>
        /// <returns>pointer to that obj</returns>
        static Book* createItem(const std::string& strBook);
	};

}
#endif // !SENECA_BOOK_H
