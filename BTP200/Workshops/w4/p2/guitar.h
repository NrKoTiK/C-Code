//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 2/13/2024

#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H
#include <iostream>
#include "guitarString.h"

namespace seneca 
{
	class Guitar 
	{
		char m_model[65];
		GuitarString* m_strings;
		int m_cntStrings;
	public:
		/// <summary>
		/// a custom constructor with one parameters that initializes the current instance with the values of the parameter if the parameter is valid.
		/// </summary>
		/// <param name="model">- the address of an unmodifiable C-style string. By default, this parameter has the address of the string "Stratocaster"! A valid model is any string with at least one character.</param>
		Guitar(const char* model = "Stratocaster");
		
		
		/// <summary>
		/// a custom constructor with three parameters that initializes the current instance with the values of the parameter if the parameters are valid.
		/// </summary>
		/// <param name="strings">- the address of an unmodifiable array of GuitarString objects</param>
		/// <param name="cntStrings">- the number of GuitarString objects in the array</param>
		/// <param name="model">- the address of an unmodiable C-style string. A valid model is any C-string with at least one character.</param>
		Guitar(const GuitarString* strings, int cntStrings, const char* model);

		
		~Guitar();


		/// <summary>
		/// a modifier that removes all the strings from the current object, and replaces them with those received as parameter
		/// </summary>
		/// <param name="strings">- the address of an unmodifiable array of GuitarString objects</param>
		/// <param name="cntStrings">- the number of GuitarString objects in the array</param>
		/// <returns>a reference to an object of type Guitar</returns>
		Guitar& reString(const GuitarString* strings, int cntStrings);

		
		/// <summary>
		/// a modifier that changes a single string with the one received as parameter
		/// </summary>
		/// <param name="aString">- a reference to an unmodifiable object of type GuitarString</param>
		/// <param name="idx">- the index of the GuitarString object that must be replaced with the one received as parameter in aString</param>
		/// <returns>a reference to an object of type Guitar</returns>
		Guitar& reString(GuitarString& aString, int idx);


		/// <summary>
		/// a modifier that removes all the strings from the current object
		/// </summary>
		/// <returns>a reference to an object of type Guitar</returns>
		Guitar& deString();


		/// <summary>
		/// a query that returns true if the guitar has at least one string; false otherwise
		/// </summary>
		/// <returns></returns>
		bool isStrung() const;


		std::ostream& display(std::ostream& out = std::cout) const;
	};

}


#endif // !SENECA_GUITAR_H

