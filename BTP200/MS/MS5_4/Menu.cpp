//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
namespace seneca
{
	seneca::Menu::Menu()
	{
		m_content = nullptr;
		m_contentcnt = 0;
		m_indentation = 0;
	}

	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		int counter = 0;
		m_content = new char[strlen(menuContent) + 1];
		strcpy(m_content, menuContent);
		for (unsigned int i = 0; i < strlen(m_content); ++i)
		{
			if (m_content[i] == '\n')
			{
				++counter;
			}
		}
		m_contentcnt = counter;
		m_indentation = numberOfTabs;
	}
	
	Menu::~Menu()
	{
		delete[] m_content;
	}
	
	int Menu::display() const
	{
		int userinput = 0;
		indent();
		for (unsigned int i = 0; i < strlen(m_content); ++i)
		{
			std::cout << m_content[i];
			if (m_content[i] == '\n')
			{
				indent();
			}
		}
		std::cout << std::endl;
		indent();
		std::cout << "0- Exit" << std::endl;
		indent();
		std::cout << "> ";
		std::cin >> userinput;
		bool correct = false;
		while (!correct)
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Bad integer value, try again: ";
				std::cin >> userinput;
			}
			else if (std::cin.peek() == ' ')
			{
				std::cout << "Only enter an integer, try again: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin >> userinput;
			}
			else if (userinput < 0 || userinput > m_contentcnt)
			{
				std::cout << "Invalid value enterd, retry[0 <= value <= " << m_contentcnt << "]: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin >> userinput;
			}
			else
			{
				correct = true;
			}
		}
		return userinput;
	}

	int& Menu::operator>>(int& selection)
	{
		selection = display();
		return selection;
	}

	void Menu::indent() const
	{
		for (int i = 0; i < m_indentation; ++i) 
		{
			std::cout << "   ";
		}
	}
}