// Project: CIS022_F2019_HW8 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 8th, 2019
// Purpose:	Create a multi-dimensional array
//			Create code that loads a multi-dimensional array from a file
//			Create code that outputs the contents of a multi-dimensional array

#include <iostream>
#include <string>												// String library
#include <fstream>												// file stream
#include <iomanip>												// i/o manipulation

using namespace std;

const int FILE_LINES = 100;	 	// number of lines in the input file
const int DATA_ITEMS = 13;	 	// number of items in each line

bool LoadArray(string strA[FILE_LINES][DATA_ITEMS])
{
	//Open the file
	string strFileName = "CIS022_F2019_HW8_data.csv";								// File name
	ifstream inFile;																// File handler

	printf("Loading...\n");															// print loading to show that it is trying to open the file

	inFile.open(strFileName);														// Open the file

	// Assign the data from the csv file into the array
	if (inFile.is_open())															// If the file is open
	{
		for (int i = 0; i < FILE_LINES; i++)										// Loop through each line
		{
			for (int j = 0; j < DATA_ITEMS - 1; j++)								// Loop through each cell
				getline(inFile, strA[i][j], ',');									// Get the value from cell in inFile and store it into the array. Don't include commas

			getline(inFile, strA[i][DATA_ITEMS - 1], '\n');							// Read last column \n delimited
		}

		printf("Complete.\n");														// Print "Complete" when done successfully
		return true;																// Return true if the file has been opened successfully
	}
	else
	{
		printf("Failed.\n");														// Print failed if it did not open
		return false;																// Return false if it did not open			
	}
}

void WriteArray(string strA[FILE_LINES][DATA_ITEMS])
{
	// Create a file to output to
	string strOutFileName = "out.txt";												// File name
	ofstream outFile;																// File handler

	printf("Writing...\n");															// Tell the user it is going to try and write to the file

	outFile.open(strOutFileName);													// Open the output file

	if (outFile.is_open())
	{
		// Print out the contents of the array to the console. This is to make sure it is working
		for (int i = 1; i < FILE_LINES; i++)										// Loop through each line. Skip the first one
		{
			cout << endl;															// Start a new blank line before every line of the array
			
			for (int j = 0; j < DATA_ITEMS; j++)									// Loop through each item
			{
				cout << left << setw(15) << strA[0][j] + ": "						// Formatting. strA[0][j] refers to the first line of the file that shows the name of the column
					<< left << setw(15) << strA[i][j] << endl;						// Formatting. Show the data in the cell
			}
		}

		// Dump the values into the outFile
		for (int i = 0; i < FILE_LINES; i++)										// Loop through each line
		{
			outFile << endl;														// Start a new line
			for (int j = 0; j < DATA_ITEMS; j++)
			{
				int iSetWList[] = {8, 8, 5, 35, 8, 15, 15, 15, 10, 8, 15, 6, 6};	// A list for setw because each cell has a specific width to look nice
				outFile << left << setw(iSetWList[j]) << strA[i][j];				// Dump the value, but in a formatted way
			}
		}

		printf("\nComplete.\n");													// Print out complete once done					
		outFile.close();															// Close the file once done
	}
	else 
	{
		printf("Failed.\n");														// Print failed if it did not succeed
	}
}

int main()
{
	string Enrollment[FILE_LINES][DATA_ITEMS];	 									// Array to hold file data

	if (LoadArray(Enrollment))	 													// Load array from file
		WriteArray(Enrollment);	 													// If successful, write array to output file

	cout << endl << endl << endl;													// Blank lines
}
