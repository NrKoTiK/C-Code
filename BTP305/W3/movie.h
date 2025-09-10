/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iomanip>
#include "mediaItem.h"
#include "settings.h"

namespace seneca 
{
	class Movie : public MediaItem 
	{
		Movie(const std::string title, const std::string summary, unsigned short year);
	public:
		void display(std::ostream& out) const override;

		/// <summary>
		/// Makes object of type movie based on the parameter string
		/// </summary>
		/// <param name="strMovie">The parameter contains a single line of text extracted from the file movies.csv (CHECK REPO FOR FORMAT)</param>
		/// <returns>pointer to that obj</returns>
		static Movie* createItem(const std::string& strMovie);
	};
}

#endif // !SENECA_MOVIE_H
