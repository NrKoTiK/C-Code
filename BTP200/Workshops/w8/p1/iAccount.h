//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
#include <iostream>

namespace seneca 
{
	class iAccount
	{
	public:

		/// <summary>
		/// Adds a positive amount to the balance
		/// </summary>
		/// <param name="balace">Some positive amount to be added</param>
		/// <returns>T or F if task was successful</returns>
		virtual bool credit(double balance) = 0;

		/// <summary>
		/// Subtracts a positive amount from the Balace
		/// </summary>
		/// <param name="balance">Some positive amount to be subtracted</param>
		/// <returns>T or F if task was successfu</returns>
		virtual bool debit(double balance) = 0;

		/// <summary>
		/// Applies transactions that are conducted at the end of the month to the account
		/// </summary>
		virtual void monthEnd() = 0;

		/// <summary>
		/// Displays account information
		/// </summary>
		/// <param name="out">ostream obj</param>
		virtual void display(std::ostream& out) const = 0;

		/// <summary>
		/// Virtual destrctor
		/// </summary>
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char* str, double balance);
}

#endif // !SENECA_IACCOUNT_H

