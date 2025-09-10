/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H
#include <vector>
#include <numeric>
#include <algorithm>
#include <list>
#include <sstream>
#include "mediaItem.h"

namespace seneca 
{
	class TvShow : public MediaItem 
	{
		/// <summary>
		/// Used int cus id increases +1
		/// </summary>
		std::string m_id{};

		/// <summary>
		/// Represents an EP
		/// </summary>
		struct TvEpisode
		{
			const TvShow* m_show{};
			unsigned short m_numberOverall{};
			unsigned short m_season{};
			unsigned short m_numberInSeason{};
			std::string m_airDate{};
			unsigned int m_length{};
			std::string m_title{};
			std::string m_summary{};
		};

		/// <summary>
		/// Used vector cus ep are supposed to be in sequence
		/// ----Array of EP
		/// </summary>
		std::vector<TvEpisode> m_episodes{};

		TvShow(const std::string& title, const std::string& summary, unsigned short year, std::string id);

	public:
		void display(std::ostream& out) const override;

		/// <summary>
		/// Builds object based on the parameter
		/// </summary>
		/// <param name="strShow">details about the TV Show in str format</param>
		/// <returns>pointer to the obj</returns>
		static TvShow* createItem(const std::string& strShow);

		/// <summary>
		/// Builds the episode based on the parameter
		/// </summary>
		/// <typeparam name="Collection_t">collection of type TV show based on ID</typeparam>
		/// <param name="col">collection of tv shows</param>
		/// <param name="strEpisode">details of episode</param>
		template<typename Collection_t> static void addEpisode(Collection_t& col, const std::string& strEpisode);

		/// <summary>
		/// get the average length in seconds of an episode. (MUST BE DONE W STL::ALGORITHMS)
		/// </summary>
		/// <returns>the avg length in seconds</returns>
		double getEpisodeAverageLength() const;
		
		/// <summary>
		/// create a list with episode names that are at least 1 hour long. (MUST BE DONE W STL::ALGORITHMS)
		/// </summary>
		std::list<std::string> getLongEpisodes() const;

	};

	TvShow::TvShow(const std::string& title, const std::string& summary, unsigned short year, std::string id) : MediaItem(title, summary, year) {
		m_id = id;
	}

	void TvShow::display(std::ostream& out) const
	{
		if (g_settings.m_tableView)
		{
			out << "S | ";
			out << std::left << std::setfill('.');
			out << std::setw(50) << this->getTitle() << " | ";
			out << std::right << std::setfill(' ');
			out << std::setw(2) << this->m_episodes.size() << " | ";
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
			out << this->getTitle() << " [" << this->getYear() << "]\n";
			out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
			while (pos < this->getSummary().size())
			{
				out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
				pos += g_settings.m_maxSummaryWidth;
			}
			for (auto& item : m_episodes)
			{
				out << std::setfill('0') << std::right;
				out << "    " << 'S' << std::setw(2) << item.m_season
					<< 'E' << std::setw(2) << item.m_numberInSeason << ' ';
				if (item.m_title != "")
					out << item.m_title << '\n';
				else
					out << "Episode " << item.m_numberOverall << '\n';

				pos = 0;
				while (pos < item.m_summary.size())
				{
					out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
					pos += g_settings.m_maxSummaryWidth - 8;
				}
			}
			out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
				<< std::setfill(' ') << '\n';
		}
	}
	
	inline TvShow* TvShow::createItem(const std::string& strShow)
	{
		std::string copyOfTvSTR = strShow;
		trim(copyOfTvSTR);
		if (copyOfTvSTR.empty() || copyOfTvSTR.c_str()[0] == '#')
		{
			throw "Not a valid show.";
			return nullptr;
		}
		else
		{
			std::istringstream stream(copyOfTvSTR);
			int index = 0;
			std::string id{};
			std::string title{};
			unsigned short year{};
			std::string summary{};
			std::string rs{};

			while ((index == 3) ? std::getline(stream, rs) : std::getline(stream, rs, ','))
			{
				/// ID,TITLE,YEAR,SUMMARY
				trim(rs);
				if (index == 0) 
				{
					id = rs;
				}
				else if (index == 1)
				{
					title = rs;
				}
				else if (index == 2) 
				{
					year = static_cast<unsigned short>(std::atoi(rs.c_str()));
				}
				else if (index == 3) 
				{
					summary = rs;
				}
				++index;
			}
			TvShow* newShow = new TvShow(title, summary, year, id);
			return newShow;
		}
	}

	inline double TvShow::getEpisodeAverageLength() const
	{
		return std::accumulate(m_episodes.begin(), m_episodes.end(), 0, 
			[](unsigned int sum, const TvEpisode& ep)
			{
				return sum += ep.m_length;
			}) / m_episodes.size();
	}

	inline std::list<std::string> TvShow::getLongEpisodes() const
	{
		std::list<std::string> longEp;
		std::vector<TvEpisode> filteredEp;
		std::copy_if(m_episodes.begin(), m_episodes.end(), std::back_inserter(filteredEp), [](const TvEpisode& ep) 
			{				
				return ep.m_length > 3600;
			});
		std::transform(filteredEp.begin(), filteredEp.end(), std::back_inserter(longEp), [](const TvEpisode& ep) 
			{
				return ep.m_title;
			});
		return longEp;
	}

	template<typename Collection_t>
	inline void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode)
	{
		std::string copyOfepSTR = strEpisode;
		trim(copyOfepSTR);
		if (copyOfepSTR.empty() || copyOfepSTR.c_str()[0] == '#')
		{
			throw "Not a valid episode.";
		}
		else 
		{
			std::istringstream stream(copyOfepSTR);
			TvEpisode ep{};
			std::string epDetail{};
			std::string length0{};
			std::string length1{};
			std::string length2{};

			/// ID,EPISODE_NUMBER,SEASON_NUMBER,EPISODE_IN_SEASON,AIR_DATE,LENGTH,TITLE,SUMMARY
			std::getline(stream, epDetail, ',');
			std::string id = epDetail;
			trim(id);
			std::getline(stream, epDetail, ',');
			trim(epDetail);
			ep.m_numberOverall = static_cast<unsigned short>(std::stoi(epDetail));
			std::getline(stream, epDetail, ',');
			trim(epDetail);
			ep.m_season = (epDetail == "" ? 1 : static_cast<unsigned short>(std::stoi(epDetail)));
			std::getline(stream, epDetail, ',');
			trim(epDetail);
			ep.m_numberInSeason = static_cast<unsigned short>(std::stoi(epDetail));
			std::getline(stream, epDetail, ',');
			trim(epDetail);
			ep.m_airDate = epDetail;
			std::getline(stream, epDetail, ',');
			//edit it Needs to get 00:00:00 can be a 00.00.00
			trim(epDetail);
			length0 = epDetail.substr(0, 2);  //HR
			length1 = epDetail.substr(3, 2);  //MIN
			length2 = epDetail.substr(6, 2);  //SEC
			ep.m_length = static_cast<unsigned int>(std::stoi(length0) * 60 * 60) + (std::stoi(length1) * 60) + std::stoi(length2);
			std::getline(stream, epDetail, ',');
			trim(epDetail);
			ep.m_title = epDetail;
			std::getline(stream, epDetail);
			trim(epDetail);
			ep.m_summary = epDetail;

			for (size_t i = 0; i < col.size(); ++i)
			{
				TvShow* someShow = dynamic_cast<TvShow*>(col[i]);
				if (someShow != nullptr && id == someShow->m_id)
				{
					ep.m_show = someShow;
					someShow->m_episodes.push_back(ep);
					i = col.size();
				}
			}		
		}
	}
}

#endif // !SENECA_TVSHOW_H
