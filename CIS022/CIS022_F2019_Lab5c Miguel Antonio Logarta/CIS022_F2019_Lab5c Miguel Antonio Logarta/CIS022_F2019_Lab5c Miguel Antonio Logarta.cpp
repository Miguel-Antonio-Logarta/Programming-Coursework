// Project:	CIS022_F2019_Lab5c Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 16, 2019
// Purpose:	Review the control structures while, do...while, and for
//			Review user input
//			Use loop control structures to gather user input

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Start variables
	// User input variable
	string strUserInput;
	// Variables to assign the input to
	int iStartValue;
	int iEndValue;
	int iStepValue;
	int iCurrentValue;
	// Bool to check if the input is an integer
	bool bIsInteger = true;

	// Get user input for starting value
	do {
		printf("Enter a starting value: ");
		getline(cin, strUserInput);

		//Check user input
		bIsInteger = true;
		for (int i = 0; i < strUserInput.length(); i++)
			if (strUserInput[i] < '0' || strUserInput[i] > '9')							// If out of range between 0 and 9
				if (strUserInput != "-")												// If the input is not a negative sign
					bIsInteger = false;
	} while (!bIsInteger || strUserInput.length() == 0);
	// Convert user input to an integer for the starting value
	iStartValue = atoi(strUserInput.c_str());

	// Get user input for ending value
	do {
		printf("Enter an ending value: ");
		getline(cin, strUserInput);

		//Check user input
		bIsInteger = true;
		for (int i = 0; i < strUserInput.length(); i++)
			if (strUserInput[i] < '0' || strUserInput[i] > '9')							// If out of range between 0 and 9
				if (strUserInput != "-")												// If the input is not a negative sign
					bIsInteger = false;
	} while (!bIsInteger || strUserInput.length() == 0);
	// Convert user input to an integer for the ending value
	iEndValue = atoi(strUserInput.c_str());

	// Get user input for step value
	do {
		printf("Enter a step value: ");
		getline(cin, strUserInput);

		//Check user input
		bIsInteger = true;
		for (int i = 0; i < strUserInput.length(); i++)
			if (strUserInput[i] < '1' || strUserInput[i] > '9')							// If out of range between 1 and 9. You cannot have a step of 0
				if (strUserInput != "-")												// If the input is not a negative sign
					bIsInteger = false;
	} while (!bIsInteger || strUserInput.length() == 0);
	// Convert user input to an integer for the step value
	iStepValue = atoi(strUserInput.c_str());

	// Display the squares
	for (int iCounter = iStartValue; iCounter <= iEndValue; iCounter += iStepValue)		// Start loop from the starting value, end the loop when counter reaches end value, counter increments by steps
	{
		iCurrentValue = iCounter * iCounter;											// Current value calculates the square of the current number
		printf("%i squared is %i.\n", iCounter, iCurrentValue);							// Print out the square of the number
	}
		
	// Blank Lines
	printf("\n\n");
}
