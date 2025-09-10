#include <iostream>
#include "SavingsAccount.h"
//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024

namespace seneca 
{
	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out << m_interest << '%';
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance)
	{
		m_interest = interest;
		m_interestDate = interestDate;
	}

	void SavingsAccount::applyInterest(const Date& today)
	{
		double accountBalance = BankAccount::getBalance();
		double interrestAdd = accountBalance * m_interest;
		double newBalance = accountBalance + interrestAdd;
		BankAccount::setBalance(newBalance);

		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "   $" << accountBalance << " + $" << interrestAdd << " (";
		std::cout.unsetf(std::ios::fixed);
		writeInterest(std::cout);
		
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << ") = $" << newBalance << " | " << m_interestDate
			<< " => " << today << '\n';
		m_interestDate = today;
		std::cout.unsetf(std::ios::fixed);
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | " << m_interestDate;
		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		BankAccount::read(in);
		std::cout << "Interest Date ";
		in >> m_interestDate;
		std::cout << "Interest Rate: ";
		in >> m_interest;
		return in;
	}

	std::istream& operator>>(std::istream& in, SavingsAccount& account)
	{
		account.read(in);
		return in;
	}

	std::ostream& operator<<(std::ostream& out, SavingsAccount& account)
	{
		account.write(out);
		return out;
	}

}
