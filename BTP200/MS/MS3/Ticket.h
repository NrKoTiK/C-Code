//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/27/2024
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca 
{
   class Ticket : public IOAble
   {
        /// <summary>
        /// The time the ticket was issued
        /// </summary>
        Time m_time;

        /// <summary>
        /// Ticket Number starts at 1 then ++.
        /// </summary>
        int m_number;
   public:
        Ticket();
       
        /// <summary>
        /// Creates obj by setting m_number
        /// </summary>
        /// <param name="number">a starting number to be set into datamember</param>
        Ticket(int number);

        /// <summary>
        /// A query that returns the time for when ticket issued
        /// </summary>
        /// <returns>time obj</returns>
        Time time() const;

        /// <summary>
        /// A query that returns the amount of tickents (int)
        /// </summary>
        /// <returns>amount of tickets</returns>
        int number() const;

        /// <summary>
        /// Sets time to current time
        /// </summary>
        void resetTime();

        /// <summary>
        /// Inserts a ticket into ostream to be displayed or displays csv format
        /// for time and ticket number  
        /// </summary>
        /// <param name="ostr">output stream</param>
        /// <returns>out</returns>
        std::ostream& write(std::ostream& out) const override;

        /// <summary>
        /// Extracts the ticket number and time in a csv format from input stream
        /// </summary>
        /// <param name="in">input stream</param>
        /// <returns>in</returns>
        std::istream& read(std::istream& in) override;
   };
}
#endif // !SENECA_TICKET_H_
