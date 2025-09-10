/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#include "book.h"

namespace seneca 
{
    Book::Book(const std::string title, const unsigned short year, const std::string summary, const std::string author, const std::string country, const double price) : MediaItem(title, summary, year)
    {
        m_author = author;
        m_country = country;
        m_price = price;
    }
    
    void Book::display(std::ostream& out) const
	{
        if (g_settings.m_tableView)
        {
            out << "B | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_country << " | ";
            out << std::setw(4) << this->getYear() << " | ";
            out << std::left;
            if (g_settings.m_maxSummaryWidth > -1)
            {
                if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                    out << this->getSummary();
                else
                    out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
            else
                out << this->getSummary();
            out << std::endl;
        }
        else
        {
            size_t pos = 0;
            out << this->getTitle() << " [" << this->getYear() << "] [";
            out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
	}

	Book* Book::createItem(const std::string& strBook)
	{
        std::string copyOfBookSTR = strBook;
        trim(copyOfBookSTR);
        if (copyOfBookSTR.empty() || copyOfBookSTR.c_str()[0] == '#') 
        {
            throw "Not a valid book.";
            return nullptr;
        }
        else 
        {
            std::istringstream stream(copyOfBookSTR);

            std::string author{};
            std::string title{};
            std::string country{};
            double price{};
            unsigned short year{};
            std::string summary{};
            int index = 0;
            std::string rs{};

            while ((index == 5) ? std::getline(stream, rs) : std::getline(stream, rs, ','))
            {
                /// AUTHOR,TITLE,COUNTRY,PRICE,YEAR,SUMMARY
                /// rs = result -- extracts all the objects
                trim(rs);
                if (index == 0) 
                {
                    author = rs;
                }   
                else if (index == 1)
                {
                    title = rs;
                }
                else if (index == 2)
                {
                    country = rs;
                }
                else if (index == 3)
                {
                    price = std::stod(rs);
                }
                else if (index == 4)
                {
                    year = static_cast<unsigned short>(std::atoi(rs.c_str()));
                }
                else if (index == 5) 
                {
                    summary = rs;
                }
                ++index;
            }
            Book* newBook = new Book(title, year, summary, author, country, price);
            return newBook;
        }
	}
}