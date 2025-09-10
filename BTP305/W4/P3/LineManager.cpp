/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/29/2024
*/
#include "LineManager.h"

namespace seneca 
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream stream(file);
		Utilities util;
		std::string strObj;
		size_t next_pos = 0;
		bool more = true;
		std::string current;
		std::string next;
		if (stream.is_open()) 
		{
			while (std::getline(stream, strObj, '\n')) 
			{
				next_pos = 0;
				current = util.extractToken(strObj, next_pos, more);
				if (more) 
				{
					next = util.extractToken(strObj, next_pos, more);
				}
				else 
				{
					next.clear();
				}
				auto currStation = std::find_if(stations.begin(), stations.end(), [&current](const Workstation* station)
					{
						return station->getItemName() == current;
					});
				auto nextStation = std::find_if(stations.begin(), stations.end(), [&next](const Workstation* station) 
					{
						return station->getItemName() == next;
					});
				if (!next.empty() && nextStation != stations.end()) 
				{
					(*currStation)->setNextStation(*nextStation);
				}
				m_activateLine.push_back(*currStation);
			}
			auto firstStation = std::find_if(m_activateLine.begin(), m_activateLine.end(), [&stations](const Workstation* station) 
				{
					return std::none_of(stations.begin(), stations.end(), [&station](const Workstation* ws) 
						{
							return ws->getNextStation() == station;
						});
				});
			if (firstStation != m_activateLine.end()) 
			{
				m_firstStation = (*firstStation);
			}
			m_cntCustomerOrder = g_pending.size();
		}
	}
	
	void LineManager::reorderStations()
	{
		std::vector<Workstation*> ordered;
		Workstation* firstStation = m_firstStation;
		while (firstStation != nullptr) 
		{
			ordered.push_back(firstStation);
			firstStation = firstStation->getNextStation();
		}
		m_activateLine = ordered;
	}
	bool LineManager::run(std::ostream& os)
	{
		static int iterCnt = 0;
		os << "Line Manager Iteration: " << ++iterCnt << '\n';
		if (g_pending.empty() == false) 
		{
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		for (auto& item : m_activateLine) 
		{
			item->fill(os);
		}
		for (auto& item : m_activateLine) 
		{
			item->attemptToMoveOrder();
		}

		return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
	}
	void LineManager::display(std::ostream& os) const
	{
		for (const auto* workStation : m_activateLine)
		{
			workStation->display(os);
		}
	}
}