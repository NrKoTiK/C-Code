//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 2/8/2024
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H
#include <iostream>
#include "food.h"

namespace seneca 
{
	class Fridge 
	{
		int m_capacity;
		char* m_model;
		Food* m_foods;
		int m_cntFoods;
		int getContentWeight() const;
	public:
		Fridge();
		Fridge(const char* model, int capacity);
		Fridge(const Food* foods, int cntFoods, const char* model, int capacity);
		~Fridge();
		bool addFood(const Food& aFood);
		void setModel(const char* model, int capacity);
		bool isFull() const;
		bool hasFood(const char* theFood = nullptr) const;
		std::ostream& display(std::ostream& out = std::cout) const;
	};
}
#endif // !SENECA_FRIDGE_H

