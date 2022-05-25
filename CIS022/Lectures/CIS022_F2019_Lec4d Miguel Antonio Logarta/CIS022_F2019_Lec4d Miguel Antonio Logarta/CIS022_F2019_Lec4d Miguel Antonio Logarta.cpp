// Project: CIS022_F2019_Lec4d Miguel Antonio Logarta.cpp 
// Author:	Miguel Antonio Logarta
// Date:	October 2, 2019
// Purpose:	Learn the stop necessary to validate numeric input
//			Contrast the techniques to validate whole number from decimal number input

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//// integer input validation

	//string strIn;										// user input string
	//int iIn;											// string converted to integer

	//// get user input
	//printf("Enter a number between 0 and 10: ");
	//getline(cin, strIn);								// assign the input to strIn

	//// 1 check for input, any input
	//if (strIn == "")									// if input string is empty
	//	printf("Error: No input was entered.\n");		// error message if the user does not input anything

	//else
	//{


	//	// 2 check for an integer

	//	iIn = atoi(strIn.c_str());						// convert user input to integer

	//	if (iIn == 0 && strIn != "0")					// if iIn is equal to 0 (meaning the input is either 0 or a string) and the original string is not 0
	//		printf("Error: Input is not a valid number.\n");
	//	else
	//	{

	//		// 3 check for range (0 - 10)
	//		if (iIn < 0 || iIn > 10)					// less than 0, greater than 10, out of range
	//			printf("Error: Input is out of range.\n");

	//		else
	//			// display the value if it is valid
	//			printf("The number entered is %i.\n", iIn);

	//	}

	//}


	// check for valid decimal input

	string strIn;										// user input
	double dIn;											// convert the string to a double

	// get user input
	printf("Please enter a decimal number between 0 and 10: ");
	getline(cin, strIn);

	// 1 check for input
	if (strIn == "")									// check if the user entered nothing
		printf("Error: There was no value entered.\n");

	else
	{
		// 2 check for a double
		dIn = atof(strIn.c_str());						// convert the string into a double / floating point

		if (dIn == 0 && strIn != "0")					// if the string converts a 0 (means that a string instead of a float was entered)
			printf("Error: The input was not a number.\n");

		else
		{
			// 3  check range
			if (dIn < 0.0 || dIn > 10.0)				// if the value is not between 0 and 10
				printf("Error: Input is out of range");

			else
				printf("The number entered is %.2f.\n", dIn);// if the value is in range, print this
		}
	}
}
