#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibraryItem.h"

namespace seneca 
{
	LibraryItem::LibraryItem()
	{
		m_title = nullptr;
		m_year = 0;
	}

	LibraryItem::LibraryItem(const char* title, const int year)
	{
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		
		m_year = year;
	}

	LibraryItem::LibraryItem(const LibraryItem& copyOf_L)
	{
		m_title = nullptr;
		*this = copyOf_L;
	}

	LibraryItem& LibraryItem::operator=(const LibraryItem& copyOf_L)
	{
		if (this != &copyOf_L)
		{
			delete[] m_title;

			m_year = copyOf_L.m_year;

			if (copyOf_L.m_title != nullptr && copyOf_L.m_title[0] != '\0') 
			{
				m_title = new char[strlen(copyOf_L.m_title) + 1];
				strcpy(m_title, copyOf_L.m_title);
			}
			else 
			{
				m_title = nullptr;
			}
		}
		return *this;
	}

	LibraryItem::~LibraryItem()
	{
		delete[] m_title;
	}

	std::ostream& LibraryItem::display(std::ostream& out) const
	{
		out << "Title: " << m_title << " (" << m_year << ")";
		return out;
	}
}