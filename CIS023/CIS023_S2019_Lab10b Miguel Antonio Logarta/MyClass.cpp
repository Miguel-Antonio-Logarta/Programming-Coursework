// Project: MyClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	January 29, 2020
// Purpose:	Implementation file for MyClass

#include "framework.h"
#include "CIS023_S2019_Lab10b Miguel Antonio Logarta.h"

TCHAR* MyClass::Manipulate(TCHAR* szOne, TCHAR* szTwo)
{
	string str1, str2, strReturn;				// Work strings
	size_t pReturnValue;						// for mbstowcs_s()

	// Convert TCHAR 1 to a string
	if (lstrlen(szOne) != 0)					// If empty, do nothing
	{
		wstring temp(szOne);					// Convert TCHAR to wstring
		string str(temp.begin(), temp.end());	// Convert wstring to string
		str1 = str;								// Copy temp string
	}

	// Convert TCHAR 2 to a string
	if (lstrlen(szOne) != 0)					// If empty, do nothing
	{
		wstring temp(szTwo);					// Convert TCHAR to wstring
		string str(temp.begin(), temp.end());	// Convert wstring to string
		str2 = str;								// Copy temp string
	}

	// Concatenate the two strings
	if (str1.length() + str2.length() > 0)		// Any length at all?
		strReturn = str1 + ", " + str2;			

	// Convert return string to TCHAR
	mbstowcs_s(									// Convert string to TCHAR
		&pReturnValue,							// Return value
		szReturn,								// Destination TCHAR
		TCHAR_SIZE,								// Size of TCHAR
		strReturn.c_str(),						// Source string
		TCHAR_SIZE);							// Max chars to convert

	return szReturn;
}
