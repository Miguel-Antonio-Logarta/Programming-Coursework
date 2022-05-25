// Project: CIS022_F2019_Lab10a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 20, 2019
// Purpose: Learn how to define a class
//			Learn how to create an object from a class
//			Call a method
//			Pass data to and from an object

#include "CIS022_F2019_Lab10a.h"								// Project header

int main()
{
	string strStringToPrint;									// Create a variable to capture the return string

	HelloClass HelloObject;										// Obstentiate an object of HelloClass method

	strStringToPrint = HelloObject.SayHello("Miguel");			// Call the SayHello() method, pass my name as the parameter, 
																//and capture the return value into strStringToPrint
	printf("%s", strStringToPrint.c_str());						// Print the string
	
	cout << endl << endl;										// Blank lines
}
