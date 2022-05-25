// Project: CIS022_F2019_Lab5a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 7, 2019
// Purpose:	Review control structures
//			Review file input
//			Use the while loop control structure with file input

#include <iostream>
#include <string>										// String library
#include <fstream>										// File streaming library

using namespace std;

int main()
{
	ifstream inFile;									// Input file handle
	string strFileName = "CIS022_F2019_Lab5a_data.txt";	// File path
	double dInput;										// Number read from the input file
	int iCount = 0;										// Count of lines in the input file
	double dTotal = 0.0;								// Add all the numbers in the input file
	double dAverage = 0.0;								// Calculate the average of all the numbers


	inFile.open(strFileName);							// Open the file

	if (inFile.is_open())								// Did the file open okay?
	{
		inFile >> dInput;								// Read the first line from the input file

		while (!inFile.eof())							// While not end of file
		{
			iCount++;									// Count the number of lines in the file
			dTotal += dInput;							// Add each value in the file to the total
			inFile >> dInput;							// Read next line from file
		}



		inFile.close();									// Close the file

		// Display the line count
		printf("There are %i lines in the file.\n", iCount);

		// Display the sum of the numbers
		printf("Total value: %.4f.\n", dTotal);

		// Calculate the average
		dAverage = (dTotal / iCount);
		printf("Average value: %.4f.\n", dAverage);
	}
	else
		printf("Unable to open the file %s.\n", strFileName.c_str());		// If the file did not open correctly, show this error message


	printf("\n\n");										// Blank line
}
