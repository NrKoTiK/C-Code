/*
NAME: Ahmad Syed
STUDENTID: 102437233
EMAIL: asyed113@myseneca.ca
WORKSHOP 5 PART 1
DATE: 2/14/2024
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include "bankAccount.h"

namespace seneca 
{
	seneca::BankAccount::BankAccount(const char* name, bool checking)
	{
		m_balance = 0;
		m_checking = checking;
		m_transactions = 0;
		if (name != nullptr && name[0] != '\0')
		{
			std::strcpy(m_username, name);
		}
		else 
		{
			m_username[0] = '\0';
		}
	}

	void BankAccount::display() const
	{
		if (*this && m_checking == true) 
		{
			std::cout << m_username << " -> $" << m_balance << " in checking account.\n";
		}
		if (*this && m_checking == false) 
		{
			std::cout << m_username << " -> $" << m_balance << " in saving account.\n";
		}
	}
	BankAccount::operator bool() const
	{
		bool accountOpen = false;
		if (m_username[0] != '\0') 
		{
			accountOpen = true;
		}
		return accountOpen;
	}

	BankAccount::operator double() const
	{
		if (*this) 
		{
			return m_balance;
		}
		else 
		{
			return std::nan("");
		}
	}

	BankAccount::operator const char* () const
	{
		if (*this) 
		{
			return m_username;
		}
		else 
		{
			return "Not Open";
		}
	}

	BankAccount::operator int() const
	{
		if (*this) 
		{
			return m_transactions;
		}
		else 
		{
			return -1;
		}
	}

	BankAccount& BankAccount::operator+=(double amount)
	{
		if (*this) 
		{
			m_balance += amount;
			++m_transactions;
		}
		return *this;
	}

	BankAccount& BankAccount::operator-=(double amount)
	{
		return *this += -1 * amount;
	}

	BankAccount BankAccount::operator+(double amount) const
	{
		BankAccount result = *this;
		result += amount;
		return result;
	}

	BankAccount& BankAccount::operator++()
	{
		if (*this) 
		{
			if (m_balance > 0 && m_checking == true) 
			{
				m_balance += m_balance * 0.005;
			}
			if (m_balance > 0 && m_checking == false) 
			{
				m_balance += m_balance * 0.025;
			}
		}
		return *this;
	}

	BankAccount BankAccount::operator++(int)
	{
		BankAccount result = *this;
		++(*this);
		return result;
	}

	bool BankAccount::operator>(double amount) const
	{
		bool greater = false;
		if (*this) 
		{
			if (m_balance > amount) 
			{
				greater = true;
			}
		}
		return greater;
	}

	bool operator>(double amount, const BankAccount& account)
	{
		return amount > account.operator double();
	}

}
