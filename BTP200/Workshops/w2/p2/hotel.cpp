//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 1/13/2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "hotel.h"
#include "file.h"


namespace seneca
{
	void setGuest(Guest& theGuest, const char* fName, const char* lName)
	{
		strcpy(theGuest.m_firstName, fName);
		strcpy(theGuest.m_lastName, lName);
	}

	/// <summary>
	/// Load all information about the rooms found in a file and store it in
	///   the `Hotel` object.
	/// </summary>
	/// <param name="fileName">the name of the file containing data.</param>
	/// <param name="theHotel">the object that must be populated with data
	///   extracted from the file.</param>
	/* TODO: add the prototype of the `loadData` function that receives as parameters
	*         the address of a C-string with the file name containing the data, and
	*         a reference to an object of type `Hotel`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - the file contains information about an undetermined number of rooms that a hotel
	*     has. Each line from the file contains information about a single room in the
	*     format:
	*
	*     `ROOM_NUMBER,ROOM_CAPACITY\n`
	*
	* - the number of rooms and the number of characters for a single ROOM_NUMBER is not
	*     known, and must be determined at runtime; use dynamic memory to store this info
	*     in your program. Allocate *exactly* the amount of memory necessary and not more.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void loadData(const char* filename, Hotel& theHotel)
	{
		if (seneca::openFile(filename))
		{
			theHotel.m_cntRooms = seneca::getRecordsCount();
			theHotel.m_rooms = new Room[theHotel.m_cntRooms];
			for (int i = 0; i < theHotel.m_cntRooms; i++)
			{
				loadData(theHotel.m_rooms[i]);
			}
		}
		closeFile();
	}

	/// <summary>
	/// Load from a file the information about a single room.
	/// </summary>
	/// <param name="theRoom">the object where to put data loaded from the file</param>
	/* TODO: add the prototype of the `loadData` function that receives as a parameter
	*         a reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - load the room number (in a dynamically-allocated string) and the capacity
	*     of the room (as an integer) and store them in the attributes of the parameter.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void loadData(Room& theRoom)
	{
		theRoom.m_roomNumber = seneca::read(',');
		seneca::read(theRoom.m_maxCntGuests, '\n');
	}

	/// <summary>
	/// Print to screen the details of the hotel.
	/// </summary>
	/// <param name="theHotel">the hotel whose details are to be printed.</param>
	/* TODO: add the prototype of the `display` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Hotel`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - print the data stored in the object in the following format:
	*     `Standard Rooms:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_A`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_A`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_A`
	*     `...`
	*     `Family Rooms:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_B`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_B`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_B`
	*     `...`
	*     `Suites:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_C`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_C`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_C`
	*     `...`
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void display(const Hotel& theHotel)
	{
		int count1 = 1;
		int count2 = 1;
		int count3 = 1;
		std::cout << "Standard Rooms:" << std::endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'A')
			{
				if (theHotel.m_rooms[i].m_cntGuests != 0) 
				{
					std::cout << count1++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << ": ";
					for (int j = 0; j < theHotel.m_rooms[i].m_cntGuests; j++)
					{
						std::cout << theHotel.m_rooms[i].m_guests[j].m_firstName << ' ';
						std::cout << theHotel.m_rooms[i].m_guests[j].m_lastName;
						if (j != theHotel.m_rooms[i].m_cntGuests - 1)
						{
							std::cout << ", ";
						}
						else
						{
							std::cout << std::endl;
						}
					}
				}
				else 
				{
					std::cout << count1++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << std::endl;
				}
			}
		}
		std::cout << "Family Rooms:" << std::endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'B')
			{
				if (theHotel.m_rooms[i].m_cntGuests != 0) 
				{
					std::cout << count2++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << ": ";
					for (int j = 0; j < theHotel.m_rooms[i].m_cntGuests; j++)
					{
						std::cout << theHotel.m_rooms[i].m_guests[j].m_firstName << ' ';
						std::cout << theHotel.m_rooms[i].m_guests[j].m_lastName;
						if (j != theHotel.m_rooms[i].m_cntGuests - 1)
						{
							std::cout << ", ";
						}
						else
						{
							std::cout << std::endl;
						}
					}
				}
				else
				{
					std::cout << count2++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << std::endl;
				}
			}
		}
		std::cout << "Suites:" << std::endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'C')
			{
				if (theHotel.m_rooms[i].m_cntGuests != 0) 
				{
					std::cout << count3++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << ": ";
					for (int j = 0; j < theHotel.m_rooms[i].m_cntGuests; j++)
					{
						std::cout << theHotel.m_rooms[i].m_guests[j].m_firstName << ' ';
						std::cout << theHotel.m_rooms[i].m_guests[j].m_lastName;
						if (j != theHotel.m_rooms[i].m_cntGuests - 1)
						{
							std::cout << ", ";
						}
						else
						{
							std::cout << std::endl;
						}
					}
				}
				else
				{
					std::cout << count3++ << ". " << theHotel.m_rooms[i].m_roomNumber << " (" << theHotel.m_rooms[i].m_cntGuests << '/' << theHotel.m_rooms[i].m_maxCntGuests << ")" << std::endl;
				}
			}
		}
	}

	/// <summary>
	/// Print to screen the details of a single room.
	/// </summary>
	/// <param name="theRoom">the room whose details are to be printed.</param>
	/* TODO: add the prototype of the `display` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - if the room has guests, print the data stored formatted as:
	*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS): GUEST_1, GUEST_2, ...`
	* - if the room has no guests, print the data stored formatted as:
	*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS)`
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void display(const Room& theRoom)
	{
		if (0 < theRoom.m_cntGuests && theRoom.m_cntGuests < theRoom.m_maxCntGuests) 
		{
			std::cout << theRoom.m_roomNumber << " (" << theRoom.m_cntGuests << '/' << theRoom.m_maxCntGuests << ")" << ": ";
			for (int i = 0; i < theRoom.m_cntGuests; i++) 
			{
				std::cout << theRoom.m_guests[i].m_firstName << ' ';
				std::cout << theRoom.m_guests[i].m_lastName;
				if (i != theRoom.m_cntGuests - 1) 
				{
					std::cout << ", "; 
				}
			}
		}
		if (theRoom.m_cntGuests == 0) 
		{
			std::cout << theRoom.m_roomNumber << " (" << theRoom.m_cntGuests << '/' << theRoom.m_maxCntGuests << ")";
		}
	}

	/// <summary>
	/// Add a guest to the room ONLY if the room capacity has not been reached.
	///   If the room is already at capacity, this function does nothing.
	/// </summary>
	/// <param name="theRoom">the room where guests will be staying</param>
	/// <param name="theGuest">the gust that wants to stay in the room</param>
	/* TODO: add the prototype of the `addGuest` function that receives as a parameters
	*         a reference to an object of type `Room` and an unmodifiable reference
	*         to an object of type `Guest`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* addGuest()
	* - resize the array of guests currently staying in the room, but only if there
	*     enough capacity to accommodate the new guest.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void addGuest(Room& theRoom, const Guest& theGuest)
	{
		Guest* tmp = nullptr;
		if (theRoom.m_cntGuests < theRoom.m_maxCntGuests) 
		{
			tmp = new Guest[theRoom.m_cntGuests + 1];
			for (int i = 0; i < theRoom.m_cntGuests; i++)
			{
				tmp[i] = theRoom.m_guests[i];
			}
			tmp[theRoom.m_cntGuests] = theGuest;
			delete[] theRoom.m_guests;
			theRoom.m_guests = tmp;
			++theRoom.m_cntGuests;
		}
	}
	
	/// <summary>
	/// Searches in the hotel for a room with the number specified in the
	///   second parameter.
	/// </summary>
	/// <param name="theHotel">the hotel where to search for a room.</param>
	/// <param name="roomNumber">the room number being searched.</param>
	/// <returns>the address of the `Room` object with the number specified
	///   in the second parameter, or null if no such room exists.</returns>
	/* TODO: add the prototype of the `findRoom` function that receives as a parameters
	*         an unmodifiable reference to an object of type `Hotel` and the
	*         address of a C-string.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* findRoom()
	* - search in the hotel a room with the specified "Room Number"
	*     (iterate over the collection of rooms).
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Room* findRoom(const Hotel& theHotel, const char* roomNumber)
	{
		Room* foundRoom = nullptr;
		for (int i = 0; i < theHotel.m_cntRooms; i++) 
		{
			if (std::strcmp(theHotel.m_rooms[i].m_roomNumber, roomNumber) == 0)
			{
				foundRoom = &theHotel.m_rooms[i];
			}
		}
		return foundRoom;
	}

	/// <summary>
	/// Deallocates all dynamic memory used by a `Hotel` object.
	/// </summary>
	/// <param name="theHotel">the object whose memory must be deallocated.</param>
	/* TODO: add the prototype of the `deallocate` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* deallocate()
	* - deallocate all the dynamic memory used by the hotel:
	*   - the room number and the array of guests (for each room)
	*   - the array of rooms
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void deallocate(const Hotel& theHotel)
	{
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			delete[] theHotel.m_rooms[i].m_guests;
			delete[] theHotel.m_rooms[i].m_roomNumber;
		}
		delete[] theHotel.m_rooms;
	}
}