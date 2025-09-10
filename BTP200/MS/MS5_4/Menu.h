//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "Time.h"
#include "Utils.h"

namespace seneca 
{
	class Menu 
	{
		char* m_content;
		int m_contentcnt;
		int m_indentation;
	
	public:
		
		/// <summary>
		/// Defualt constructor to set obj
		/// </summary>
		Menu();
		
		/// <summary>
		/// Constructor that initializes the menu object. Store "menuContent" into "m_content" 
		/// Then scans for amount of characters in "m_content" 
		/// </summary>
		/// <param name="menuContent">Dynamic char array stores menu contents</param>
		/// <param name="numberOfTabs">int that specifies the amount of indentation.</param>
		Menu(const char* menuContent, int numberOfTabs = 0);

		/// <summary>
		/// Copy constructor copy data from object.
		/// </summary>
		/// <param name="copyOf_M">Another Menu Object</param>
		Menu(const Menu& copyOf_M) = delete;

		/// <summary>
		/// Destroy obj
		/// </summary>
		~Menu();

		/// <summary>
		/// Copies data from current instance into another instance (vice versa)
		/// </summary>
		/// <param name="copyOf_M">Another Menu object</param>
		/// <returns>return current instance</returns>
		Menu& operator=(const Menu& copyOf_M) = delete;

		/// <summary>
		/// Displays the menu to console
		/// and allows the user to input.
		/// </summary>
		/// <returns>the user inputted value.</returns>
		int display() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Selection"></param>
		/// <returns></returns>
		int& operator>>(int& selection);

		void indent() const;
	};
}
#endif // !SENECA_MENU_H
