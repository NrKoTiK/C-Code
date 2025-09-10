/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <vector>
#include <iterator>
#include <algorithm>
#include "mediaItem.h"

namespace seneca 
{
	class Collection
	{
		std::string m_colName{};
		std::vector<MediaItem*> m_mediaCol{};
		/// <summary>
		/// tells client that media was added to collection.
		/// </summary>
		void (*m_observer)(const Collection&, const MediaItem&) = nullptr;

	public:
		/// <summary>
		/// Set name of collection
		/// </summary>
		/// <param name="name">parameter which has the collection name</param>
		Collection(const std::string& name);

		Collection(const Collection& copyOf_C) = delete;
		Collection& operator=(const Collection& copyOf_C) = delete;
		Collection(Collection&& copyOf_C) = delete;
		Collection& operator=(Collection&& copyOf_C) = delete;

		~Collection();
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns>returns the name of the collection</returns>
		const std::string& name() const;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Returns number of item in collection</returns>
		size_t size() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="observer"></param>
		void setObserver(void (*observer)(const Collection&, const MediaItem&));

		Collection& operator+=(MediaItem* item);

		MediaItem* operator[](size_t idx) const;

		MediaItem* operator[](const std::string& title) const;

		void removeQuotes();

		void sort(const std::string& field);
	};
	std::ostream& operator<<(std::ostream& out, const Collection& col);
}

#endif // !SENECA_COLLECTION_H
