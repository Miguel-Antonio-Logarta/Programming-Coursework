// Project: CIS022_F2019_HW4 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 2, 2019
// Purpose: Understand a complex problem
//			Demonstrate the correct use of conditional control structures


#include <iostream>
#include <string>									// String library

using namespace std;								// Standard namespace

int main()
{
	// Variables for us to use
	string strPlanetName;
	string strUserWeight;
	int iPlanetName;
	double dUserWeight;
	double dPlanetFactor;
	double dCalculatedWeight;

	// These variables are set to -1 by default to prevent it from calculating the weight later if incorrect
	dUserWeight = -1;
	dPlanetFactor = -1;

	// Title
	printf("CALCULATE YOUR WEIGHT ON ANOTHER PLANET \n\n");

	// List out all the planets for the user to select
	printf("Select a planet...\n");
	printf("0:  The Sun\n"
		"1:  Mercury\n"
		"2:  Venus\n"
		"3:  Earth\n"
		"4:  Moon\n"
		"5:  Mars\n"
		"6:  Jupiter\n"
		"7:  Saturn\n"
		"8:  Uranus\n"
		"9:  Neptune\n"
		"10: Pluto\n\n");

	// Ask for the user for input
	printf("Enter the number of the planet: ");
	getline(cin, strPlanetName);

	// Check if the user's input for the planets correspond to a number
	// 1 check if the user entered something
	if (strPlanetName == "")
		printf("Error: The number of the planet wasn't entered.\n");
	else
	{
		iPlanetName = atof(strPlanetName.c_str());

		// 2 check if the input was a number
		if (iPlanetName == 0 && strPlanetName != "0")
			printf("Error: The input of the planet was not a number\n");
		
		else
		{
			// 3 check if the input of the user corresponds to a planet
			// If the number does correspond to a planet, set the factor to the planet selected
			switch (iPlanetName)
			{
				case 0:
					// The Sun
					dPlanetFactor = 27.072;
					break;
				case 1:
					// Mercury
					dPlanetFactor = 0.378;
					break;
				case 2:
					// Venus
					dPlanetFactor = 0.907;
					break;
				case 3:
					// Earth
					dPlanetFactor = 1.0;
					break;
				case 4:
					// Moon
					dPlanetFactor = 0.166;
					break;
				case 5:
					// Mars
					dPlanetFactor = 0.377;
					break;
				case 6:
					// Jupieter
					dPlanetFactor = 2.364;
					break;
				case 7:
					// Saturn
					dPlanetFactor = 1.064;
					break;
				case 8:
					// Uranus
					dPlanetFactor = 0.889;
					break;
				case 9:
					// Neptune
					dPlanetFactor = 1.125;
					break;
				case 10:
					// Pluto
					dPlanetFactor = 0.067;
					break;
				default:
					// If the number inputted doesn't correspond to any of the planet numbers
					printf("The number inputted doesn't correspond to a planet.\n");
					break;
			}
		}
	}

	// Check if we got a factor to calculate with
	if (dPlanetFactor == -1)
	{
		printf("\nDid not calculate the weight. The planet was not selected.");
	}
	// Proceed to ask for weight if we have a factor to calculate with
	else
	{
		// Now ask for the user's weight
		printf("What is your weight in lbs?: ");
		getline(cin, strUserWeight);

		// 1 check if the input is not blank
		if (strUserWeight == "")
			printf("Error: The weight was left blank.\n");
		else
		{
			// 2 check if the input was a number
			dUserWeight = atof(strUserWeight.c_str());

			if (dUserWeight == 0 && strUserWeight != "0")
			{
				printf("Error: Please enter a number for your weight.\n");
				dUserWeight = -1;				// This is so that later on we can check if the input for the weight was actually correct
			}
			else
			{
				// 3 check if the input is in range
				if (dUserWeight < 0)
					printf("Error: You cannot have negative weight.\n");
			}
		}

		// Check if we have a weight to work with
		if (dUserWeight < 0)
			printf("\nDid not calculate the weight. The weight was not a valid number.");
		// Now calculate the weight
		else
		{
			dCalculatedWeight = dUserWeight * dPlanetFactor;
			printf("Your weight would be: %.3f lbs.", dCalculatedWeight);
		}
	}
		
	printf("\n\n"); // Leave two blank lines on the bottom of the program
	
}
