// Project: CIS022_F2019_Lec10b.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 25, 2019
// Purpose: Define a storage class
//			Create and interact with object arrays and file i/o
//			Interact with accessors and mutators

#include "CIS022_F2019_Lec10b.h"								// Include project header

bool LoadArray(AddressClass Add[])
{
	ifstream inFile;											// Handle to input file
	string strFileName =										// Input file name
		"CIS022_F2019_Lec10b_Data.csv";
	string strData;												// Input data from file

	inFile.open(strFileName);									// Open the input file

	if (inFile.is_open())										// Did the file open
	{
		for (int i = 0; i < FILE_SIZE; i++)						// Loop through all lines of the input file
		{
			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetFirstName(strData);						// Set first name

			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetLastName(strData);						// Set last name

			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetStreet(strData);							// Set street name

			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetCity(strData);							// Set city

			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetState(strData);							// Set state

			getline(inFile, strData, ',');						// Comma delimited
			Add[i].SetZip(strData);								// Set zip

			getline(inFile, strData, '\n');						// End of line
			Add[i].SetPhone(strData);							// Set phone number
		}

		inFile.close();											// Close the input file
		return true;											// File loaded okay
	}

	return false;												// Load failed
}

void DisplayArray(AddressClass Add[])
{
	for (int i = 0; i < FILE_SIZE; i++)							// Roll through array
	{
		printf("%s %s \n",										// First name last name
			Add[i].GetFirstName().c_str(),
			Add[i].GetLastName().c_str());

		printf("%s \n", Add[i].GetStreet().c_str());			// Street

		printf("%s, %s %s \n",									// City, state, zip
			Add[i].GetCity().c_str(),
			Add[i].GetState().c_str(),
			Add[i].GetZip().c_str());

		printf("%s \n\n", Add[i].GetPhone().c_str());			// Phone number
	}

}

int main()
{
	AddressClass Addresses[FILE_SIZE];							// Array of objects

	//// Test code
	//Addresses[0].SetLastName("Goober");

	//string strTemp;
	//strTemp = Addresses[0].GetLastName();
	//printf("Name: %s\n", strTemp.c_str());

	if (LoadArray(Addresses))									// Load array from data file
		DisplayArray(Addresses);								// Dump data to the console

	cout << endl << endl;										// Blank lines
}
