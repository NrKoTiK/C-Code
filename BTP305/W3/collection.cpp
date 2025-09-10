/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#include "collection.h"
namespace seneca 
{
	Collection::Collection(const std::string& name)
	{
		m_colName = name;
		m_mediaCol = {};
	}

	Collection::~Collection()
	{
		for (auto iter = m_mediaCol.begin(); iter != m_mediaCol.end(); ++iter) 
		{
			delete* iter;
		}
	}

	const std::string& Collection::name() const
	{
		return m_colName;
	}

	size_t Collection::size() const
	{
		return m_mediaCol.size();
	}

	void Collection::setObserver(void(*observer)(const Collection&, const MediaItem&))
	{
		m_observer = observer;
	}

	Collection& Collection::operator+=(MediaItem* item)
	{
		auto duplicate = std::find_if(m_mediaCol.begin(), m_mediaCol.end(),
			[&item](const MediaItem* existingItem) 
			{
				return existingItem->getTitle() == item->getTitle();
			});

		if (duplicate != m_mediaCol.end()) 
		{
			delete item;
		}
		else 
		{
			m_mediaCol.push_back(item);
		}
		if (m_observer != nullptr) 
		{
			m_observer(*this, *item);
		}
		return *this;
	}

	MediaItem* Collection::operator[](size_t idx) const
	{
		auto iter = m_mediaCol.begin();
		if (idx > m_mediaCol.size()) 
		{
			throw std::out_of_range("Bad index " + std::to_string(idx) + ". Collection has " + std::to_string(m_mediaCol.size()) + " items.\n");
		}
		else 
		{
			std::advance(iter, idx);
		}
		return *iter;
	}

	MediaItem* Collection::operator[](const std::string& title) const
	{
		auto it = std::find_if(m_mediaCol.begin(), m_mediaCol.end(), 
			[=](const MediaItem* item)
			{
				return item->getTitle() == title;
			});
		if (it == m_mediaCol.end()) 
		{
			return nullptr;
		}
		return *it;
	}

	void Collection::removeQuotes()
	{
		std::for_each(m_mediaCol.begin(), m_mediaCol.end(), [](const auto& item) 
			{
				if (item)
				{
					std::string title = item->getTitle();
					if (!title.empty() && title.front() == '"' && title.back() == '"')
					{
						title = title.substr(1, title.size() - 2);
						item->setTitle(title);
					}

					std::string summary = item->getSummary();
					if (!summary.empty() && summary.front() == '"' && summary.back() == '"')
					{
						summary = summary.substr(1, summary.size() - 2);
						item->setSummary(summary);
					}
					else if (summary.back() == '"')
					{
						summary = summary.substr(0, summary.size() - 1);
						item->setSummary(summary);
					}
				}
			});
	}

	void Collection::sort(const std::string& field)
	{
		if (field == "title") 
		{
			// Sort by title
			std::sort(m_mediaCol.begin(), m_mediaCol.end(), [](const MediaItem* a, const MediaItem* b)
				{
					return a->getTitle() < b->getTitle();
				});
		}
		else 
		{
			// Sort by year
			std::sort(m_mediaCol.begin(), m_mediaCol.end(), [](const MediaItem* a, const MediaItem* b)
				{
					return a->getYear() < b->getYear();
				});
		}
	}
	
	std::ostream& operator<<(std::ostream& out, const Collection& col)
	{
		for (size_t i = 0u; i < col.size(); ++i) 
		{
			col[i]->display(out);
		}
		return out;
	}
}
