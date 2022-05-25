// Project: CIS022_F2019_Lec6c Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 28, 2019
// Purpose: Learn how to use local and global variables
//			Learn how to use static variables
//			Perform function overloading
//			Add default parameters to a function

#include <iostream>
#include <string>

using namespace std;

void Display(int iIn)
{
	printf("Display %i \n", iIn);							// Display the integer
}

void Display(double dIn)
{
	printf("Display %.2f \n", dIn);							// Display the decimal value
}

//void Display(bool bIn)										// True or false
//{
//	bIn ?
//		printf("Display true\n") :
//		printf("Display false\n");
//}

void Display(string strIn)
{
	printf("%s \n", strIn.c_str());							// Display the string
}

// Default parameters
void AddNumbers(int A, int B, int C = 0, int D = 0, int E = 0)
{
	int iTotal = A + B + C + D + E;							// Add all of the parameters (provided or not)

	//printf("Total: %i \n", iTotal);							// Display the total
	Display(iTotal);										// Use the overloaded display function
}

int main()
{

	Display(15);											// Display an integer
	Display(123.321);										// Display a decimal 
	Display(true);											// Display a boolean value
	Display("Welcome to class. Please turn the lights out before you leave - if necessary.");	// Display a string

	// Default parameters
	AddNumbers(1, 2, 3, 4, 5);								// Give it all the parameters it wants
	AddNumbers(1, 2, 3, 4);									// Short one parameter
	AddNumbers(1, 2);										// Least amount allowed
	//AddNumbers(1);											// Not enough



	// Blank lines
	cout << endl << endl;
}
