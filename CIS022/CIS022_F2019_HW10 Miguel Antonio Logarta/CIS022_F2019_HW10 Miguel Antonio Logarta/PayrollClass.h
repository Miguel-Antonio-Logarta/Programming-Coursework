// Project: PayrollClass.h
// Author:	Miguel Antonio Logarta
// Date:	December 3, 2019
// Purpose: Header file for Payroll Class

#pragma once
class PayrollClass
{
public:
	bool LoadFile(string);						// Function to load the file
	void CalculatePay();						// Function for calculating people's pay
	void Display();								// Function to output to console
	void Save(string);							// Function to save output to a file


private:
	TimeCardRecord Records[60];					// Create an array of size 60 to hold the data

};

