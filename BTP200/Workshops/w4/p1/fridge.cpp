//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 2/8/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "fridge.h"
#include "food.h"

using namespace std;
namespace seneca
{
	int seneca::Fridge::getContentWeight() const
	{
		int totalWeight = 0;
		for (int i = 0; i < m_cntFoods; i++) 
		{
			totalWeight += m_foods[i].m_weight;
		}

		return totalWeight;
	}

	seneca::Fridge::Fridge()
	{
		m_capacity = 0;
		m_cntFoods = 0;
		m_model = nullptr;
		m_foods = nullptr;
	}

	seneca::Fridge::Fridge(const char* model, int capacity)
	{
		*this = Fridge();
		Fridge::setModel(model, capacity);
	}

	seneca::Fridge::Fridge(const Food* foods, int cntFoods, const char* model, int capacity)
	{
		*this = Fridge();
		Fridge::setModel(model, capacity);
		if (m_model != nullptr)
		{
			for (int i = 0; i < cntFoods; i++)
			{
				addFood(foods[i]);
			}
		}
	}

	seneca::Fridge::~Fridge()
	{
		delete[] m_foods;
		delete[] m_model;
	}

	bool seneca::Fridge::addFood(const Food& aFood)
	{
		bool foodAdded = false;
		int totalWeight = Fridge::getContentWeight();
		if ((totalWeight + aFood.m_weight) <= m_capacity)
		{
			seneca::Food* tmp = new Food[m_cntFoods + 1];
			for (int i = 0; i < m_cntFoods; i++)
			{
				tmp[i] = m_foods[i];
			}
			delete[] m_foods;
			tmp[m_cntFoods] = aFood;
			m_foods = tmp;
			++m_cntFoods;
			foodAdded = true;
		}
		return foodAdded;
	}

	void seneca::Fridge::setModel(const char* model, int capacity)
	{
		if ((model != nullptr || model[0] != '\0') && capacity >= 10)
		{
			delete[] m_model;
			char* tmp = new char[strlen(model) + 1];
			strcpy(tmp, model);
			m_model = tmp;
			m_capacity = capacity;
		}
	}

	bool seneca::Fridge::isFull() const
	{
		bool notEpty = false;
		float totalWeight = Fridge::getContentWeight();
		if (totalWeight / (float)m_capacity >= 0.9)
		{
			notEpty = true;
		}
		return notEpty;
	}

	bool seneca::Fridge::hasFood(const char* theFood) const
	{
		bool foodValid = false;
		if (theFood == nullptr && m_cntFoods > 0)
		{
			foodValid = true;
		}
		else
		{
			for (int i = 0; i < m_cntFoods; i++)
			{
				if (strcmp(m_foods[i].m_name, theFood) == 0)
				{
					foodValid = true;
				}
			}
		}
		return foodValid;
	}

	std::ostream& seneca::Fridge::display(std::ostream& out) const
	{
		if (m_model == nullptr)
		{
			std::cout << "The fridge object is in an empty state.\n";
		}
		else
		{
			out.width(19);
			out.setf(ios::right);
			out << "Fridge model: " << m_model << '\n';
			out.width(19);
			out << "Fridge capacity: " << m_capacity << "kg\n";
			out.width(19);
			out << "Fill percentage: " << ((100*getContentWeight())/m_capacity) << "% full\n";
			out << "The list of foods:\n";
			for (int i = 0; i < m_cntFoods; i++)
				out << "  - " << m_foods[i].m_name << " (" << m_foods[i].m_weight << "kg)" << '\n';
			out.unsetf(ios::right);
		}
		return out;
	}
}
