//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 1/13/2024
#include <iostream>
#include <cstring>
#include "Movie.h"
#include "DataHandle.h"
// TD: include any other header that is necessary for your solution

using namespace std;
namespace seneca
{
	// TD: put everything in the `seneca` namespace

	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	Movie* g_colMovies = nullptr;

	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	int g_cntMovies = 0;

	bool loadData(const char* filename)
	{
		bool reTorF = false;
		if (g_colMovies != nullptr) 
		{
			seneca::deallocateMemory();
		}
		if (!seneca::openFile(filename)) 
		{
			reTorF = false;
		}
		else 
		{
			g_cntMovies = seneca::getRecordsCount();
			g_colMovies = new Movie[g_cntMovies];
			for (int i = 0; i < g_cntMovies; i++)
			{
				seneca::loadData(g_colMovies[i]);	
			}
			reTorF = true;
		}
		closeFile();
		return reTorF;
	}

	bool loadData(Movie &aMovie)
	{  
		bool running = false;
		running = seneca::read(aMovie.m_budget);
		running = seneca::read(aMovie.m_grossIncome);
		running = seneca::read(aMovie.m_rating);
		aMovie.m_title = seneca::read('\n');
		if (aMovie.m_title == nullptr) 
		{
			running = false;
		}
		return running;
	}
		
	void display(int idx)
	{
		if (0 <= idx && idx < g_cntMovies) 
		{
			cout << g_colMovies[idx].m_title; 
			cout << ", " << g_colMovies[idx].m_budget;
			cout << ", $" << g_colMovies[idx].m_grossIncome;
			cout << ", " << g_colMovies[idx].m_rating << endl;
		}
		else 
		{
			cout << "Index out of bounds.\n";
		}
	}

	void display(const char* label, int startIdx, int endIdx)
	{
		cout << "******** " << label << " ****************\n";
		for (int i = startIdx; i <= endIdx && i < g_cntMovies; ++i) 
		{
			cout << ">> ";
			seneca::display(i);
		}
	}

	void deallocateMemory()
	{
		for (int i = 0; i < g_cntMovies; i++)
		{
			delete[] g_colMovies[i].m_title;
		}
		delete[] g_colMovies;
		g_colMovies = nullptr;
		g_cntMovies = 0;
	}

	// TD: define below all the functions from this module
}