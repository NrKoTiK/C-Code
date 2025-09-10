/*
- Syed Ahmad Hasnain,
- 102437233,
- asyed113@myseneca.ca
- 11/20/2024
*/
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca 
{	
	struct Settings 
	{
		short m_maxSummaryWidth{};
		bool m_tableView{ false };
	};
	
	extern Settings g_settings;
}
#endif // !SENECA_SETTINGS_H
