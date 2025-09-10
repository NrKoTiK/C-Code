/*
- Ahmad Syed
- 102437233
- asyed113@myseneca.ca
- 9/29/2024
*/
#include <iostream>
#include "logger.h"

namespace seneca 
{
	Logger::Logger()
	{
		m_collectionE = nullptr;
		m_ItemCount = 0;
	}
	Logger::~Logger()
	{
		delete[] m_collectionE;
	}
	Logger::Logger(Logger&& copy_OfL) noexcept
	{
		*this = std::move(copy_OfL);
	}
	Logger& Logger::operator=(Logger&& copy_OfL) noexcept
	{
		if (this != &copy_OfL) 
		{
			delete[] m_collectionE;

			m_ItemCount = copy_OfL.m_ItemCount;

			m_collectionE = copy_OfL.m_collectionE;
			copy_OfL.m_collectionE = nullptr;
			copy_OfL.m_ItemCount = 0;
		}
		return *this;
	}
	void Logger::addEvent(const Event& event)
	{
		Event* tempArr = new Event[m_ItemCount + 1];
		for (size_t i = 0u; i < m_ItemCount; ++i) 
		{
			tempArr[i] = m_collectionE[i];
		}
		delete[] m_collectionE;
		tempArr[m_ItemCount] = event;
		m_collectionE = tempArr;
		++m_ItemCount;
	}
	std::ostream& operator<<(std::ostream& out, const Logger& Logger_Obj)
	{
		for (size_t i = 0; i < Logger_Obj.m_ItemCount; ++i) 
		{
			out << Logger_Obj.m_collectionE[i] << std::endl;
		}
		return out;
	}
}
