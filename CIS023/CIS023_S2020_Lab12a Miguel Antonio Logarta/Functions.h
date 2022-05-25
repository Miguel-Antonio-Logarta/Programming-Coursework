// Module:	Functions.h
// Author:	Miguel Antonio Logarta
// Date:	March 2, 2020
// Purpose: Header file for Functions.cpp
//			Virtual functions

#pragma once
class Functions
{
public:
	Functions();						// Contructor

	// Find largest, (array, size of array, largest number found)
	// Return position in array where largest number was found
	static int Largest(int A[], int, int&);

	// Search for int in array, return -1 if not found
	static int Search(int A[], int, int);
};

