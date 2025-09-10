/*
NAME: Ahmad Syed
STUDENTID: 102437233
EMAIL: asyed113@myseneca.ca
WORKSHOP 5 PART 1
DATE: 2/19/2024
*/
#ifndef SENECA_ABILITY_H
#define SENECA_ABILITY_H

namespace seneca 
{
	
	/// <summary>
	/// Stores a single ability
	/// </summary>
	class Ability 
	{
		// Ability Name (Static)
		char m_ability[100];

		// Ability Strength
		int m_abltyStrngth;
	public:

		/// <summary>
		/// Default Constructora
		/// </summary>
		Ability();
		
		/// <summary>
		/// Custom Constructor that validates the object before assigning the values to the members
		/// </summary>
		/// <param name="abilityName">Name of the Ability sent as a pointer and is const</param>
		/// <param name="abltyStrngth">Ability Strength sent as a int</param>
		Ability(const char* abilityName, int abltyStrngth);

		/// <summary>
		/// Function that returns the name of the ability
		/// </summary>
		/// <returns>Ability Name</returns>
		const char* getAbility() const;
		
		/// <summary>
		/// Function that returns the strength of ability
		/// </summary>
		/// <returns>Ability Strength</returns>
		int getAbltyStr() const;
	};
}





#endif // !SENECA_ABILITY_H

