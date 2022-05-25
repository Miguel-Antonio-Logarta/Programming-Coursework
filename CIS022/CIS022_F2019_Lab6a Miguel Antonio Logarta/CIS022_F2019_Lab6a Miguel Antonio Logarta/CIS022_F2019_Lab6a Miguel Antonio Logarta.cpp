// Project: CIS022_F2019_Lab6a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 21, 2019
// Purpose: Use predefined functions
//			Create user-defined functions
//			Create value-returning functions
//			Pass values to and from functions

#include <iostream>
#include <string>											// String library
#include <random>											// Random library

using namespace std;										// Standard namespace

int GetRandomInt(int iLow, int iHigh)						// Generate random number
{
	random_device rd;										// Non-deterministic generator
	mt19937 gen(rd());										// Seed mersenne twister
	uniform_int_distribution<>								// Distributed results between
		dist(iLow, iHigh);									//		iLow and iHigh inclusive

	return dist(gen);										// Return pseudo-random int
}

int main()
{
	bool bWinner = false;									// Set win condition to false
	do {
		// Start variables
		string strUserInput;
		int iUserInput;
		int iTotalDiceValue = 0;
		bool bIsNumber = true;
		bool bInRange = true;
		

		// Check for input
		do {
			printf("Enter a number between 2 and 12: ");
			getline(cin, strUserInput);						// Get user input

			iUserInput = atoi(strUserInput.c_str());		// Convert user input to integer

			// Always reset to true every time the loop starts
			bIsNumber = true;
			bInRange = true;

			// Check if the input is a number
			for (int i = 0; i < strUserInput.length(); i++)
				if (strUserInput[i] < '0' || strUserInput[i] > '9')
					bIsNumber = false;

			// Check if the number is in range
			if (iUserInput < 2 || iUserInput > 12)
				bInRange = false;

		} while (!bIsNumber || !bInRange);

		// Convert the user input to integer
		iUserInput = atoi(strUserInput.c_str());

		// Rolle the dice twice and add the total value
		for (int i = 0; i < 2; i++)
			iTotalDiceValue += GetRandomInt(1, 6);

		// Make sure the win condition has been reset before checking
		bWinner = false;

		// Check if the input matches the dice value
		if (iUserInput == iTotalDiceValue)				// If the dice value matches
		{
			printf("Winner!\n");						// Print winner and set win condition to true
			bWinner = true;
		}
		else
			printf("It didn't match!\n");				// Print didn't match. The win condition is set to false which triggers the loop to start again

	} while (!bWinner);
}

