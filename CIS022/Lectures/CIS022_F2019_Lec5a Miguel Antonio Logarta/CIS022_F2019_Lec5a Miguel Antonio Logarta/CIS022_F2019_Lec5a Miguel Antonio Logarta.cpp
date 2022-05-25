// Project: CIS022_F2019_Lec5a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 7, 2019
// Purpose:	Learn how to use the while / do... while statements
//			Learn how to do loops

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//// 1. Simple while loop
	//string strInput;										// User input
	//int iInput;											// User input converted to an integer

	//// Get user input
	//printf("Enter a number between 1 and 10: ");
	//getline(cin, strInput);

	//// Convert the user input into an integer and assign it to iInput
	//iInput = atoi(strInput.c_str());

	//while (iInput > 0)										// loop until iInput is not > 0 
	//{
	//	printf("%i\n", iInput--);								// Display value, then decrement
	//}
	//printf("\n\n");											// Blank line on the bottom of the program

	//// 2. counter controlled
	//int iMax = 100;											// limit
	//int iCounter = 0;											// counter
	//while (iCounter < iMax)									// loop until it reaches the limit
	//{
	//	printf("%i, ", iCounter++);								// display counter, then increment
	//}
	//printf("%i\n", iCounter);									// display limit value

	//// 3. sentinel controlled
	//string strInput;											// User input
	//int iInput = 0;												// User input converted to integer
	//int iSentinel = 100;										// Sentinel, must match to close loop

	//while (iInput != iSentinel)									// Loop until matching sentinel
	//{
	//	printf("Enter a number (100 to end): ");				// Prompt for user input
	//	getline(cin, strInput);									// Get user input
	//	iInput = atoi(strInput.c_str());						// Convert to integer

	//}

	// 4. Flag Controlled
	int iInput = 0;												// User input
	int iCatch = 1000;											// Catch value for setting flag
	string strInput;											// User input
	bool bFlag = false;											// Boolean flag

	while (!bFlag)												// Loop while the flag is not set
	{
		printf("Enter a number (%i to quit): ", iCatch);
		getline(cin, strInput);									// Get user input
		iInput = atoi(strInput.c_str());						// Convert to integer

		if (iInput == iCatch)									// Look for a match
			bFlag = true;										// Set the flag

	}
}
