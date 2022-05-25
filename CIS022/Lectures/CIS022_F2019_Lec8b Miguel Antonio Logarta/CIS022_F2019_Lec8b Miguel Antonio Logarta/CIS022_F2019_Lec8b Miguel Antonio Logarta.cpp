// Project: CIS022_F2019_Lec8b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 6, 2019
// Purpose: Review how to define an array, with and without preset values
//			Learn how to traverse and interact with 

#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

int GetRandomInt(int iLow, int iHigh)
{
	random_device rd;																// Non-deterministic generator
	mt19937 gen(rd());																// Seed mersenne twister
	uniform_int_distribution<> dist(iLow, iHigh);									

	return dist(gen);																// Return random integer
}

int main()
{
	//// 1. Simple, multi-dimensional array
	//const int WIDTH = 80;															// Screen width
	//const int HEIGHT = 26;															// Alphabet, A to Z

	//char screen[WIDTH][HEIGHT];														// 80 x 26 array

	//// Fill array with alphabet
	//for (int i = 0; i < HEIGHT; i++)												// Roll through columns
	//	for (int j = 0; j < WIDTH; j++)												// Roll through rows. Use j instead of i because i is already used
	//		screen[i][j] =															// Insert char in array
	//		static_cast <char> (65 + i);											// ASCII character

	//// Display array values on console
	//for (int i = 0; i < HEIGHT; i++)												// Roll through columns
	//	for (int j = 0; j < WIDTH; j++)												// Roll through rows. Use j instead of i because i is already used
	//		cout << screen[i][j];													// Display contents of array


	//// 2. 3-dimensional array
	//int Coordinates[3][3][3];														// 3-dimensional array. It is 3 x 3 x 3 array that holds values

	//for (int x = 0; x < 3; x++)														// x-dimension
	//	for (int y = 0; y < 3; y++)													// y-dimension
	//		for (int z = 0; z < 3; z++)												// z-dimension
	//			Coordinates[x][y][z] =												// Fill array with random single digit
	//			GetRandomInt(0, 9);

	//// Display array
	//for (int x = 0; x < 3; x++)														// x-dimension
	//	for (int y = 0; y < 3; y++)													// y-dimension
	//		for (int z = 0; z < 3; z++)												// z-dimension
	//			printf("(%i, %i, %i) = %i\n", x, y, z, Coordinates[x][y][z]);		// (Coordinates) = value of that particular coordinate


	// 3. Load a 2-dimensional array from a csv file
	const int LINES = 24;															// Number of lines in the file
	const int ITEMS = 7;															// Number of columns in the file

	string Addresses[LINES][ITEMS];													// Array of data from file

	string strFileName =															// Filespec
		"CIS022_F2019_Lec8b_Data.csv";
	ifstream inFile;																// File handle

	inFile.open(strFileName);														// Open the file

	if (inFile.is_open())															// If the file opened alright
	{
		printf("Loading...\n");														// Tell the user the file is loading

		for (int i = 0; i < LINES; i++)												// Read all the lines from the file
		{
			for (int j = 0; j < ITEMS-1; j++)											// Read each data item in line
				getline(inFile, Addresses[i][j], ',');								// Store each data into the array. Do not include commas

			getline(inFile, Addresses[i][ITEMS - 1], '\n');							// Read last column \n delimited

		}

		for (int i = 0; i < LINES; i++)												// Lines from the file
			for (int j = 0; j < ITEMS; j++)											// Items in the line
				printf("%s ", Addresses[i][j].c_str());

		printf("done\n");															// Finished reading file

		inFile.close();																// Close the file
	}
	
	// Formatted output
	for (int i = 0; i < LINES; i++)													// One row per label
	{
		printf("%s %s \n",															// First name and last name
			Addresses[i][0].c_str(),
			Addresses[i][1].c_str());

		printf("%s \n", 
			Addresses[i][2].c_str());												// Street address

		printf("%s, %s %s \n",														// City, state zip
			Addresses[i][3].c_str(),
			Addresses[i][4].c_str(),
			Addresses[i][5].c_str());

		printf("%s \n\n",
			Addresses[i][6].c_str());
	}

	cout << endl << endl;
}
