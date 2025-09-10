//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/9/2024

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BankAccount.h"


namespace seneca
{
    const double BankAccount::getBalance() const
    {
        return m_balance;
    }

    void BankAccount::setBalance(double balance)
    {
        m_balance = balance;
    }

    void BankAccount::writeCurrency(std::ostream& out, double amount) const
    {            
        out.setf(std::ios::fixed);
        out.precision(2);
        out << '$' << amount;
        out.unsetf(std::ios::fixed);
    }

    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
    {
        strcpy(m_name, name);
        m_openDate = openDate;
        m_depInfo = depInfo;
        m_balance = balance;
    }

    std::ostream& BankAccount::write(std::ostream& out) const
    {
        out << ">> " << m_name << " | "; 
        writeCurrency(out, m_balance);
        out << " | " << m_openDate << " | " << m_depInfo;
        return out;
    }
    
    std::istream& BankAccount::read(std::istream& in)
    {
        std::cout << "Name: ";
        in.getline(m_name, 150, '\n');
        std::cout << "Opening Balance: ";
        in >> m_balance;
        std::cout << "Date Opened ";
        in >> m_openDate;
        in >> m_depInfo;
        return in;
    }

    std::istream& operator>>(std::istream& in, BankAccount& account)
    {
        account.read(in);
        return in;
    }

    std::ostream& operator<<(std::ostream& out, BankAccount& account)
    {
        account.write(out);
        return out;
    }
}