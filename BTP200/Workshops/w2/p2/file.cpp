#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "file.h"

//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 1/13/2024


namespace seneca 
{
	FILE* g_fptr;
	bool openFile(const char* filename)
	{
		bool allGood = false;
		if (g_fptr == nullptr) 
		{
			g_fptr = fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	void closeFile()
	{
		if (g_fptr) 
		{
			fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	int getRecordsCount()
	{
		int noOfRecs = -1;

		if (g_fptr != nullptr)
		{
			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}

	char* read(char delim)
	{
		int count = 0;
		long pos = std::ftell(g_fptr);
		char ch;
		while (std::fscanf(g_fptr, "%c", &ch) == 1 && delim != ch)
		{
			count++;
		}
		std::fseek(g_fptr, pos, SEEK_SET);

		char* aRR = nullptr;
		aRR = new char[count + 1];

		int i = 0;
		while (std::fscanf(g_fptr, "%c", &ch) == 1 && delim != ch)
		{
			aRR[i] = ch;
			i++;
		}
		aRR[count] = '\0';
		return aRR;
	}

	bool read(int& val, char delim)
	{
		bool TorF = false;
		char* aRRAddrs = seneca::read(delim);
		if (aRRAddrs != nullptr)
		{
			val = std::atoi(aRRAddrs);
			delete[] aRRAddrs;
			TorF = true;
		}
		return TorF;
	}
}
