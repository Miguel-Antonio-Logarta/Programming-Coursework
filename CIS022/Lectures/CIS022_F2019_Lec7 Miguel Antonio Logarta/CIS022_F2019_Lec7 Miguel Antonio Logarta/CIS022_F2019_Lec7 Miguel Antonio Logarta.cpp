// Project: CIS022_F2019_Lec7 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 30, 2019
// Purpose:	Discover the built-in functions of the <string> library
//			Learn how to use the functions built-in to the <string> library.
//			Manipulate strings using standard functions


#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 1. string operations
	
	// Declaration
	string strOne;							// Declare a variable of type string
											// Obstantiate an object of class string


	// Initialize
	string strTwo = "Two";													// Set value when created

	// Assign with arithmetic
	strOne = strTwo;														// Set the value
	strOne += strTwo;														// Append

	// Display the values
	printf("strOne = %s \n", strOne.c_str());
	printf("strTwo = %s \n", strTwo.c_str());

	// Operators
	if (strOne > strTwo)
		printf("strOne > strTwo because strOne dresses fancy. \n");
	else
		printf("What? \n");


	// 2. String functions - page 496 of your textbook
	string strInput;														// User input
	printf("Enter a string of text: ");										// Prompt
	getline(cin, strInput);													// Get user input

	// .at																	// Gets a char of a string
	printf("0th char in a string: %c \n", strInput.at(0));

	strInput.at(0) = toupper(strInput.at(0));								// Capitalize the string
	printf("%s\n", strInput.c_str());

	// .append																// Concatinate chars to a string
	strInput.append(1, ' ');												// Append a space
	strInput.append("NOW!");												// Append a string
	printf("Append a space and a string: %s \n", strInput.c_str());

	// .clear																// Clears the string
	strInput.clear();														// All gone
	printf("strInput: %s\n", strInput.c_str());

	strInput = "Doggy";														// Refill the string

	// .compare																// Compare two strings
	if (strInput.compare("doggy"))
		printf("YES!\n");
	else
		printf("NO!\n");
	printf("Compare: %i \n", strInput.compare("doggy"));					// Number return

	// .empty																// Is the string empty?
	strInput.empty() ?														// Trinary look at empty()
		printf("strInput is empty \n") :
		printf("strInput is not empty \n");

	// .erase																// Same as clear()

	// .erase(pos, n)														// Erases n chars at pos
	strInput.erase(2, 1);													// Erase a g from Doggy
	printf("strInput = %s\n", strInput.c_str());								

	// .find																// Search a string in a string
	int iFind = strInput.find("gy");										// Look for gy in string
	printf("gy was found at: %i \n", iFind);

	// .insert																// Inserts chars in a string
	strInput.insert(2, 5, 'g');												// Insert 5 g's into the string
	printf("strInput: %s \n", strInput.c_str());

	// .replace																// Substitue chars in a string
	strInput.replace(2, 7, "gg");											// replace(pos, n, str) starting position, number of characters to replace, the string that will replace them	
	printf("strInput: %s \n", strInput.c_str());

	// .substr																// Return a sub-string
	printf("Substring of strInput starting at 1, 2 chars: %s \n",
		strInput.substr(1, 2).c_str());

	// size																	// same as length
	printf("The size of strInput is %i \n",
		strInput.size());

	// .swap
	string str2 = "kitty";													// 2nd string for swap
	strInput.swap(str2);													// Swap the strings

	printf("strInput = %s \nstr2 = %s \n", 
		strInput.c_str(), str2.c_str());


	// Blank lines
	cout << endl << endl;
}
