/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#include "Workstation.h"

namespace seneca 
{
	std::deque<CustomerOrder> g_pending = {};
	std::deque<CustomerOrder> g_completed = {};
	std::deque<CustomerOrder> g_incomplete{};

	Workstation::Workstation(const std::string strObj) : Station(strObj)
	{}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool moved = false;
		if (m_orders.empty() == false)
		{
			auto& order = m_orders.front();
			if (order.isItemFilled(getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += std::move(order);
				}
				else
				{
					if (order.isOrderFilled())
					{
						g_completed.push_back(std::move(order));
					}
					else
					{
						g_incomplete.push_back(std::move(order));
					}
				}
				m_orders.pop_front();
				moved = true;
			}
		}
		return moved;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
		station = nullptr;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		if (this->getNextStation() != nullptr)
		{
			os << this->getItemName() << " --> " << m_pNextStation->getItemName();
		}
		else
		{
			os << this->getItemName() << " --> " << "End of Line";
		}
		os << "\n";
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}