// Project: CIS022_F2019_Lec6b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 23, 2019
// Purpose:	Learn how to create void-returning functions
//			Pass values by reference
//			Understand the limitations of scope of a function parameter

#include <iostream>
#include <string>

using namespace std;

void Function1()							// Void function
{
	printf("Function 1 \n");				// Note: no return value

}

void Function2(int iIn)						// Void function with parameter
{
	printf("%i \n", iIn);
}

void Function3(string strIn)				// Void function with a complex parameter
{
	printf("%s \n", strIn.c_str());
}

void NextChar(char& cWork)					// Reference variables - note the & symbol
{
	cWork++;								// Next char in ASCII table
}

void GetString(string& strString)			// Reference variable
{
	printf("Please enter text: ");			// Prompt for input
	getline(cin, strString);				// Get user input, store in parameter
}

void Parse(string strIn, char& a, char& b, char& c, char& d, char& e)
{
	if (strIn.length() < 5)					// String must be at least 5 chars
		printf("Input must be at leas5 5 chars \n\n");

	// Set reference variables
	a = strIn[0];
	b = strIn[1];
	c = strIn[2];
	d = strIn[3];
	e = strIn[4];
}

bool ParseFixed(string strIn, char& a, char& b, char& c, char& d, char& e)
{
	if (strIn.length() < 5)					// String must be at least 5 chars
	{
		printf("Input must be at least 5 chars \n\n");
		return false;						// Don't continue
	}
		
	// Set reference variables
	a = strIn[0];
	b = strIn[1];
	c = strIn[2];
	d = strIn[3];
	e = strIn[4];

	return true;							// It worked
}

int main()
{
	//// 1. Void functions
	//Function1();
	//Function2(12345);
	//Function3("Welcome to class!");

	//// 2. Reference parameter
	//char cIn;								// User input
	//printf("Enter a character: ");			// Prompt
	//cin >> cIn;								// Get user input
	//printf("Before: %c \n", cIn);			// Echo user input
	//NextChar(cIn);							// Call void function
	//printf("After: %c \n\n", cIn);			// Call void function
	

	//// 3. Complex reference parameter
	//string strReference;					// User input

	//printf("Reference parameter before call to GetString() = '%s' \n\n", strReference.c_str());

	//GetString(strReference);

	//printf("Reference parameter after call to GetString() = '%s' \n\n", strReference.c_str());


	// 4. Multiple return values
	string strIn;							// User input
	char one, two, three, four, five;		// Reference variables

	GetString(strIn);						// Call function to get user input

	// Parse(strIn, one, two, three, four, five);	// This call is broken
	if (ParseFixed(strIn, one, two, three, four, five))
	{
		printf("The 1st 5 characters are: '%c', '%c', '%c', '%c', '%c' \n\n", one, two, three, four, five);
	}



	printf("\n\n");							// Blank lines
}
