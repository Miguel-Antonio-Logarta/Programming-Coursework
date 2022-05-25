// Project: CIS022_F2019_HW9 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 11, 2019
// Purpose:	Define a struct data type
//			Create a variable from a user-defined struct data type
//			Interact with a struct variable
//			Learn how to interact with an array of variables defined from a struct

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Wages														// Struct holding wage data of each employee
{
	string strLastName;												// Employee last name
	string strFirstName;											// Employee first name
	string strCity;													// Employee's city
	double dWageAmount;												// Employee's wage amount
	double dNumberOfHours;											// Employee's hours worked
};

const int TOTAL_RECORDS = 60;

// * is a pointer
bool ReadFileData(string strFileName, Wages* employee)
{
	ifstream inFile;												// File handler

	printf("Opening file...\n");									// Status: Opening file
	inFile.open(strFileName);										// Actually open the file

	if (inFile.is_open())
	{
		printf("Reading file...\n");								// Status: reading the file

		// Try to read every row in the csv file
		// For every row, assign each item to the corresponding variable in the array
		for (int i = 0; i < TOTAL_RECORDS; i++)
		{
			// Variables to convert the string to floats
			// getline() doesn't take in doubles, only strings
			string strWageAmount;				
			string strNumberOfHours;

			// Get the values from the csv and assign them to the struct
			getline(inFile, employee[i].strFirstName, ',');			// Get the first name of employee
			getline(inFile, employee[i].strLastName, ',');			// Get the last name of employee
			getline(inFile, employee[i].strCity, ',');				// Get employee's city
			getline(inFile, strWageAmount, ',');					// Store wage amount in a string
			getline(inFile, strNumberOfHours, '\n');				// Store number of hours in a string

			employee[i].dWageAmount =								// Convert Wage to a float and store it
				atof(strWageAmount.c_str());
			employee[i].dNumberOfHours =							// Convert hours to a float and store it
				atof(strNumberOfHours.c_str());

		}

		inFile.close();												// Close the file if successful
		printf("File has been read.\n");							// Status: finished reading
		return true;
	}

	printf("Unable to open file.\n");								// Print this if it did not open
	return false;
}

void DumpData(Wages* employee)
{
	// Print the records
	for (int i = 0; i < TOTAL_RECORDS; i++)							// Roll through array
	{
		// Print each entry in the record
		printf("%s %s %s %.2f %.2f\n",
			employee[i].strLastName.c_str(),
			employee[i].strFirstName.c_str(),
			employee[i].strCity.c_str(),
			employee[i].dWageAmount,
			employee[i].dNumberOfHours);
	}
}

bool WriteOutput(string strOut, Wages* employee)
{
	ofstream outFile;												// File handler

	printf("Opening file...");										// Status: Opening the file
	outFile.open(strOut);											// Actually open the file

	if (outFile.is_open())											// If the file is open
	{
		for (int i = 0; i < TOTAL_RECORDS; i++)						// Roll through array
		{
			outFile <<												// Put the values into the output file in a formatted way
				employee[i].strFirstName << " " <<
				employee[i].strLastName << " " <<
				endl <<
				employee[i].strCity <<
				endl <<
				employee[i].dNumberOfHours << " " <<
				employee[i].dWageAmount << " " <<
				employee[i].dNumberOfHours * employee[i].dWageAmount <<		// Calculate total amount of pay (Hours * Wage)
				endl << endl;
		}

		printf("Done writing.\n\n");								// Status: done writing
		outFile.close();											// Actually close the file
		return true;
	}

	printf("Unable to open file %s.\n\n", strOut.c_str());			// Print this if the file failed to open
	return false;
}

int main()
{
	string strSrcFileName = "CIS022_F2019_HW9_data.csv";			// Source file name
	string strDestFileName = "out.txt";								// Output file name
	Wages payrollRecords[TOTAL_RECORDS];							// Create an array 

	if (ReadFileData(strSrcFileName, payrollRecords))				// If the file data was read fine
	{
		if (WriteOutput(strDestFileName, payrollRecords))			// If it was written to the destination file fine
			DumpData(payrollRecords);								// Display what was outputted to the file
	}

	cout << endl << endl;											// Blank lines
}


