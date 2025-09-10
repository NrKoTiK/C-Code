//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/19/2024
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca 
{
	class SavingsAccount : public Account 
	{
		double m_interest;
	public:

		/// <summary>
		/// Construct obj, recieves initial account balance, and interest that is to be applied onto account.
		/// If the interest rate is positive then it is store. else it stores 0.0 as rate to be applied
		/// </summary>
		/// <param name="balance"></param>
		/// <param name="interest"></param>
		SavingsAccount(double balance, double interest);

		~SavingsAccount() {};

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

#endif // !SENECA_SAVINGSACCOUNT_H
