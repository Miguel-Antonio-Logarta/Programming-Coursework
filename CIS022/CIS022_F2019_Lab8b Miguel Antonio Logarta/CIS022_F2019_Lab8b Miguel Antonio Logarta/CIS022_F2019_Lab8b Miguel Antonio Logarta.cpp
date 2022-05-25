// Project: CIS022_F2019_Lab8b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 6, 2019
// Purpose: Learn how to define a multi-dimensional array
//			Learn how to traverse and interact with a multi-dimensional array
//			Load a multi-dimensional array from user-input

#include <iostream>
#include <string>

using namespace std;

const int USER_COUNT = 3;	 	// number of user records
const int INFO_ITEMS = 5;	 	// number of info items

// Notes: 2-dimensional arrays must have a specified size in order to work. That's why we declared the constants above


void GetUserInput(string strA[USER_COUNT][INFO_ITEMS])
{
	// Heading
	printf("Please Enter User Information\n\n");

	for (int i = 0; i < USER_COUNT; i++)						// Roll through array records
	{
		printf("\nUser %i\n\n", i + 1);							// Prompt for user

		printf("Last Name: ");									// Prompt for last name
		getline(cin, strA[i][0]);								// Get last name

		printf("First Name: ");									// Prompt for first name
		getline(cin, strA[i][1]);								// Get first name

		printf("Address: ");									// Prompt for address
		getline(cin, strA[i][2]);								// Get address

		printf("City: ");										// Prompt for city
		getline(cin, strA[i][3]);								// Get city

		printf("State: ");										// Prompt for state
		getline(cin, strA[i][4]);								// Get state
	}
}

void DisplayUserInput(string strA[USER_COUNT][INFO_ITEMS])
{
	printf("\n\nContact List\n\n");								// Header

	for (int i = 0; i < USER_COUNT; i++)						// Roll through array
	{
		printf("User %i \n\n", i + 1);							// 1 through 3

		printf("Name:        %s %s\n",							// First name and last name
			strA[i][1].c_str(),
			strA[i][0].c_str());

		printf("Address:     %s\n",								// Address
			strA[i][2].c_str());

		printf("City:        %s, %s\n\n",						// City, state
			strA[i][3].c_str(),
			strA[i][4].c_str());

	}
}


int main()
{
	string strInput[USER_COUNT][INFO_ITEMS];	 				// array of user data

	GetUserInput(strInput);	 									// prompt for user data
	DisplayUserInput(strInput);	 								// display collected data

	cout << endl << endl;	 									// blank line
	system("Pause");	 										// pause before closing
	return 0;	 												// end program
}
