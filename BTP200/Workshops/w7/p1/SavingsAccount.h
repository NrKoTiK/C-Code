//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024

#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca 
{
	class SavingsAccount : public BankAccount
	{
		/// <summary>
		/// interest rate that should be applied (double precision) 
		/// [number between 0 and 1] - it is the percentage the account
		/// gains in interest every month.
		/// </summary>
		double m_interest; 

		/// <summary>
		/// Date when interest was applied
		/// </summary>
		Date m_interestDate;

		/// <summary>
		/// outputs the interest rate stored in current instance
		/// </summary>
		/// <param name="out">output</param>
		void writeInterest(std::ostream& out) const;
	
	public:
		/// <summary>
		/// Sets obj to functional state
		/// </summary>
		/// <param name="name">name of the account holder</param>
		/// <param name="openDate">date repping when account open</param>
		/// <param name="depInfo">extra info on account</param>
		/// <param name="balance">amount of money in account</param>
		/// <param name="interest">interest to be applied on account</param>
		/// <param name="interestDate">date for when the interest was applied</param>
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);

		/// <summary>
		/// increases the account balance by adding interest
		/// </summary>
		/// <param name="today">unmod ref to an obj Date</param>
		void applyInterest(const Date& today);

		/// <summary>
		/// outputs the data stored in current instance.
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// reads data from "in" and stores it in the current instance
		/// </summary>
		/// <param name="in">input stream</param>
		/// <returns>in</returns>
		std::istream& read(std::istream& in);
	};

	/// <summary>
	/// reads data using in from account
	/// </summary>
	/// <param name="in"></param>
	/// <param name="account">obj type account</param>
	/// <returns>in</returns>
	std::istream& operator>>(std::istream& in, SavingsAccount& account);

	/// <summary>
	/// outputs data stored in account
	/// </summary>
	/// <param name="out">output stream</param>
	/// <param name="account">obj type account</param>
	/// <returns>out</returns>
	std::ostream& operator<<(std::ostream& out, SavingsAccount& account);
}
#endif // !SENECA_SAVINGACCOUNT_H

