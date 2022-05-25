// Project: CIS022_F2019_Lab5b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 14, 2019
// Purpose:	Review control structures
//			Use the for loop control structure to create a counting scheme

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	// Variables to open the file
	ifstream inFile;
	string strFileInput = "CIS022_F2019_Lab5b_data.txt";
	// String variables to assign the data to
	string strString1;
	string strString2;
	string strString3;
	string strString4;
	// Bool value to check for the input
	bool bIsInteger = true;
	// Open the file
	inFile.open(strFileInput);

	// Check if the file opened correctly
	if (inFile.is_open())
	{
		// Assign the data in the text file to the variables below
		inFile >> strString1;
		inFile >> strString2;
		inFile >> strString3;
		inFile >> strString4;
	}
	// If the file did not open correctly
	else
		printf("Unable to open file");

	// Validate each value and check if it is an integer

	// Check string 1
	for (int i = 0; i < strString1.length(); i++)
		if (strString1[i] < '0' || strString1[i] > '9')									// If the value of the index is out of range of 0 - 9
			if (strString1[i] != '-')													// If it doesn't have a dash (negative number)
				bIsInteger = false;														// Then it is not an integer
	if (bIsInteger)																		// If the value turns out to be an integer
	{
		int iNumber = 0;																// Create an int to print out the value
		iNumber = atoi(strString1.c_str());												// First convert the string into an int and assign it to iNumber
		printf("%i\n", iNumber);														// Now print it
	}
	else
		printf("Invalid Number\n");														// Print invalid number if it is not an integer

	bIsInteger = true;																	// Reset the bool value to true

	// Check string 2
	for (int i = 0; i < strString2.length(); i++)
		if (strString2[i] < '0' || strString2[i] > '9')
			if (strString2[i] != '-')
				bIsInteger = false;
	if (bIsInteger)
	{
		int iNumber = 0;
		iNumber = atoi(strString2.c_str());
		printf("%i\n", iNumber);
	}
	else
		printf("Invalid Number\n");

	bIsInteger = true;

	// Check string 3
	for (int i = 0; i < strString3.length(); i++)
		if (strString3[i] < '0' || strString3[i] > '9')
			if (strString3[i] != '-')
				bIsInteger = false;
	if (bIsInteger)
	{
		int iNumber = 0;
		iNumber = atoi(strString3.c_str());
		printf("%i\n", iNumber);
	}
	else
		printf("Invalid Number\n");

	bIsInteger = true;

	// Check string 4
	for (int i = 0; i < strString4.length(); i++)
		if (strString4[i] < '0' || strString4[i] > '9')
			if (strString4[i] != '-')
				bIsInteger = false;
	if (bIsInteger)
	{
		int iNumber = 0;
		iNumber = atoi(strString4.c_str());
		printf("%i\n", iNumber);
	}
	else
		printf("Invalid Number\n");

	bIsInteger = true;


	// Close the file
	inFile.close();

	// Blank lines
	printf("\n\n");
}
