/*
Ahmad Hasnain Syed
102437233
asyed113@myseneca.ca
1/23/2024
*/

#include <iostream>
#include "mark.h"
#include "file.h"
#include "graph.h"
#include "io.h"

using namespace seneca;
using namespace std;
namespace seneca
{
	bool printReport(const char* filename)
	{
		bool retValue = true;
		if (seneca::openFile(filename))
		{
			Mark marks[MAX_NO_RECS];
			int count = readAllMarks(marks);

			int interval[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int gradeIndex[11] = { -1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
			for (int i = 0; i < count; i++)
			{
				for (int j = 9; j >= 0; j--)
				{
					if (gradeIndex[j] < marks[i].m_mark && marks[i].m_mark <= gradeIndex[j + 1])
					{
						interval[9 - j] += 1;
						break;  // Exit the loop as soon as the correct interval is found
					}
				}
			}
			printGraph(interval, 10, "Students' Mark Distribution");
			markSort(marks, count);
			for (int i = 0; i < count; i++) 
			{
				printInt(i + 1, 3);
				cout << ": [";
				printInt(marks[i].m_mark, 3);
				cout  << ']' << ' ' << marks[i].m_firstName << ' ' << marks[i].m_lastName << "\n";
			}
			cout << "----------------------------------------\n";
			closeFile();
		}
		else 
		{
			retValue = false;
		}
		return retValue;
	}
	void markSort(Mark marks[], int count)
	{
		int i, j;
		Mark temp;
		for (i = count - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (marks[j].m_mark < marks[j + 1].m_mark)
				{
					temp = marks[j];
					marks[j] = marks[j + 1];
					marks[j + 1] = temp;
				}
			}
		}
	}
}