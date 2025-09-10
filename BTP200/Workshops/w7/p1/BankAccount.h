//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include "DepositUtility.h"

namespace seneca 
{
	class BankAccount : public DepositInfo
	{
		/// <summary>
		/// static char name
		/// </summary>
		char m_name[100];

		/// <summary>
		/// obj type Date tells when account has been open.
		/// </summary>
		Date m_openDate;

		/// <summary>
		/// Holds some information about the account (institution name, bank transit code, account number)
		/// </summary>
		DepositInfo m_depInfo;

		/// <summary>
		/// Holds amount of money in account (double precision)
		/// </summary>
		double m_balance;

	protected:
		/// <summary>
		/// query that returns balance of account.
		/// </summary>
		/// <returns>m_balance</returns>
		const double getBalance() const;

		/// <summary>
		/// modifier that sets the m_balance to the value stored in parameter
		/// </summary>
		/// <param name="balance">amount to be set</param>
		void setBalance(double balance);

		/// <summary>
		/// its a display function (use out to output amount)
		/// </summary>
		/// <param name="out">output stream</param>
		/// <param name="amount">parameter to be outputted</param>
		/// <returns>out</returns>
		void writeCurrency(std::ostream& out, double amount) const;

	public:

		/// <summary>
		/// Custom constructor to set obj to a proper state
		/// </summary>
		/// <param name="name">name of the client</param>
		/// <param name="openDate">date open of account</param>
		/// <param name="depInfo">info on deposit</param>
		/// <param name="balance">amount of money in account</param>
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);

		/// <summary>
		/// query that inserts into ostream the contents of the current instance
		/// </summary>
		/// <param name="out">output stream</param>
		/// <returns>out</returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// reads data from "in" and stores it into the attributes of current instance
		/// </summary>
		/// <param name="in">input stream</param>
		/// <returns>in</returns>
		std::istream& read(std::istream& in);
	};

	/// <summary>
	/// read data from account using "in"
	/// </summary>
	/// <param name="in">input stream</param>
	/// <param name="account">obj for type bankaccount</param>
	/// <returns>in</returns>
	std::istream& operator>>(std::istream& in, BankAccount& account);

	/// <summary>
	/// Output the data from accounts 
	/// </summary>
	/// <param name="out">output stream</param>
	/// <param name="account">obj for type bankaccount</param>
	/// <returns>out</returns>
	std::ostream& operator<<(std::ostream& out, BankAccount& account);
}
#endif // !SENECA_BANKACCOUNT_H

