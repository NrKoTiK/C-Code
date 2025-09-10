/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <chrono>
#include "event.h"

namespace seneca 
{
	class TimeMonitor 
	{
		/// <summary>
		/// name of the current event
		/// </summary>
		std::string m_currEName;
		
		/// <summary>
		/// Using chrono lib to calc start time for the current task
		/// </summary>
		std::chrono::steady_clock::time_point m_startTime;

	public:
		TimeMonitor() = default;

		void startEvent(const char* name);

		Event stopEvent();
	};

}
#endif // !SENECA_TIMEMONITOR_H

