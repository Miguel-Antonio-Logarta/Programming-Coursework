// Project: CIS022_F2019_Lab7 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 30, 2019
// Purpose: Use the built-in functions of the <string> library
//			Manipulate strings using standard functions

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Start variables
	string strUserInput;
	string strReplacementChar;
	char cUserChar;

	// Capture user input
	cout << "Enter a word: ";
	cin >> strUserInput;
	
	// Find the first letter and store it
	cUserChar = strUserInput.at(0);

	// Loop through each character and move it one position forward
	for (int i = 1; i < strUserInput.length(); i++)
	{
		strReplacementChar = strUserInput[i];
		strUserInput.replace(i-1, 1, strReplacementChar);
	}

	// Replace the last letter
	strUserInput.at(strUserInput.length()-1) = cUserChar;

	// Add y to the end
	strUserInput.append("y");

	// Output the new word
	cout << strUserInput;

	// Blank lines
	cout << endl << endl;
}
