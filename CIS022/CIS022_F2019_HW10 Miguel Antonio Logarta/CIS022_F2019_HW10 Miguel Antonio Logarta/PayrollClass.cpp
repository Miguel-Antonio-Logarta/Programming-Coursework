// Project: PayrollClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	December 3, 2019
// Purpose: Implementation file for Payroll Class

#include "CIS022_F2019_HW10 Miguel Antonio Logarta.h"

bool PayrollClass::LoadFile(string strFileName)
{
	ifstream inFile;												// File handler
	string strTemp;													// Temporary string variable to store data
	double dTemp;													// Temporary float to store numbers

	printf("Opening file...");										// Status

	inFile.open(strFileName);										// Open the file

	if (inFile.is_open())											// Check if file opened correctly
	{
		printf("Reading...");										// Status

		for (int i = 0; i < 60; i++)								// Loop through each record
		{
			getline(inFile, strTemp, ',');							// Get last name and store it
			Records[i].SetLastName(strTemp);

			getline(inFile, strTemp, ',');							// Get first name and store it
			Records[i].SetFirstName(strTemp);

			getline(inFile, strTemp, ',');							// Get city and store it
			Records[i].SetCity(strTemp);

			getline(inFile, strTemp, ',');							// Get wage amount and store it
			dTemp = atof(strTemp.c_str());
			Records[i].SetWageAmount(dTemp);

			// Read last entry in record
			getline(inFile, strTemp, '\n');
			dTemp = atof(strTemp.c_str());							// Get the number of hours and store it
			Records[i].SetNumberOfHours(dTemp);						

		}

		inFile.close();												// Close the file
		printf("Complete\n\n");										// Status
		return true;												// Return true if completed
	}

	printf("Unable to open %s", strFileName.c_str());				// Status if unable to open file
	return false;													// Return false if it didn't open
}

void PayrollClass::CalculatePay()
{
	double dGrossPay = 0.0;											// Variable to hold the calculated gross pay

	for (int i = 0; i < 60; i++)
	{
		dGrossPay =													// Calculate gross pay from hours * wage
			Records[i].GetNumberOfHours() * 
			Records[i].GetWageAmount();
		Records[i].SetGrossPay(dGrossPay);							// Get the value of gross pay and store it in the record array
	}
}

void PayrollClass::Display()
{
	for (int i = 0; i < 60; i++)									// Loop through each record
	{
		// Display employee Info
		// Last, First, City
		cout << setw(8) << left << "Employee" << ": "
			<< Records[i].GetLastName() << ", "
			<< Records[i].GetFirstName() << ", "
			<< Records[i].GetCity() << endl;

		// Wage, Hours, Gross Pay
		cout << setw(8) << left << "W/H/P" << ": "
			<< "$" << Records[i].GetWageAmount() << ", "
			<< Records[i].GetNumberOfHours() << "hrs" << ", "
			<< "$" << fixed << setprecision(2)						// Set fixed precision to 2 for gross pay
			<< Records[i].GetGrossPay() << endl
			<< endl;
	}
}

void PayrollClass::Save(string strOutFileName)
{
	ofstream outFile;												// File handler for output file

	printf("Opening output file...");								// Status

	outFile.open(strOutFileName);									// Open the output file

	if (outFile.is_open())											// Check if file opened just fine
	{
		printf("Writing...");										// Status

		for (int i = 0; i < 60; i++)								// Loop through each record
		{
			// Output record to file
			outFile << Records[i].GetLastName() << ", "
				<< Records[i].GetFirstName() << ", "
				<< Records[i].GetCity() << ", "
				<< Records[i].GetWageAmount() << ", "
				<< Records[i].GetNumberOfHours() << ", "
				<< fixed << setprecision(2)							// Set fixed precision to 2 for gross pay
				<< Records[i].GetGrossPay() << endl;				// New line at end of file
		}

		outFile.close();											// Close the file
		printf("Complete\n");										// Status
	}
	else
	{
		printf("Unable to open %s", strOutFileName.c_str());		// Print this if the file did not open
	}
}
