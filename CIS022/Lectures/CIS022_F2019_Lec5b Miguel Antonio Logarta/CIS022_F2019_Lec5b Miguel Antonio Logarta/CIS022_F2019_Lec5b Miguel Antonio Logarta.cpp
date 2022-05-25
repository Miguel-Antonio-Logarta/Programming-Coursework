// Project: CIS022_F2019_Lec5b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 14, 2019
// Purpose:	Learn how to use the for control structure to produce looping action.
//			Use the index value in the body of a for control structure.
//			Learn how to use default values in the for control structure.
//			Use the for control structure to access individual characters in a string.
//			Access individual characters in a string.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//// 1. Syntax of the for loop
	//// i is an initializer / index that increments through each loop
	//for (int i = 0; i < 10; i++)									// Initialize i, check condition, increment i
	//	printf("Hello\n");											// Statement(s)

	//cout << endl;

	//for (int i = 0; i < 10; i += 2)									// Note new expression. i is a local variable that can be used
	//	printf("%i. Hello ", i);

	//cout << endl;
	//
	//for (int i = 0; i < 100; i++)									// New condition
	//	printf("%i ", i);

	//// 1. Defaults
	//int iLoop = 0;													// Counter declared outside the loop

	//for (; iLoop < 10; iLoop++)										// Default initializer
	//	printf("%i. Hello ", iLoop);

	//cout << endl;

	//for (int i = 0; ; i++)											// Default condition
	//{
	//	if (i == 2)													// Loop for 2
	//		continue;												// Continue means to stop the current loop and move on to the next one. This skips 2

	//	printf("%i ", i);											// Show the counter

	//	if (i == 10)												// Look for 10
	//		break;													// Break out of the loop
	//}

	//for (int i = 0; i < 10; )										// Default expression
	//{
	//	// printf("%i ", i);

	//	//printf("%i ", i++);											// Show the counter, increment (0 - 9)
	//	
	//	printf("%i ", ++i);											// Increment, then show the counter (1 - 10)
	//}

	// 3. Semantic error
	//for (int i = 0; i < 100; i++);									// not the ; at the end
	////printf("%i ", i);
	//printf("Hello\n");												// How many times will this run

	// 4. isNumber, determining intger input

	string strInput;												// User input
	int iNumber = 0;												// User input converted to number
	bool bIsNumber = true;											// The user input is an integer

	printf("Please enter an integer: ");							// Ask for user input
	getline(cin, strInput);											// Assign the user input to a variable

	for (int i = 0; i < strInput.length(); i++)						// Loop through the entire input string
	{
		if (strInput[i] < '0' || strInput[i] > '9')					// If outside 0 to 9
			if (strInput[i] != '-')									// Allow for negative numbers
				bIsNumber = false;									// Then not a number
	}

	if (bIsNumber)
	{
		iNumber = atoi(strInput.c_str());							// Convert user input to an integer
		printf("Number: %i\n", iNumber);							// Display the number

		printf("1st char is: %c", strInput[0]);						// Show 1st char (%c to show a single char)
	}
	else
		printf("\nInvalid number");									// Error message

	printf("\n\n");		// Display two blank lines
}
