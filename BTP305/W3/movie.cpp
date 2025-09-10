/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#include <sstream>
#include "movie.h"

namespace seneca 
{
    Movie::Movie(const std::string title, const std::string summary, unsigned short year) : MediaItem(title, summary, year) 
    {}

    void Movie::display(std::ostream& out) const
	{
        if (g_settings.m_tableView)
        {
            out << "M | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(9) << this->getYear() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "]\n";
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
    Movie* Movie::createItem(const std::string& strMovie)
    {
        std::string copyOfMovieSTR = strMovie;
        trim(copyOfMovieSTR);
        if (copyOfMovieSTR.empty() || copyOfMovieSTR.c_str()[0] == '#') 
        {
            throw "Not a valid movie.";
            return nullptr;
        }
        else 
        {
            std::istringstream stream(copyOfMovieSTR);

            int index = 0;
            std::string title{};
            unsigned short year{};
            std::string summary{};
            std::string rs{};
            
            while ((index == 2) ? std::getline(stream, rs) : std::getline(stream, rs, ','))
            {
                /// TITLE,YEAR,SUMMARY                
                trim(rs);
                if (index == 0) 
                {
                    title = rs;
                }
                else if (index == 1) 
                {
                    year = std::atoi(rs.c_str());
                }
                else if (index == 2) 
                {
                    summary = rs;
                }
                ++index;
            }
            Movie* newMov = new Movie(title, summary, year);
            return newMov;
        }
    }
}
