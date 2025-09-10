//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"

namespace seneca 
{
	class Account : public iAccount
	{
		double m_balance;

	protected:

		/// <summary>
		/// setter for m_balance
		/// </summary>
		void setBalance(double balance);

		/// <summary>
		/// getter for m_balance
		/// </summary>
		/// <returns>m_balance</returns>
		double getBalance() const; 

	public:

		/// <summary>
		/// Sets state of obj
		/// </summary>
		/// <param name="balance">account balance passed as parameter to set obj</param>
		Account(double balance);
		
		~Account() {};

		/// <summary>
		/// Adds a positive amount to the balance
		/// </summary>
		/// <param name="balace">Some positive amount to be added</param>
		/// <returns>T or F if task was successful</returns>
		bool credit(double balance) override;

		/// <summary>
		/// Subtracts a positive amount from the Balace
		/// </summary>
		/// <param name="balance">Some positive amount to be subtracted</param>
		/// <returns>T or F if task was successfu</returns>
		bool debit(double balance) override;

	};
}

#endif // !SENECA_ACCOUNT_H

