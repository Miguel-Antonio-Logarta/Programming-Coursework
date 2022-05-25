// Project: CIS022_F2019_HW5 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 17, 2019
// Purpose:	Understand a complex problem
//			Produce code that properly uses loop control structures
//			Write code that solves a complex problem

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Variable to take in user input
	string strUserInput;

	// Title
	printf("STRING ENCRYPTER / DECRYPTER \n\n");

	// Ask user for input
	printf("Type in a message: ");
	getline(cin, strUserInput);
		
	// Encrypt the message
	for (int i = 0; i < strUserInput.length(); i++)
		strUserInput[i] += 10;										// Add 10 to the ascii value of the current character

	// Display the encrypted message
	printf("Your encrypted message is: %s\n", strUserInput.c_str());

	// Decrypt the message
	for (int i = 0; i < strUserInput.length(); i++)
		strUserInput[i] -= 10;										// Subtract 10 to the ascii value of the current character

	// Display the decrypted message
	printf("Your decrypted message is: %s\n", strUserInput.c_str());

	// Blank lines
	printf("\n\n");
}
