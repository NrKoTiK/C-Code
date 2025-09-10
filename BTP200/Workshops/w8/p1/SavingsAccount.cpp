//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#include <iostream>
#include "SavingsAccount.h"

namespace seneca 
{
	SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance)
	{
		if (interest >= 0) 
		{
			m_interest = interest;
		}
		else 
		{
			m_interest = 0.0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double interestAdd = getBalance() * m_interest;
		setBalance(getBalance() + interestAdd);
	}
	void SavingsAccount::display(std::ostream& out) const
	{
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Account type: Savings\n";
		std::cout << "Balance: $" << getBalance() << '\n';
		std::cout << "Interest Rate (%): " << m_interest * 100 << '\n';
		std::cout.unsetf(std::ios::fixed);

	}
}