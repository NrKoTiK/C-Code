/*
NAME: Ahmad Syed
STUDENTID: 102437233
EMAIL: asyed113@myseneca.ca
WORKSHOP 5 PART 1
DATE: 2/14/2024
*/

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

namespace seneca 
{
	class BankAccount
	{
		// 100 char representing username (If empty account considered not open). 
		char m_username[100];
		
		// Holds how much money (Must be in Double decimal precision).
		double m_balance;
		
		// True if: checking account; Else False if: Saving Accounts.
		bool m_checking;
		
		// int that holds number of transactions (deposits and withdrawals) on a single account.
		int m_transactions;

	public:
		/// <summary>
		/// Custom Constructor that initializes the current instance with the values of the parameters.
		/// </summary>
		/// <param name="name">The address of an unmodeifiable C-string representing the account owner. By Defualt this parameter is NULL</param>
		/// <param name="checking">A boolean value that stores if this account is a checking or savings account. By defualt this parameter is false</param>
		BankAccount(const char* name = nullptr, bool checking = false);

		/// <summary>
		/// A query that prints to screen the contect of the current instance.
		/// </summary>
		void display() const;

		/// <summary>
		/// The conversion to bool operator is a query that returns true if the account is open, false otherwise.
		/// </summary>
		operator bool() const;

		/// <summary>
		/// The conversion to double operator is a query that returns the balance from the current account if the account is open or "std::nan("")" 
		/// (This is a special value that means not a number) if the account is not open.
		/// </summary>
		operator double() const;

		/// <summary>
		/// The conversion to string operator is a query that returns address of the account owner attribute if the account is open or "Not Open" 
		/// if the account is not open. 
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// The conversion to int operator is a query that returns the number of transactions performed in this account if the account is open or -1 
		/// if the account is not open. 
		/// </summary>
		operator int() const;

		/// <summary>
		/// A modifier that adds to the balance the amount received as parameter.
		/// </summary>
		/// <param name="amount">A floating point number in double precision that represents how much money should be added to the balance</param>
		/// <returns>A reference to the current instance</returns>
		BankAccount& operator+=(double amount);

		/// <summary>
		/// A modifier that withdraws from the balance the amount recieved as parameter.
		/// </summary>
		/// <param name="amount">A floating point number in double precision that represents how much money should be removed from the balance</param>
		/// <returns>A reference to the current instance</returns>
		BankAccount& operator-=(double amount);

		/// <summary>
		/// A query that creates a new account and adds to it the amount specifed as parameter
		/// </summary>
		/// <param name="amount">A floating point number in double precision that represents how much money should be added to the balance of the new account</param>
		/// <returns>an object of type BankAccount</returns>
		BankAccount operator+(double amount) const;

		/// <summary>
		/// The prefix increment in a modifier that adds the interest to the account balance.
		/// </summary>
		/// <returns>A reference to the current instance</returns>
		BankAccount& operator++();

		/// <summary>
		/// The postfix increment is a modifier that adds the interest to the account balance
		/// </summary>
		/// <param name="">This is a dummy parameter to help distinguish prefix/postfix</param>
		/// <returns>An object type BankAccount</returns>
		BankAccount operator++(int);

		/// <summary>
		/// the greater-than comparison operator is a query that compares the balnce from the current instance with the amount specified as parameter
		/// </summary>
		/// <param name="amount">A floating point number in double precision</param>
		/// <returns>true if balance is greater than the parameter, false otherwise</returns>
		bool operator>(double amount) const;
	};

	/// <summary>
	/// the greater-than comparison operator compares amount specified in the first parameter with the balance of the account specified in the second parameter.
	/// </summary>
	/// <param name="amount">A floating point number in double precision</param>
	/// <param name="account">An unmodifiable reference to an object of type BankAccount</param>
	/// <returns>True if the first parameter is greater than the balance of the second parameter, false otherwise</returns>
	bool operator>(double amount, const BankAccount& account); 
}





#endif // !SENECA_BANKACCOUNT_H

