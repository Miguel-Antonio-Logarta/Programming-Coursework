// Project:		CIS022_F2019_Lec10c.cpp
// Author:		Mark Berrett
// Date:		November 16, 2019
//				December 2, 2019, Miguel Antonio Logarta
// Purpose:		Lecture 10c
//				Convert struct to class
//

#include "CIS022_F2019_Lec10c.h"				// Include project header

int main()
{
	StudentClass StudentObj;					// Object of type StudentClass

	string szSourcePath =
		"CIS022_F2019_Lec10c_data.csv";
	string szOutPath =
		"out.txt";

	if (StudentObj.LoadFile(szSourcePath))			// Load the file into the storage class
	{
		StudentObj.CalculateScores();				// Total the scores
		StudentObj.CalculateGrades();				// Calculate the letter grades
		StudentObj.Save(szOutPath);					// Save data to output file
	}

	cout << endl << endl << endl;				// blank lines
}

