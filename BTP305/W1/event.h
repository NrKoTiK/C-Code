/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <string>
#include <chrono>

namespace seneca 
{
	class Event 
	{
		std::string m_Ename;
		std::chrono::nanoseconds m_duration;

	public:
		Event() = default;

		Event(const char* name, const std::chrono::nanoseconds& duration);
		
		friend std::ostream& operator<<(std::ostream& out, const Event& event_Obj);

	};

	
}

#endif // !SENECA_EVENT_H

	