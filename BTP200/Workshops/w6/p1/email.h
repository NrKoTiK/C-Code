//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/3/2024

#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H

namespace seneca
{
	class Email 
	{
		/// <summary>
		/// A statically allocated array of 100 characters representing the name of the person who sends the email.
		/// </summary>
		char m_fromName[100];
		
		/// <summary>
		/// A statically allocated array of 100 characters representing the email address of the person who sends the email.
		/// </summary>
		char m_fromAddress[100];
		
		/// <summary>
		/// as a statically allocated array of 20 characters represenitng the date and time when the email has been recieved 
		/// the date and time field will have the format (YYYY-MM-DD HH:MM:SS).
		/// </summary>
		char m_dateReceived[20];

		/// <summary>
		/// A pointer that represents the subject of the email. RESOURCE I HAVE TO MANAGE!!
		/// </summary>
		char* m_subject;

	public:
		/// <summary>
		/// Set the current instance to an empty state.
		/// </summary>
		Email();

		/// <summary>
		/// Copies data from Email to the newly created object.
		/// </summary>
		/// <param name="copyOf_E">New Email object</param>
		Email(const Email& copyOf_E);

		/// <summary>
		/// Copies data from current instance into another instance (vice versa)
		/// </summary>
		/// <param name="copyOf_E">Another email object (That can be full of data)</param>
		/// <returns>return the current instance</returns>
		Email& operator=(const Email& copyOf_E);

		/// <summary>
		/// destroy this obj
		/// </summary>
		~Email();

		/// <summary>
		/// Checks if obj is in valid state
		/// </summary>
		//operator bool() const;

		/// <summary>
		/// A modifier that loads data from the input stream and stores it into the current instance
		/// Format of the info: (FROM_ADDRESS,FROM_NAME,SUBJECT,DATE)
		/// </summary>
		/// <param name="in">Is used to load data from the input stream (am guessing file)?</param>
		/// <returns>true if data was successfully loaded; false otherwise</returns>
		bool load(std::istream& in);
	
		/// <summary>
		/// Overload the insertion to insert an email object into the first parameter.
		/// </summary>
		/// <param name="out">Reference to an output stream</param>
		/// <param name="email">a un-modifiable reference to an object of type Email</param>
		/// <returns>returns "out"</returns>
		friend std::ostream& operator<<(std::ostream& out, const Email& email);
	};
}
#endif // !SENECA_EMAIL_H

