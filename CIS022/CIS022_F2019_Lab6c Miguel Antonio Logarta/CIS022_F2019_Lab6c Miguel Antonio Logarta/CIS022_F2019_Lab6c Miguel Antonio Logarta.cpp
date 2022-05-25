// Project: CIS022_F2019_Lab6c Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 28, 2019
// Purpose:	Use local and global identifiers
//			Use static variables
//			Perform function overloading
//			Add default parameters to a function


#include <iostream>
#include <string>

using namespace std;

/* This function checks if each character in the string is a number. 
	If it is a number it returns true, otherwise it returns false */
bool CheckIfNumber(string strUserInput, int characterNumber)												// This function confirms whether the character of a string is a char or an int
{
	if (strUserInput[characterNumber] < '0' || strUserInput[characterNumber] > '9')							// If it is out of range
	{	
		return false;																						// Return false
	}
	else return true;																						// Else return true
}

void DisplayChar(int iInputNumber)																			// Display an int
{
	printf(".%i.\n", iInputNumber);																
}

void DisplayChar(char cInputChar)																			// Display a char
{
	printf("'%c'\n", cInputChar);
}

int main()
{
	// Variable to capture user input
	string strUserInput;

	// Capture user input
	printf("Enter a string of characters: ");
	getline(cin, strUserInput);

	// Loop through the string and check if each character is an int or a char
	for (int i = 0; i < strUserInput.length(); i++)
	{
		// Variables for conversion
		string strStringToConvert;
		int iIntToPrint;
		char cCharToPrint;

		/* Condition below: 
			If it is a number, call the display function and display it as an integer
			Else if it is a letter, call the display function and display it as a letter
		*/
		if (CheckIfNumber(strUserInput, i))
		{
			strStringToConvert = strUserInput[i];
			iIntToPrint = atoi(strStringToConvert.c_str());
			
			DisplayChar(iIntToPrint);
		}
		else
		{
			cCharToPrint = strUserInput[i];
			DisplayChar(cCharToPrint);
		}
	}

	// Blank lines
	cout << endl << endl;
}
