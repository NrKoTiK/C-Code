/*
NAME: Ahmad Syed
STUDENTID: 102437233
EMAIL: asyed113@myseneca.ca
WORKSHOP 5 PART 1
DATE: 2/19/2024
*/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "ability.h"

namespace seneca 
{
	class Hero 
	{
		// Hero Name (Static)
		char m_name[100];

		// Array of Object Abilities (Pointer)
		Ability* m_abilities;

		// Stores the number of Abilities Objects in Array
		int m_cntAbilities;

		// Stores the Level of the Hero. Higher the Level the Stronger the hero
		// value cant be less then 1 for a valid hero.
		int m_level;

	public:
		/// <summary>
		/// Default Constructor (Put Object into a default state)
		/// </summary>
		Hero();

		/// <summary>
		/// A custom Constructor that sets the object to a current state 
		/// validates the data then assigns (Hero starts at lvl 1)
		/// </summary>
		/// <param name="name">Has to be const Name of the Hero (Pointer)</param>
		/// <param name="abilities">Has to be const Array of Ability Objects a Hero has</param>
		/// <param name="cntAbilities">Number of Ability Objects in Array</param>
		Hero(const char* name, const Ability* abilities, int cntAbilities);

		/// <summary>
		/// Destructor cleans up the object and its resources
		/// </summary>
		~Hero();

		/// <summary>
		/// Returns the Name of the Hero
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// Returns the total strength. (The total strength is the sum of all the strengths of abilities multiplied by the lvl of hero)
		/// </summary>
		operator int() const;

		/// <summary>
		/// A modifier that adds a new ability to the array of abilities (adds 1 new ability to m_abilities)
		/// </summary>
		/// <param name="ability">Has to be const reference to obj type Ability</param>
		/// <returns>A reference to obj type Hero</returns>
		Hero& operator+=(const Ability& ability);

		/// <summary>
		/// A modifier that changes the level of the hero by the value recieved as parameter 
		/// (If parameter is a negative subtract a level but make sure it dosnt go below 1)
		/// </summary>
		/// <param name="lvlChange">Representing a number of levels to be added to a hero's level</param>
		/// <returns>A reference to the type Hero</returns>
		Hero& operator+=(int lvlChange);

		/// <summary>
		/// A modifier that increases the hero's level by 1
		/// </summary>
		/// <returns>A reference to the type Hero</returns>
		Hero& operator++();

		/// <summary>
		/// Prints to the screen the contents of current instance. In this format 
		/// HERO_NAME (lvl: HERO_LEVEL, str: TOTAL_HERO_STRENGTH)
		///	  - ABILITY_1 (ABILITY_1_STRENGTH)
		///	  - ABILITY_2 (ABILITY_2_STRENGTH)
		///	  - ...
		/// </summary>
		void display() const;
	};
	

	/// <summary>
	/// Compares hero 1 with hero 2
	/// </summary>
	/// <param name="h1">Has to be const hero 1</param>
	/// <param name="h2">Has to be const hero 2</param>
	/// <returns>Returns True if h1 strength is less than the strength of h2 otherwise false (RETURNS FALSE IF EQUAL)</returns>
	bool operator<(const Hero& h1, const Hero& h2);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="h1"></param>
	/// <param name="h2"></param>
	/// <returns>Returns True if h1 strength is greater than the strength of h2 otherwise false (RETURNS FALSE IF EQUAL)</returns>
	bool operator>(const Hero& h1, const Hero& h2);

	/// <summary>
	/// Adds ability into "hero"
	/// </summary>
	/// <param name="ability">Reference to obj type Ability</param>
	/// <param name="hero">Has to be const Reference to obj type Hero</param>
	void operator>>(const Ability& ability, Hero& hero);

	/// <summary>
	/// Adds ability into "hero"
	/// </summary>
	/// <param name="hero">Reference to an obj type Hero</param>
	/// <param name="ability">Has to be const Reference to an obj type Ability</param>
	void operator<<(Hero& hero, const Ability& ability);
}
#endif // !SENECA_HERO_H
