// Project: ScoresClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	December 2, 2019
// Purpose:	Implementation file for storage class ScoresClass

#include "CIS022_F2019_Lec10c.h"						// Project header

ScoresClass::ScoresClass()
{
	// Initialize members. Variables are called members while functions are called methods
	strID = "";
	strLName = "";
	strFName = "";
	for (int i = 0; i < 10; i++)						// Create an array of size 10 and set them to 0.0
		dScores[i] = 0.0;
	dTotal = 0.0;
	cGrade = 'F';
}

void ScoresClass::SetID(string strIn)
{
	strID = strIn;
}

void ScoresClass::SetLName(string strIn)
{
	strLName = strIn;
}

void ScoresClass::SetFName(string strIn)
{
	strFName = strIn;
}

void ScoresClass::SetScores(int iIndex, double dValue)
{
	dScores[iIndex] = dValue;
}

void ScoresClass::SetTotal(double dIn)
{
	dTotal = dIn;
}

void ScoresClass::SetGrade(char cIn)
{
	cGrade = cIn;
}

string ScoresClass::GetID()
{
	return strID;
}

string ScoresClass::GetLName()
{
	return strLName;
}

string ScoresClass::GetFName()
{
	return strFName;
}

double ScoresClass::GetScore(int iIndex)
{
	return dScores[iIndex];
}

double ScoresClass::GetTotal()
{
	return dTotal;
}

char ScoresClass::GetGrade()
{
	return cGrade;
}
