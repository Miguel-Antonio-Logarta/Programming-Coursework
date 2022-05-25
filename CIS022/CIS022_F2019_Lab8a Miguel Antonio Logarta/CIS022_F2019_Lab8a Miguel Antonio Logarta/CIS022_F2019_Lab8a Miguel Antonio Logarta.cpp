// Project: CIS022_F2019_Lab8a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 4, 2019
// Purpose:	Define an array
//			Traverse and interact with an array
//			Load and unload an array with file data
//			Review file input and output

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool LoadArray(string strA[], int iSize)
{
	ifstream inFile;															// Handle to input file
	string strFileName = "CIS022_F2019_Lab8a_Data.txt";							// Name of input file
	string strData;																// Line of text from the input file
	int iIndex = 0;																// Index of array

	printf("Loading...\n");														// Tell user file is loading

	inFile.open(strFileName);													// Open the file

	if (inFile.is_open())														// Did the file open with no problems?
	{
		while (!inFile.eof())													// Loop until the end of the file
		{
			getline(inFile, strData);											// Read a line from the file
			strA[iIndex++] = strData;											// Save the string in the array
		}

		inFile.close();															// Close the file

		printf("Complete \n");													// Tell the user the array is filled from the file

		return true;
	}
	else
		printf("Unable to open file: %s \n", strFileName.c_str());				// Tell the user that it did not open fine

	return false;																// Fail by default
}

void DisplayInitials(string strA[], int iSize)
{
	printf("Displaying initials: \n");											// Notice
	for (int i = 0; i < iSize; i++)												// Loop through array
		printf("%c ", strA[i].at(0));											// Print the first character of the element of the array

	printf("\nEnd of initials\n");												// Close label
}

void OutputArray(string strA[], int iSize)
{
	printf("Contents of array:\n");												// Notice

	for (int i = 0; i < iSize; i++)												// Loop through array
		printf("%s\n", strA[i].c_str());										// Display element at i

	printf("End of array\n");													// Close label
}

void SortArray(string strA[], int iSize)
{
	printf("Sorting...");														// Header

	for (int iOuter = 0; iOuter < iSize; iOuter++)								// Outer loop
		for (int iInner = 0; iInner < iSize - 1; iInner++)						// Inner sort
			if (strA[iInner] > strA[iInner + 1])								// Out of order?
				strA[iInner].swap(strA[iInner + 1]);							// Swap them

	printf("Complete\n");														// Footer
}

void SaveArray(string strA[], int iSize)
{
	ofstream outFile;															// Handle of output file
	string strFileName = "out.txt";												// Name of output file

	printf("Writing...");														// Header

	outFile.open(strFileName);													// Open the file

	if (outFile.is_open())														// Did the file open okay?
	{
		for (int i = 0; i < iSize; i++)											// Loop through array
			outFile << strA[i] << endl;											// Stream the array element


		outFile.close();														// Close the file

		printf("Complete\n");													// Footer
	}
	else
		printf("Unable to open output file: %s\n", strFileName.c_str());		// If the file fails to open display this
}

int main()
{
	const int ARRAY_SIZE = 100;	 												// size of array
	string aArray[ARRAY_SIZE];	 												// array to be sorted

	if (LoadArray(aArray, ARRAY_SIZE))	 										// did the array load okay?
	{
		DisplayInitials(aArray, ARRAY_SIZE);	 								// display the 1st initial of each name in the array
		OutputArray(aArray, ARRAY_SIZE);	 									// write the sorted array to an output file
		SortArray(aArray, ARRAY_SIZE);											// Sort the elements of the array
		OutputArray(aArray, ARRAY_SIZE);										// Display after sort

		SaveArray(aArray, ARRAY_SIZE);											// Output the contents of the array to a file

	}

	cout << endl << endl << endl;	 	// blank line
}
