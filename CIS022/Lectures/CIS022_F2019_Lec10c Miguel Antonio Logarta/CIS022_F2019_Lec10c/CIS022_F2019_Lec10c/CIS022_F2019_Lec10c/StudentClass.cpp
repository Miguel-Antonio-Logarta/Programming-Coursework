// Project: StudentClass.h
// Author:	Miguel Antonio Logarta
// Date:	December 2, 2019
// Purpose:	Implementation file for StudentClass
//			File i/o, score calculation

#include "CIS022_F2019_Lec10c.h"

bool StudentClass::LoadFile(string strFileName)
{
	ifstream inFile;											// File handler
	string strTemp;												// Temp string for file read
	double dTemp;												// Temp double for data conversion

	printf("Opening input file...");							// Status

	inFile.open(strFileName);									// Open the input file

	if (inFile.is_open())										// Did the file open correctly
	{
		printf("Reading...");									// Status

		for (int i = 0; i < 20; i++)							// File has 20 lines (records)
		{
			getline(inFile, strTemp, ',');						// Read ID
			Scores[i].SetID(strTemp);

			getline(inFile, strTemp, ',');						// Read last name
			Scores[i].SetLName(strTemp);	

			getline(inFile, strTemp, ',');						// Read First name
			Scores[i].SetFName(strTemp);

			for (int j = 0; j < 9; j++)							// 10 scores
			{
				getline(inFile, strTemp, ',');					// Read scores
				dTemp = atof(strTemp.c_str());					// Convert to double
				Scores[i].SetScores(j, dTemp);
			}
			// Read last score
			getline(inFile, strTemp, '\n');						// Read the last score
			dTemp = atof(strTemp.c_str());						// Convert to double
			Scores[i].SetScores(9, dTemp);
		}


		inFile.close();											// Close the file
		printf("Complete\n\n");									// Status
		return true;											// Return true if the file was read just fine
	}


	return false;												// False if the file is not found
}

void StudentClass::CalculateScores()
{
	double dTotal = 0.0;										// Accumulator

	for (int i = 0; i < 20; i++)								// Loop through the 20 records 
	{
		for (int j = 0; j < 10; j++)							// Loop through each score in the record (10 scores)
		{
			dTotal += Scores[i].GetScore(j);					// Add the scores together and total them

		}

		dTotal /= 10;										// Average = sum divided by 10

		Scores[i].SetTotal(dTotal);							// Store value in record
	}
}

void StudentClass::CalculateGrades()
{
	for (int i = 0; i < 20; i++)									// 20 Records
	{
		double dTotal = Scores[i].GetTotal();						// Get the total calculated in Calculate Scores()

		if (dTotal >= 9.0)											// Calc and store grade
			Scores[i].SetGrade('A');
		else if (dTotal >= 8.0)
			Scores[i].SetGrade('B');
		else if (dTotal >= 7.0)
			Scores[i].SetGrade('C');
		else if (dTotal >= 6.0)
			Scores[i].SetGrade('D');
		else Scores[i].SetGrade('F');

	}
}

void StudentClass::Save(string strFileName)
{
	ofstream outFile;												// Handle to output file

	printf("Opening output file...");								// Status
	
	outFile.open(strFileName);										// Open / create the file

	if (outFile.is_open())											// Did the file open?
	{
		printf("Writing...");

		for (int i = 0; i < 20; i++)								// 20 records
		{
			outFile << Scores[i].GetID() << ",";		
			outFile << Scores[i].GetLName() << ",";
			outFile << Scores[i].GetFName() << ",";
			outFile << Scores[i].GetTotal() << ",";
			outFile << Scores[i].GetGrade() << "\n";
		}


		outFile.close();											// Close the file
		printf("Complete\n\n");
	}
}
