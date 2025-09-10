#include <iostream>
#include "Movie.h"
#include "DataHandle.h"

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

const int ERROR_MISSING_FILE = 1;
const int ERROR_CORRECT_FILE = 2;

int main()
{
	{
		// TEST: Check that the "read" overloads work
		std::cout << "T1: Extract various tokens from the file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		// assume the data in the file is perfect
		seneca::openFile("tokens.txt");

		// get the first token as a C-style array of characters (delimiter is ',')
		//   - the array is dynamically allocated; after we're done
		//     with it, we must deallocate it.
		char* str = seneca::read();
		std::cout << "[" << str << "]";
		delete[] str;
		str = nullptr;

		// get the second token as an int (delimiter is '|')
		int iData = 0;
		seneca::read(iData, '|');
		std::cout << "[" << iData << "]";

		// get the third token as a double (delimiter is ',')
		double dData = 0;
		seneca::read(dData);
		std::cout << "[" << dData << "]";

		// get the fourth token as a string (delimiter is '!')
		str = seneca::read('!');
		std::cout << "[" << str << "]";
		delete[] str;

		// get the last token as a long (delimiter is ',')
		long lData = 0;
		seneca::read(lData);
		std::cout << "[" << lData << "]\n";
		seneca::closeFile();
	}

	{
		// TEST: Check that "seneca::loadData" detects that the file is missing
		std::cout << "\n\nT2: Check missing file detection\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		if (seneca::loadData("penguin.jpg") == false)
			std::cout << "[Success] Missing file correctly handled.\n";
		else
		{
			std::cout << "[Error] missing file incorrectly handled. Exiting ...";
			return ERROR_MISSING_FILE;
		}
	}

	// The code below work with data from a good file (assume the file has perfect data)

	{
		// TEST: Check that "seneca::loadData" loads data from a good file
		std::cout << "\n\nT3: Check data loading with a good file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		if (seneca::loadData("movies.csv") == false)
		{
			std::cout << "[Error] The file 'movies.csv' should be good; check if"
				"        your code contains the file in the project's folder.\n";
			return ERROR_CORRECT_FILE;
		}
		else
		{
			std::cout << "[Success] The file 'movies.csv' was loaded.\n";
		}
	}

	{
		// TEST: print some of the loaded movies
		std::cout << "\n\nT4: Show some movies loaded from file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::display(   0); // good -> "Look Who's Talking"
		seneca::display(   1); // good -> "Driving Miss Daisy"
		seneca::display(  10); // good -> "The War of the Roses"
		seneca::display( 100); // good -> "Ace Ventura: Pet Detective"
		seneca::display( 199); // good -> "American Pie"
		seneca::display( 200); // Out of Bounds
	}

	{
		// TEST: check the display with ranges
		std::cout << "\n\nT5: Show specific ranges as loaded from file\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::display("First movies in collection", 0, 5);
		seneca::display("Movies in the middle of collection", 98, 103);
		seneca::display("Last three movies from collection", 197); // using default value for the third param
	}

	{
		// TEST: load data from a second file
		std::cout << "\n\nT6: Load a second collection of movies\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::loadData("favorites.csv"); // will generate a memory leak if memory is not properly managed
		seneca::display("My Favorites");
	}


	// cleanup: if memory is leaked, "valgrind" will flag it.
	seneca::deallocateMemory();

	return cout;
}


/*
* Changes:
* - removed namespaces from main, and using fully qualified name for each identifier
* - changed namespace to `seneca`
* - updated the header guard to use the standard conventions, and no decorators
* - in main module, added a `cout` global variable: will trip a `using namespace std;` statement in headers
* - renamed `Movies` to `Movie` since it represents a single movie (the names should be meaningful)
* - renamed the `main.cpp` to `w2p1.cpp`
* - removed `#define ...` - prefer const, variables, or parameters
* - removed the second `for` loop in movie `display` (why would the title contatin '\r' -- that is just bad file format, students/profs should upload files as text allowing proper file ending)
* - removed `cout << ...` from load function. Functions are too chaty -- they should shutup and do work; signal to client when things go wrong, let client decide how to proceed.
* - function implementation and protoype are a mismatch: they return `bool`, but prototype says it's an int. What's up with that???
* - fixed indentations (now is consistent in all files)
* - `for (i = 0; i < no_of_lines && check; i++)` -- `check` is a local variable and never changed inside the body; why does it appear in the stopping condition?
* - `no_of_lines` represents the size of the array. the variable is misnamed. Changed to `g_cntMovies`
* - renamed global variable `movies` to `g_colMovies`
* - in load function, the variable `check` is always true. Why does it even exists??  Mistery...
* - the load function check if the number of lines is the same as the number of movies extracted.  Why would the count procedure not work here?   Assume the data is perfect in "Workshop #2" -- too early for broken files.
* 
*/
