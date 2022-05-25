// Project: ScoresClass.h
// Author:	Miguel Antonio Logarta
// Date:	December 2, 2019
// Purpose:	ScoresClass Header

#pragma once
class ScoresClass
{
public:
	ScoresClass();										// Accessor


	// Mutators
	void SetID(string);									// Set strID
	void SetLName(string);								// Set Last name
	void SetFName(string);								// Set First name
	void SetScores(int, double);						// Set dScore[int] value
	void SetTotal(double);								// Set total
	void SetGrade(char);								// Set Grade

	// Accessors
	string GetID();										// Return strID
	string GetLName();									// Return strLName
	string GetFName();									// Return strFName
	double GetScore(int);								// Return dScore[int]
	double GetTotal();									// Return dTotal
	char GetGrade();									// Return cGrade

private:
	string strID;										// ID number
	string strLName;									// Last name
	string strFName;									// First name
	double dScores[10];									// Array of 10 test scores
	double dTotal;										// Average of dScores[]
	char cGrade;										// Letter grade of scores



};

