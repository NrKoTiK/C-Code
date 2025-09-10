//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/27/2024
#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
#include "Utils.h"

/// <summary>
/// Will manage progression of time and add timestamps to appointment tickets
/// </summary>

namespace seneca
{
	class Time 
	{
		/// <summary>
		/// Records time in minutes.
		/// </summary>
		unsigned int m_mins{};
	
	public:
		/// <summary>
		/// Initializes the state of object sets m_mins to parameter
		/// </summary>
		/// <param name="min">minutes</param>
		Time(unsigned int min = 0u);

		/// <summary>
		/// Resets the time Obj to the current time using U.getTime() 
		/// </summary>
		/// <returns>This current instance.</returns>
		Time& reset();

		/// <summary>
		/// Output stream displays the time in "HH:MM" format
		/// </summary>
		/// <param name="out">reference to out</param>
		/// <returns>returns out</returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// Input stream reads time in "H:M" format ensures that the 2 ints are separated by a ":"	
		/// If they not then set istream to a failure state 
		/// </summary>
		/// <param name="in">reference to in</param>
		/// <returns>returns in</returns>
		std::istream& read(std::istream& in);

		/// <summary>
		/// Turns time obj to int (mins).
		/// </summary>
		operator unsigned int() const;

		/// <summary>
		/// multiplies the number of minutes stored in the time object 
		/// </summary>
		/// <param name="val">Some value that is used to multiple minutes stored in time obj</param>
		/// <returns>the current instance</returns>
		Time& operator*=(int val);

		/// <summary>
		/// Calculates the time difference between the current time and the time stored in Obj D 
		/// (the Difference can never be a --NEGATIVE--) If	result is negative add 24hours (1440 minutes)
		/// to ensure result is positive 
		/// </summary>
		/// <param name="D">An un-modifiable Time object that is used to calculate difference between the current time.</param>
		/// <returns>the current instance</returns>
		Time& operator-=(const Time& D);

		/// <summary>
		/// Does the same thing as the previous assignment overload. (DOES NOT MOD CURRENT OBJ)
		/// </summary>
		/// <param name="T">An un-modifiable Time object that is used to calculate difference between the current time.</param>
		/// <returns>an obj of type Time</returns>
		Time operator-(const Time& T) const;


	};

	//**FREEHELPER**

	/// <summary>
	/// calls the write function on obj aTime
	/// </summary>
	/// <param name="out">reference to output stream</param>
	/// <param name="aTime">a un-modifiable reference to an object of type of aTime</param>
	/// <returns>returns "out"</returns>
	std::ostream& operator<<(std::ostream& out, const Time& aTime);

	/// <summary>
	/// Input stream reads time in "H:M" format ensures that the 2 ints are separated by a ":"	
	/// If they not then set istream to a failure state 
	/// </summary>
	/// <param name="in">reference to input stream (used to read)</param>
	/// <param name="aTime">a un-modifiable reference to an object of type aTime</param>
	/// <returns>returns "in"</returns>
	std::istream& operator>>(std::istream& in, Time& aTime);
	
}
#endif // !SENECA_TIME_H