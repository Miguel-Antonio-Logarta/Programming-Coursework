// Project: CIS022_F2019_Lec6a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 21, 2019
// Purpose:	Learn how to use predefined functions
//			Learn how to create functions
//			Create value-returning functions
//			Pass values to and from functions

#include <iostream>
#include <string>
#include <cctype>									// Character library
#include <cmath>									// Math library
#include <random>									// Random number generator

using namespace std;

int iNumber()										// iNumber function used in 3.
{
	return 17;										// Return value
}

int iAddOne(int iIn)								// Add 1 to input integer
{
	//return iIn += 1;								// Return value

	//return iIn++;									// Increment after use. This means that it didn't even add since it already returned the variable before adding

	return ++iIn;									// Increment before use
}

int GetRandomInt(int iLow, int iHigh)				// Generate random number
{
	random_device rd;								// Non-deterministic generator
	mt19937 gen(rd());								// Seed mersenne twister
	uniform_int_distribution<>						// Distributed results between
		dist(iLow, iHigh);							//		iLow and iHigh inclusive

	return dist(gen);								// Return pseudo-random int
}

// Prototype
string ReverseString(string);						// Prototype of function at bottom


int main()
{
	//// 1. Some standard character functions included in <cctype>
	//char cIn, cOut;								// Input / output characters

	//printf("Enter a character: ");				// Prompt for input
	//cin >> cIn;									// Get user input

	//cOut = toupper(cIn);						// Set to upper case
	//printf("%c in upper case is %c\n\n", cIn, cOut);

	//cOut = tolower(cIn);
	//printf("%c in lower case is %c\n\n", cIn, cOut);

	//printf("%c is ", cIn);
	//islower(cIn) ? cout << "lower" : cout << "upper:";
	//printf(" case \n\n");

	//// 2. Math function include in <cmath>
	//double dIn, dOut;								// Input output

	//printf("Enter a positive or negative decimal value: ");
	//cin >> dIn;

	//dOut = abs(dIn);								// Absolute value
	//printf("The absolute value of %f is %f\n\n", dIn, dOut);

	//dOut = ceil(dIn);								// Ceiling
	//printf("The smallest whole number is not less than %f is %f \n\n", dIn, dOut);

	//// Floor here

	//dOut = cos(dIn);								// Cosine
	//printf("The cosine of %f is %f\n\n", dIn, dOut);

	//dOut = sqrt(dIn);								// Square root
	//printf("The square root of %f is %f\n\n", dIn, dOut);

	//// 3. User-defined functions
	//int iIn, iOut;								// Integer variables

	//iOut = iNumber();								// call iNumber() function
	//printf("%i \n\n", iOut);						// Display result

	//iOut = iAddOne(17);							// Call iAddOne() function
	//printf("%i \n\n", iOut);						// Display result

	//// 4. Random numbers
	//int iIn1, iIn2, iOut;						// Inputs and an output

	//printf("Enter two integers: ");
	//cin >> iIn1;								// Get user input
	//cin >> iIn2;								// Get user input for second variable

	//iOut = GetRandomInt(iIn1, iIn2);					// Get a random number in between the two numbers

	//printf("%i \n\n", iOut);					// Display random number

	//for (int i = 0; i < 100; i++)
	//	printf("%i ", GetRandomInt(iIn1, iIn2));

	// 5. Prototype
	string strInput;							// User input
	string strOutput;							// Return from ReverseString() function
	
	printf("Please enter a string of characters: ");
	getline(cin, strInput);						// Get user input

	strOutput = ReverseString(strInput);

	printf("Your string: \n%s\nreversed is:\n%s\n", strInput.c_str(), strOutput.c_str());


	// Blank line
	cout << endl << endl;
}

string ReverseString(string strIn)					// Reverse the chars in a string
{
	string strReturn;								// Return value

	for (int i = strIn.length() - 1; i >= 0; i--)
		strReturn += strIn[i];

	return strReturn;								// Return reversed string
}