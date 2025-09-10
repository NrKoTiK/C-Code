/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca 
{
	class Logger 
	{
		/// <summary>
		/// Collection of Events
		/// </summary>
		Event* m_collectionE;

		/// <summary>
		/// Number to calc the size of array
		/// </summary>
		size_t m_ItemCount;

	public:

		Logger();
			
		~Logger();

		Logger(const Logger& copy_OfL) = delete;

		Logger& operator=(const Logger& copy_OfL) = delete;

		Logger(Logger&& copy_OfL) noexcept;

		Logger& operator=(Logger&& copy_OfL) noexcept;

		void addEvent(const Event& event);
		
		friend std::ostream& operator<<(std::ostream& out, const Logger& Logger_Obj);
	};


}

#endif // !SENECA_LOGGER_H

