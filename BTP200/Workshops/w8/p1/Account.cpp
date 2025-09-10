//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#include "Account.h"

namespace seneca 
{
	Account::Account(double balance)
	{
		if (balance >= 0.0) 
		{
			m_balance = balance;
		}
		else 
		{
			m_balance = 0.0;
		}
	}

	void Account::setBalance(double balance)
	{
		if (balance >= 0.0)
		{
			m_balance = balance;
		}
		else
		{
			m_balance = 0.0;
		}
	}

	double Account::getBalance() const
	{
		return m_balance;
	}

	bool Account::credit(double balance)
	{
		bool success = false;
		if (balance >= 0)
		{
			m_balance += balance;
			success = true;
		}
		return success;
	}

	bool Account::debit(double balance)
	{
		bool success = false;
		if (balance >= 0) 
		{
			m_balance -= balance;
			success = true;
		}
		return success;
	}
}