// Project: CIS022_F2019_Lab4d Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 2, 2019
// Purpose:	Review conditional operators
//			Perform input verification with an if statements
//			Use simple mathematical expressions

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// title of the program
	printf("This is a horsepower calculator.\n\n");

	// user input variables
	string strTorque;
	string strRPM;
	// strings converted to doubles
	int iTorque;
	int iRPM;
	// values that will be plugged into the equation
	int iValidTorque;
	int iValidRPM;
	// set the values to be negative. If it isn't changed, then don't plug them into the HP equation later
	iValidTorque = -1;
	iValidRPM = -1;

	// ask the user for input for the torque
	printf("Enter a torque value between 100 and 1,000: ");
	getline(cin, strTorque);

	// ask the user for input for the RPM
	printf("Enter an RPM value between 0 and 10,000: ");
	getline(cin, strRPM);

	// check the inputs for torque
	// 1 check if the input is empty
	if (strTorque == "")
		printf("Error: Torque has no value.\n");
	else
	{
		// 2 check if the input was a number
		iTorque = atof(strTorque.c_str());

		if (iTorque == 0 && strTorque != "0")													// if the user entered a string and not a number
			printf("Error: The value entered for the torque is not a number.\n");
		
		else
		{
			// 3 check the range
			if (iTorque < 100 || iTorque > 1000)
				printf("Error: The torque is out of range.\n");
			else
			{
				// if the input is correct set the value entered to iValidTorque
				iValidTorque = iTorque;
				printf("The torque is: %i\n", iValidTorque);
			}
				
		}
	}

	// check the inputs for RPM
	// 1 check if the input is empty
	if (strRPM == "")
		printf("Error: RPM has no value.\n");
	else
	{
		// 2 check if the input was a number
		iRPM = atof(strRPM.c_str());

		if (iRPM == 0 && strRPM != "0")
			printf("Error: The value entered for the RPM is not a number.\n");

		else
		{
			// 3 check the range
			if (iRPM < 0 || iRPM > 10000)
				printf("Error: The value entered for the RPM is out of range.\n");
			else
			{
				// if the value is correct, set the value entered to iValidRPM
				iValidRPM = iRPM;
				printf("The RPM is: %i\n", iValidRPM);
			}
		}


	}

	// calculate the horsepower
	int iHorsepower;
	const int FACTOR = 5252;

	if (iValidTorque != -1 || iValidRPM != -1)						// if the inputs for torque and RPM were correct and were changed
	{
		iHorsepower = (iValidTorque * iValidRPM) / FACTOR;
		printf("\nThe total horsepower is: %i\n", iHorsepower);
	}
	// if the inputs were incorrect, then print this instead of calculating the HP
	else
		printf("\nDid not calculate the total horsepower; The values entered were not right.\n");
		
}
