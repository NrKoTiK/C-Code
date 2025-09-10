/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#include "Station.h"

namespace seneca 
{
	size_t Station::m_widthField = {};
	int Station::id_generator = {};

	Station::Station(const std::string& strObj)
	{
		Utilities util;
		bool more = 1;
		size_t pos = 0;
		m_id = ++id_generator;
		m_itemName = util.extractToken(strObj, pos, more);
		m_serialNum = static_cast<unsigned int>(std::stoi(util.extractToken(strObj, pos, more)));
		m_currStock = static_cast<unsigned int>(std::stoi(util.extractToken(strObj, pos, more)));
		m_widthField = (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();
		m_itemDesc = util.extractToken(strObj, pos, more);
	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serialNum++;
	}
	size_t Station::getQuantity() const
	{
		return m_currStock;
	}
	void Station::updateQuantity()
	{
		if (m_currStock != 0 && m_currStock > 0) 
		{
			--m_currStock;
		}
		else 
		{
			m_currStock = 0;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (!full) 
		{
			os << std::setfill('0') << std::setw(3) << m_id << " | ";
			os.setf(std::ios::left);
			os << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | ";
			os.setf(std::ios::right);
			os << std::setfill('0') << std::setw(6) << m_serialNum << " | " << std::endl;
			os.unsetf(std::ios::left);
			os.unsetf(std::ios::right);
		}
		else 
		{
			os << std::setfill('0') << std::setw(3) << m_id << " | ";
			os.setf(std::ios::left);
			os << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | ";
			os.setf(std::ios::right);
			os << std::setfill('0') << std::setw(6) << m_serialNum << " | ";
			os << std::setfill(' ') << std::setw(4) << m_currStock << " | ";
			os.unsetf(std::ios::right);
			os << std::setfill(' ') << std::setw(m_widthField - 1) << m_itemDesc << std::endl;
			os.unsetf(std::ios::left);
		}
	}
}