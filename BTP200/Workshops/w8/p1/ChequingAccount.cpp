//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#include <iostream>
#include "ChequingAccount.h"

namespace seneca 
{
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account(balance)
	{
		if (transactionFee > 0) 
		{
			m_transactionFee = transactionFee;
		}
		else 
		{
			m_transactionFee = 0.0;
		}

		if (monthlyFee > 0) 
		{
			m_monthlyFee = monthlyFee;
		}
		else 
		{
			m_monthlyFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double balance)
	{	
		//bool success = ;
		int accountBalance = 0;
		accountBalance = ((getBalance() + balance) - m_transactionFee) + (1.0);
		setBalance(accountBalance);
		return true;
	}

	bool ChequingAccount::debit(double balance)
	{
		int accountBalance = 0;
		accountBalance = (getBalance() - balance - m_transactionFee);
		setBalance(accountBalance);
		return true;
	}

	void ChequingAccount::monthEnd()
	{
		int accountBalance = 0;
		accountBalance = getBalance() - m_monthlyFee;
		setBalance(accountBalance);
	}

	void ChequingAccount::display(std::ostream& out) const
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Account type: Chequing\n";
		std::cout << "Balance: $" << getBalance() << '\n';
		std::cout << "Per Transaction Fee: " << m_transactionFee << '\n';
		std::cout << "Monthly Fee: " << m_monthlyFee << '\n';
		std::cout.unsetf(std::ios::fixed);
	}
}