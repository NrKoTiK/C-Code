//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"

namespace seneca 
{
	class  ChequingAccount : public Account
	{
		double m_transactionFee;
		double m_monthlyFee;

	public:
		/// <summary>
		/// Constructor with initial account balance,
		/// double holding the transaction fee (MUST BE POSITIVE IF NOT ADD 0.0),
		/// double holding monthly fee (MUST BE POSITIVE IF NOT ADD 0.0),
		/// </summary>
		/// <param name="balance">initial account balance</param>
		/// <param name="transactionFee">transaction fee to be added to account balance</param>
		/// <param name="monthlyFee">month-end fees to be added to account balance</param>
		ChequingAccount(double balance, double transactionFee, double monthlyFee);

		~ChequingAccount() {};

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

		/// <summary>
		/// Applies transactions that are conducted at the end of the month to the account
		/// </summary>
		void monthEnd() override;

		/// <summary>
		/// Displays account information
		/// </summary>
		/// <param name="out">ostream obj</param>
		void display(std::ostream& out) const override;

	};

}

#endif // !SENECA_CHEQUINGACCOUNT_H

