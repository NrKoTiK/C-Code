#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

namespace seneca 
{
	Book::Book(const char* title, const int year, const char* author) : LibraryItem(title, year)
	{
		m_author = new char[strlen(author) + 1];
		strcpy(m_author, author);
	}
	Book::Book(const Book& copyOf_B)
	{
		m_author = nullptr;
		*this = copyOf_B;
	}
	Book& Book::operator=(const Book& copyOf_B)
	{
		// Calling the copy assignment from base class casting to the base class 
		(LibraryItem&)*this = (const LibraryItem&)copyOf_B;
		if (this != &copyOf_B)
		{
			delete[] m_author;

			if (copyOf_B.m_author != nullptr && copyOf_B.m_author[0] != '\0') 
			{
				m_author = new char[strlen(copyOf_B.m_author) + 1];
				strcpy(m_author, copyOf_B.m_author);
			}
			else 
			{
				m_author = nullptr;
			}
		}
		return *this;
	}
	Book::~Book()
	{
		delete[] m_author;
	}
	std::ostream& Book::display(std::ostream& out) const
	{
		this->LibraryItem::display(out);
		out << "\nAuthor: " << m_author;
		return out;
	}
	bool Book::operator>(const Book& other) const
	{
		bool lexi = false;
		if (strcmp(m_author, other.m_author) > 0) 
		{
			lexi = true;
		}
		return lexi;
	}
}

