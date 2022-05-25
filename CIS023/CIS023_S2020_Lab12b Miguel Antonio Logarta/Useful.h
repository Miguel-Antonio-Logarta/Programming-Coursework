// Module:	Useful.h
// Author:	Miguel Antonio Logarta
// Date:	March 4, 2020
// Purpose:	Useful class templates

#pragma once

// Default array size for TCHARs
#define TCHAR_SIZE 128

#include <string>							// String library
#include <sstream>							// Needed for StringtoTCHAR

using namespace std;						// Standard namespace

// Convert TCHAR* to int
template <class Type>
int TCHARtoInt(Type* szIn)
{
	// Attempt to convert to integer
	int iReturn = (int)_tstoi(szIn);		// _tstoi() return UINT, cast to int

	if (lstrlen(szIn) > 0 && iReturn == 0)
		for (int i = 0; i < lstrlen(szIn); i++)		// Check for each char for 0
			if (szIn[i] != '0')
				iReturn = MININT;

	return iReturn;									// Return the converted number
}

// Converts int to TCHAR
// Assumes base 10
template <class Type>
void InttoTCHAR(Type iIn, TCHAR* szIn)
{
	_itot_s(										// Standard convert TCHAR function
		iIn,										// Input number
		szIn,										// Input TCHAR, edit in place
		TCHAR_SIZE,									// Size of input TCHAR
		10);										// Radix
}

// Converts TCHAR to double
template <class Type>
double TCHARtoDouble(Type* szIn)
{
	return _tcstod(									// Standard convert TCHAR to double function
		szIn,										// Input TCHAR
		NULL);										// Local, not used
}

// Convert double to TCHAR
// iPrecision determines the number of decimal places
// Return point to local TCHAR
template <class Type>
void DoubleToTCHAR(Type dIn, TCHAR* szReturn, int iPrecision)
{
	TCHAR szControl[10];							// Conversion mask
	TCHAR szWork[TCHAR_SIZE];						// Completed TCHAR

	// Create mask
	_stprintf_s(									// Printf
		szControl,									// Target TCHAR
		TEXT("%%.%df"),								// Mask to specify precision
		iPrecision);								// Precision in decimal #'s

	// Convert double to TCHAR
	_stprintf_s(									// Printf
		szWork,										// Target TCHAR
		szControl,									// Mask
		dIn);										// Input value

	// Copy work TCHAR to return TCHAR
	_tcscpy_s(										// Copy
		szReturn,									// Destination TCHAR
		TCHAR_SIZE,									// Size of target TCHAR
		szWork);									// Source TCHAR
}

// Convert TCHAR to string
// Uses pointer to string (calling code needs &string)
template <class Type>
void TCHARtoString(TCHAR* szIn, Type* strIn)
{
	strIn->erase();									// Clear output string

	if (lstrlen(szIn) > 0)							// Don't attempt conversion if input is empty
	{
		wstring temp(szIn);							// Convert TCHAR to stream (wide) chars
		string str(temp.begin(), temp.end());		// Char by char conversion to string

		strIn->append(str);							// Copy temp string to return string
	}
}

// Convert string to TCHAR
// String must be pointer (use &string in calling code)
// Modifies TCHAR in place
// Return size_t code from mbstowcs_s()
// Max TCHAR_SIZE TCHAR length
template <class Type>
size_t StringtoTCHAR(Type* strIn, TCHAR* szIn)
{
	size_t pReturnValue = 0;						// Return code from mbstowcs_s()

	if (strIn->length() == 0 ||						// Cannot be empty
		strIn->length() > TCHAR_SIZE)				// Cannot be longer than the TCHAR
	{
		memset(szIn, 0, sizeof(szIn));				// Then return empty TCHAR
	}
	else
	{
		mbstowcs_s(									// Copy ASCII to Unicode
			&pReturnValue,							// Return value (or # of chars converted)
			szIn,									// Destination TCHAR
			TCHAR_SIZE,								// Size of destination TCHAR
			strIn->c_str(),							// Source string
			TCHAR_SIZE);							// Max # of chars to copy
	}

	return pReturnValue;							// Return the return value from mbstowcs_s()
}