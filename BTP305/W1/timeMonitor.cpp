/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#include <iostream>
#include "timeMonitor.h"
#include "event.h"

namespace seneca 
{
	void TimeMonitor::startEvent(const char* name)
	{
		m_currEName = name;
		m_startTime = std::chrono::steady_clock::now();
	}
	Event TimeMonitor::stopEvent()
	{
		auto endtime = std::chrono::steady_clock::now();

		//ion think this is working properly the output is giving me all the calc in nanoseconds
		std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endtime - m_startTime);

		return Event(m_currEName.c_str(), duration);
	}
}