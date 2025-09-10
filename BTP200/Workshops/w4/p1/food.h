#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

namespace seneca
{
	struct Food
	{
		// for simplicity, we allow clients to directly access the data members
		//     and assume that any data they store into the attribute is valid
		char m_name[100 + 1];
		int m_weight;

		Food();
		Food(const char* name, int weight);
	};
}

#endif