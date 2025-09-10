//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/3/2024

#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H
#include "email.h"

namespace seneca 
{
	class Inbox 
	{
		/// <summary>
		/// Array of object emails (I MUST DEALLOCATE IT)
		/// </summary>
		Email* m_emails;

		/// <summary>
		/// The number of obj emails (This keeps count of that)
		/// </summary>
		int m_cntEmails;

	public:
		/// <summary>
		/// Sets the current instance to empty state
		/// </summary>
		Inbox();

		/// <summary>
		/// Copy constructor to set new obj to the same state as current instance
		/// </summary>
		/// <param name="copyOf_I">New Inbox object</param>
		Inbox(const Inbox& copyOf_I);

		/// <summary>
		/// Copies data from current obj into another object (vise versa)
		/// </summary>
		/// <param name="copyOf_I">Another Inbox object</param>
		/// <returns></returns>
		Inbox& operator=(const Inbox& copyOf_I);

		~Inbox();

		/// <summary>
		/// Adds to inbox 1 email at a time.
		/// </summary>
		/// <param name="email">A single email that is to be added into inbox</param>
		/// <returns>returns a reference to the current instance</returns>
		Inbox& operator+=(const Email& email);

		/// <summary>
		/// A query that creates a new inbox object (COPY OF THE CURRENT INSTANCE)
		/// and add to it the email recieved as parameter
		/// </summary>
		/// <param name="email">A single email that will be added into the new object</param>
		/// <returns>the new made object</returns>
		Inbox operator+(const Email& email) const;

		/// <summary>
		/// A modifier that loads a collection of emails froms a file and adds them to the current instance (resize the array if necessay) 
		/// </summary>
		/// <param name="filename">name of the file that contains all the emails</param>
		void load(const char* filename);

		/// <summary>
		/// a query that saves into the file all the emails stored in the inbox
		/// </summary>
		/// <param name="filename">name of the file on where to save the data</param>
		void save(const char* filename) const;

		/// <summary>
		/// Overload the insertion to insert an Inbox object into "out".
		/// </summary>
		/// <param name="out">a reference to output stream</param>
		/// <param name="inbox">unmod reference to object Inbox</param>
		/// <returns>out</returns>
		friend std::ostream& operator<<(std::ostream& out, const Inbox& inbox);
	};
}
#endif // !SENECA_INBOX_H

