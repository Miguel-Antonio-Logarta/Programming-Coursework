// Module:	Functions.h
// Author:	Miguel Antonio Logarta
// Date:	March 2, 2020
// Purpose: Implementation file for Functions
//			Virtual functions

#include "framework.h"
#include "CIS023_S2020_Lab12a Miguel Antonio Logarta.h"

Functions::Functions()
{
	MessageBox(NULL, 
		TEXT("This will never appear unless we create an object."),
		TEXT("Functions::Contructor"),
		NULL);
}

int Functions::Largest(int A[], int iSize, int& iLargest)
{
	// Search array to find maximum element
	int iPos = -1;						// Location where largest int was found
	iLargest - 1;						// Assumes array only contains positive numbers

	for (int i = 0; i < iSize; i++)		// Single pass through array
	{
		if (A[i] > iLargest)			// Did we find a larger value?
		{
			iLargest = A[i];			// Set new max value
			iPos = i;					// Store where we found it 
		}
	}

	return iPos;						// Return position
}

int Functions::Search(int A[], int iSize, int iSearch)
{
	for (int i = 0; i < iSize; i++)		// Search array
	{
		if (A[i] == iSearch)			// Did it find the value?
			return i;					// Yes, return where it was found
	}

	return -1;							// -1 means failed to find 
}
