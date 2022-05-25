// Project: StudentClass.h
// Author:	Miguel Antonio Logarta
// Date:	December 2, 2019
// Purpose:	Header file for StudentClass
//			File i/o, score calculation

#pragma once

class StudentClass
{
public:

	bool LoadFile(string);								// Load Scores[] from input file
	void CalculateScores();								// Calculate total scores
	void CalculateGrades();								// Calculate letter grades
	void Save(string);									// Save data to output file

private:

	ScoresClass Scores[20];								// Array of student data objects
														// This creates 20 records with individual entries in each record 
};

