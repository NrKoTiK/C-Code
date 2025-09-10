//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/4/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "PreTriage.h"
#include "Time.h"
#include "Patient.h"
#include "TriagePatient.h"
#include "TestPatient.h"
#include "Menu.h"

namespace seneca
{
	// --Public Members--
	PreTriage::PreTriage(const char* fileName)
	{
		m_avgTimeC = 15;
		m_avgTimeT = 5;
		m_PinLine[g_maxNumLineUp - 1] = nullptr;
		m_DFileName = new char[strlen(fileName) + 1];
		strcpy(m_DFileName, fileName);
		m_numOfP = 0;
		load();
	}

	PreTriage::~PreTriage()
	{
		save();
		for (int i = 0; i < m_numOfP; ++i)
		{
			delete m_PinLine[i];
		}
		delete[] m_DFileName;
	}

	void PreTriage::run()
	{
		int choice = -1;
		Menu menu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		std::cout << std::endl;
		
		while (choice != 0)
		{
			menu >> choice;
			switch (choice)
			{
			case 1:
				registerp();
				break;

			case 2:
				admit();
				break;

			case 3:
				lineup();
				break;
			}
		}
	}

	// --Private Members--
	Time PreTriage::getWaitTime(const Patient& wTime) const
	{
		int count = 0;
		for (int i = 0; i < m_numOfP; ++i)
		{
			if (wTime.type() == m_PinLine[i]->type())
			{
				++count;
			}
		}
		return wTime.time() * count;
	}

	void PreTriage::setAverageWaitTime(const Patient& avgWaitTimeofP)
	{
		Time CT = CT.reset();
		Time PTT = avgWaitTimeofP.time();
		int PTN = avgWaitTimeofP.number();
		if (avgWaitTimeofP.type() == 'C') 
		{
			m_avgTimeC = ((CT - PTT) + (m_avgTimeC * (PTN - 1))) / PTN;
		}
		else 
		{
			m_avgTimeT = ((CT - PTT) + (m_avgTimeT * (PTN - 1))) / PTN;
		}
	}

	int PreTriage::indexOfFirstInLine(const char pType) const
	{
		int index = -1;
		for (int i = 0; i < m_numOfP; ++i)
		{
			if (m_PinLine[i]->type() == pType)
			{
				index = i;
				break;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		std::cout << "Loading data..." << std::endl;
		std::ifstream file;
		file.open(m_DFileName, std::ifstream::in);
		file >> m_avgTimeC;
		file.ignore(1000, ',');
		file >> m_avgTimeT;
		file.ignore(1000, '\n');

		Patient* p = nullptr;
		char type;
		m_numOfP = 0;
		while (file >> type && m_numOfP < g_maxNumLineUp)
		{
			file.ignore(1000, ',');
			if (type == 'C')
			{
				p = new TestPatient();
			}
			if (type == 'T')
			{
				p = new TriagePatient();
			}
			if (p->read(file))
			{
				m_PinLine[m_numOfP++] = p;
			}
		}
		if (file.peek() != EOF)
		{
			std::cout << "Warning: number of records exceeded " << g_maxNumLineUp << std::endl;
		}
		if (m_numOfP == 0)
		{
			std::cout << "No data or bad data file!" << std::endl;
		}
		else
		{
			std::cout << m_numOfP << " Records imported..." << std::endl;
		}
		file.close();
	}

	void PreTriage::save() const
	{
		std::cout << "Saving lineup..." << std::endl;
		std::ofstream file;
		file.open(m_DFileName, std::ofstream::out);
		file << m_avgTimeC << ',' << m_avgTimeT << '\n';
		if (file.fail())
		{
			std::cout << "No data or bad data file!" << std::endl;
		}
		int countC = 0;
		int countT = 0;
		for (int i = 0; i < m_numOfP; ++i)
		{
			m_PinLine[i]->write(file);
			file << '\n';
			if (m_PinLine[i]->type() == 'C')
			{
				++countC;
			}
			if (m_PinLine[i]->type() == 'T')
			{
				++countT;
			}
		}
		std::cout << countC << " Contagion Tests and "
			<< countT << " Triage records were saved!" << std::endl;
		file.close();
	}

	void PreTriage::registerp()
	{

	}

	void PreTriage::admit()
	{
		Menu subMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
		int choice = -1;
		subMenu >> choice;

		char type = 'A';
		if (choice == 1)
		{
			type = 'C';
		}
		else if (choice == 2)
		{
			type = 'T';
		}
		if (choice != 0)
		{
			int index = indexOfFirstInLine(type);
			if (index == -1)
			{
				std::cout << "Line up is empty!\n";
			}
			else 
			{
				Time CT;
				std::cout << "\n******************************************\n";
				std::cout << "Call time: [";
				std::cout << CT.reset() << "]\n";
				std::cout << "Calling at for ";
				std::cout << *m_PinLine[index];
				std::cout << "******************************************\n\n";
				setAverageWaitTime(*m_PinLine[index]);
				removeDynamicElement(m_PinLine, index, m_numOfP);
			}
		}

	}

	void PreTriage::lineup() const
	{
		if (m_numOfP >= g_maxNumLineUp)
		{
			std::cout << "Line up full!" << std::endl;
		}
		Menu subMenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		int choice = -1;
		subMenu >> choice;

		char type = 'A';
		if (choice == 1)
		{
			type = 'C';
		}
		else if (choice == 2)
		{
			type = 'T';
		}
		if (choice != 0)
		{
			std::cout << "Row - Patient name                                          OHIP     Tk #  Time\n";
			std::cout << "-------------------------------------------------------------------------------\n";

			if (m_numOfP <= 0)
			{
				std::cout << "Line up is empty!\n";
			}
			else
			{
				int sequence = 1;
				for (int i = 0; i < m_numOfP; ++i)
				{
					if (m_PinLine[i]->type() == type)
					{
						std::clog.setf(std::ios::left);
						std::clog << std::setw(4)
							<< sequence++;
						std::clog.unsetf(std::ios::left);
						std::clog << "- ";
						m_PinLine[i]->write(std::clog);
						std::clog << '\n';
					}
				}
			}
			std::cout << "-------------------------------------------------------------------------------\n";
		}
	}
}