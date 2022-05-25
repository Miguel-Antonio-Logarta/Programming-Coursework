// Project: CIS022_F2019_Lec5c.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 16, 2019
// Purpose: Learn how to solve complex problems using nested loops
//			Perform the calculations for a Fibonacci sequence.
//			Introduce the <string> library
//			Use the getline() function for string input
//			Use the printf() function for formatted output

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 1. Get numbers from the user
	// 2. If seq is 1, just print 1
	// 3. If seq is 2, print the first two numbers
	// 4. If seq > 2, use a for loop to find the sequence of numbers (Start 03, seq, count)
	// 5. Addition
	// 6. Display

	int iNum1 = 0;												// 1st user input
	int iNum2 = 0;												// 2nd user input
	int iSequence = 0;											// 3rd user input
	int iCurrent = 0;											// Calculated value
	string strInput;											// User input
	bool bIsNumber = true;										// True if user input is a number

	printf("FIBONACCI\n\n");									// Title
	do {

		// Get 1st value from user
		do
		{
			printf("Enter the first number in the sequence: ");
			getline(cin, strInput);									// Get user input

			// Make sure input is a number
			bIsNumber = true;
			for (int i = 0; i < strInput.length(); i++)				// Loop through each character
				if (strInput[i] < '0' || strInput[i] > '9')			// Must be between 0 and 9
					if (strInput != "-")							// If it is not a dash that indicates that it is negative
						bIsNumber = false;							// Set the bool to false since it is not a number
		} while (!bIsNumber || strInput.length() == 0);

		// Cannot get here until 1st number is valid
		iNum1 = atoi(strInput.c_str());								// Convert user input to integer

		// Get 2nd value from user
		do
		{
			printf("Enter the second number in the sequence: ");
			getline(cin, strInput);									// Get user input

			// Make sure input is a number
			bIsNumber = true;
			for (int i = 0; i < strInput.length(); i++)				// Loop through each character
				if (strInput[i] < '0' || strInput[i] > '9')			// Must be between 0 and 9
					if (strInput != "-")							// If it is not a dash that indicates that it is negative
						bIsNumber = false;							// Set the bool to false since it is not a number
		} while (!bIsNumber || strInput.length() == 0);

		// Cannot get here until 2nd number is valid
		iNum2 = atoi(strInput.c_str());								// Convert 2nd user input to integer

		// Get the sequence number from the user
		do
		{
			printf("Enter number of values to discover: ");
			getline(cin, strInput);									// Get user input

			// Make sure input is a number
			bIsNumber = true;
			for (int i = 0; i < strInput.length(); i++)				// Loop through each character
				if (strInput[i] < '0' || strInput[i] > '9')			// Must be between 0 and 9
					if (strInput != "-")							// If it is not a dash that indicates that it is negative
						bIsNumber = false;							// Set the bool to false since it is not a number
		} while (!bIsNumber || strInput.length() == 0);

		// Cannot get here until sequence number is valid
		iSequence = atoi(strInput.c_str());							// Convert sequence user input to integer

		// Display Fibonacci sequence
		if (iSequence == 1)											// If they only want 1 number
			printf("1. %i\n", iNum1);								// Display 1st number
		else if (iSequence == 2)									// If they want 2 numbers
		{
			printf("1. %i\n", iNum1);								// Display 1st number
			printf("2. %i\n", iNum2);								// Display 2nd number
		}
		else
		{
			printf("1. %i\n", iNum1);								// Display 1st number
			printf("2. %i\n", iNum2);								// Display 2nd number

			// Loop from 3 to the sequence number
			for (int iCounter = 3; iCounter <= iSequence; iCounter++)
			{
				iCurrent = iNum1 + iNum2;							// Calculate new value
				iNum1 = iNum2;										// 1st number becomes 2nd number
				iNum2 = iCurrent;									// 2nd number becomes new claculated value

				// Display the value
				printf("%i. %i\n", iCounter, iCurrent);
			}
		}

		// Prompt user, want another run?
		printf("\n\nWould you like another (Y/N)?");
		getline(cin, strInput);

		strInput[0] = toupper(strInput[0]);
		printf("\n\n");



	} while (strInput[0] == 'Y');									// Repeat until user is done 


	printf("\n\n");													// Blank lines
}
