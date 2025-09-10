/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "event.h"
#include "settings.h"

namespace seneca 
{
	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_Ename{ name }, m_duration{duration} {	}

	std::ostream& operator<<(std::ostream& out, const Event& event_Obj)
	{
		static int cnt = 0;
		size_t time = event_Obj.m_duration.count();
		++cnt;
		int durationFieldSize = 11;
		if (g_settings.m_time_units == "seconds") 
		{
			durationFieldSize = 2;
			time = std::chrono::duration_cast<std::chrono::seconds>(event_Obj.m_duration).count();
		}
		else if (g_settings.m_time_units == "milliseconds") 
		{
			durationFieldSize = 5;
			time = std::chrono::duration_cast<std::chrono::milliseconds>(event_Obj.m_duration).count();
		}
		else if (g_settings.m_time_units == "microseconds") 
		{
			durationFieldSize = 8;
			time = std::chrono::duration_cast<std::chrono::microseconds>(event_Obj.m_duration).count();
		}

		out << std::setw(2) << cnt << ": "
			<< std::setw(40) << event_Obj.m_Ename << " -> "
			<< std::setw(durationFieldSize) << time << " "
			<< g_settings.m_time_units;

		return out;
	}
}
