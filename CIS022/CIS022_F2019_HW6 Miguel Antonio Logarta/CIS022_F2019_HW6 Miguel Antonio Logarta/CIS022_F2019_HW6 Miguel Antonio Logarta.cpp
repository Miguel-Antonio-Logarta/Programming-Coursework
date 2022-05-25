// Project: CIS022_F2019_HW6 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 3, 2019
// Purpose:	Compartmentalize code
//			Write and debug functions

#include <iostream>
#include <string>

using namespace std;

// Function GetString captures user input
void GetString(string& strUserInputReference)
{
	printf("Enter a string of characters: ");
	getline(cin, strUserInputReference);
}

bool LookForSpecial(string strStringToCheck)
{
	// Make a bool so that we can check the characters
	bool bIsSpecial = false;

	for (int i = 0; i < strStringToCheck.length(); i++)
	{
		// Have the bool be false 
		bIsSpecial = false;

		// Check the character
		if (strStringToCheck[i] < '0' || strStringToCheck[i] > '9')							// If it is less than 0 or greater than 9
			if (strStringToCheck[i] < 'A' || strStringToCheck[i] > 'Z')						// If it is less than A or greater than Z
				if (strStringToCheck[i] < 'a' || strStringToCheck[i] > 'z')					// If it is less than a or greater than z
				{
					bIsSpecial = true;														// Set bool to true
					break;
				}
	}

	// This works too. You can return a variable's value
	return bIsSpecial;

	//// Return a bool value
	//if (bIsSpecial)
	//	return true;
	//else
	//	return false;
}

void CountCharacters(string strUserInput)
{
	int iNormalCharacters = 0;
	int iSpecialCharacters = 0;

	for (int i = 0; i < strUserInput.length(); i++)
	{
		if (strUserInput[i] >= '0' && strUserInput[i] <= '9')								// If it is in range 0 to 9
			iNormalCharacters++;
		else if (strUserInput[i] >= 'A' && strUserInput[i] <= 'Z')							// Else if it is in between A to Z
			iNormalCharacters++;
		else if (strUserInput[i] >= 'a' && strUserInput[i] <= 'z')							// Else if it is i between a to z
			iNormalCharacters++;
		else
			iSpecialCharacters++;															// Else then it is a special character
	}

	printf("Number of normal characters in the string: %i\n", iNormalCharacters);			// Print amount of normal characters
	printf("Number of special characters in the string: %i\n", iSpecialCharacters);			// Print amount of special characters
}

int main()
{
	// Get user input using GetString()
	string strUserInput;
	GetString(strUserInput);

	if (LookForSpecial(strUserInput))														// If the character in the string is special
		CountCharacters(strUserInput);														// Then count the normal and special chars in the string
	else								
		printf("There are no special characters in this string.\n");						// Else print this if there are no special chars

	// Blank lines
	cout << endl << endl;
}