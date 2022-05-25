// Project: CIS022_F2019_Lec9 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 11, 2019
// Purpose:	Define a struct data type
//			Create a varaible from a user-defined struct data type
//			Interact with a struct variable
//			Learn how to interact with an array of variables defined form a struct

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StudentType												// Struct holding student data
{
	string FirstName;											// Student first name
	string LastName;											// Student last name
	int TestScore;												// Their test score
	char Grade;													// Letter graded calculated in program
	bool HighScore;												// This student got the highest score
};

const int TOTAL_STUDENTS = 20;									// Input file has 20 records


// * is a pointer
bool ReadStudentData(string strFile, StudentType* Student)
{
	ifstream inFile;											// Handle to input file

	printf("Opening file...");									// Status
	inFile.open(strFile);										// Open the file

	if (inFile.is_open())
	{
		printf("Reading file...");								// Status
		for (int i = 0; i < TOTAL_STUDENTS; i++)				// Read entire file
			inFile >>											// Read the data
			Student[i].FirstName >>								// Load first name
			Student[i].LastName >>								// Load last name
			Student[i].TestScore;								// Load test score int

		inFile.close();											// Close the file
		printf("File read okay. \n\n");							// Status
		return true;											// File read okay
	}

	printf("Unable to open file %s.\n\n", strFile.c_str());		// Error message
	return false;												// File did not read okay
}

void DumpData(StudentType* Student)								// Display array data on console
{
	for (int i = 0; i < TOTAL_STUDENTS; i++)					// Roll through array
	{
		printf("%s %s %i %c",									// Display data 
			Student[i].FirstName.c_str(),
			Student[i].LastName.c_str(),
			Student[i].TestScore,
			Student[i].Grade);

		if (Student[i].HighScore)								// Is this a high scorer
			printf(" Highest score");							// Banner

		printf("\n");											// New line
	}
}

void AssignGrades(StudentType* Student)
{
	struct GradeType
	{
		int MinScore;											// Minimum score value
		char Grade;												// Calculated letter grade
	};

	GradeType GradeRange[5];									// Array of grade values

	GradeRange[0].MinScore = 0;									// 0 - 59 = F
	GradeRange[0].Grade = 'F';
	GradeRange[1].MinScore = 60;								// 60 - 69 = D
	GradeRange[1].Grade = 'D';
	GradeRange[2].MinScore = 70;								// 70 - 79 = C
	GradeRange[2].Grade = 'C';
	GradeRange[3].MinScore = 80;								// 80 - 89 = B
	GradeRange[3].Grade = 'B';
	GradeRange[4].MinScore = 90;								// 90 - 99 = A
	GradeRange[4].Grade = 'A';

	for (int i = 0; i < TOTAL_STUDENTS; i++)					// Roll through array of students
		for (int j = 0; j < 5; j++)								// Roll through array of grades
			if (Student[i].TestScore >=							// Greater than or equal to min score
				GradeRange[j].MinScore)
			{
				Student[i].Grade =								// Then set it 
					GradeRange[j].Grade;						// To the corresponding letter grade
			}
}

void FindHighest(StudentType* Student)
{
	int HighestScore = 0;										// Highest score earned by all students

	for (int i = 0; i < TOTAL_STUDENTS; i++)					// 1st loop, find the highest score
		if (Student[i].TestScore > HighestScore)				// If the score is higher than the current one
			HighestScore = Student[i].TestScore;				// Then change the highest score to that number

	for (int i = 0; i < TOTAL_STUDENTS; i++)					// 2nd loop, find out who got this score
		if (Student[i].TestScore == HighestScore)				// Is this a match to the highest score?
			Student[i].HighScore = true;						// Then set the bool to true
		else
			Student[i].HighScore = false;						// Then set the bool to false since it is not a higher score			
}

bool WriteOutput(string strOut, StudentType* Student)
{
	ofstream outFile;											// File handler for output file

	printf("Opening file...");									// Status
	outFile.open(strOut);										// Open the file

	if (outFile.is_open())										// Did it open
	{
		for (int i = 0; i < TOTAL_STUDENTS; i++)				// Loop through array
		{
			outFile <<											// Stream data to the output file
				Student[i].LastName << ", " <<
				Student[i].FirstName << ", " <<
				Student[i].TestScore << ", " <<
				Student[i].Grade;

			if (Student[i].HighScore)							// Is this the highest score record?
				outFile << ", Highest score";

			outFile << endl;									// New line at the end of each record

		}

		printf("Done writing.\n\n");							// Status
		outFile.close();										// Close the file
		return true;
	}

	printf("Unable to open file %s.\n\n",						// Error message
		strOut.c_str());
	return false;												// Bad file
}

int main()
{
	StudentType StudentData[TOTAL_STUDENTS];					// Array of student data (from input file)

	string strSourceFile =										// Input filename
		"CIS022_F2019_Lec9.txt";
	string strDestFile =										// Output filename
		"out.txt";		

	if (ReadStudentData(strSourceFile, StudentData))			// If input file read alright
	{
		AssignGrades(StudentData);								// Assign letter grades based in test scores
		FindHighest(StudentData);								// Find the highest grade in the data

		if (WriteOutput(strDestFile, StudentData))				// Write to the output file
			DumpData(StudentData);									// Display data on console
	}


	cout << endl << endl;
}
