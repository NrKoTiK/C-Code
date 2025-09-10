/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/27/2024
*/
#include "CustomerOrder.h"

namespace seneca 
{
	size_t CustomerOrder::m_widthField = {};

	CustomerOrder::CustomerOrder()
	{
		m_name = {};
		m_product = {};
		m_cntItem = {};
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(const std::string& strObj)
	{
		Utilities util;
		bool more = 1;
		size_t pos = 0;
		m_name = util.extractToken(strObj, pos, more);
		m_product = util.extractToken(strObj, pos, more);
		std::vector<std::string> itemVec{};
		while (more) 
		{
			std::string item = util.extractToken(strObj, pos, more);
			itemVec.push_back(item);
		}
		m_cntItem = itemVec.size();
		m_lstItem = new Item*[m_cntItem];
		for (size_t i = 0; i < m_cntItem; ++i) 
		{
			m_lstItem[i] = new Item(itemVec[i]);
		}
		m_widthField = (m_widthField < util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& copyOf_C)
	{
		throw CustomerOrder();
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& copyOf_C) noexcept
	{
		*this = std::move(copyOf_C);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& copyOf_C) noexcept
	{
		if (this != &copyOf_C) 
		{
			for (size_t i = 0; i < m_cntItem; ++i) 
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_name = copyOf_C.m_name;
			m_product = copyOf_C.m_product;
			m_cntItem = copyOf_C.m_cntItem;

			m_lstItem = copyOf_C.m_lstItem;
			copyOf_C.m_lstItem = nullptr;
			copyOf_C.m_name = {};
			copyOf_C.m_product = {};
			copyOf_C.m_cntItem = 0;
		}
		return *this;
	}
	/// This works
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; ++i) 
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool filled = 1;
		for (size_t i = 0; i < m_cntItem; ++i) 
		{
			if (m_lstItem[i]->m_isFilled == 0) 
			{
				filled = 0;
			}
		}
		return filled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = 1;
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (m_lstItem[i]->m_isFilled == 0)
				{
					filled = 0;
				}
			}
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool found = 1;
		for (size_t i = 0; i < m_cntItem && found; ++i) 
		{
			if (station.getQuantity() > 0)
			{
				if (m_lstItem[i]->m_itemName == station.getItemName())
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = 1;

					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
					found = 0;
				}
			}
			if(station.getQuantity() == 0)
			{
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				found = 0;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; ++i) 
		{
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << ']';
			os.setf(std::ios::left);
			os << " " << std::setw(m_widthField) << m_lstItem[i]->m_itemName << std::setfill(' ') << " - ";
			if (m_lstItem[i]->m_isFilled) 
			{
				os << "FILLED" << std::endl;
			}
			else 
			{
				os << "TO BE FILLED" << std::endl;
			}
			os.unsetf(std::ios::left);
		}
	}
}
