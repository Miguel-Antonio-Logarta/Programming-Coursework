// Project: CIS022_F2019_Lab6b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	October 23, 2019
// Purpose:	Create void-returning functions
//			Pass values by reference


#include <iostream>
#include <string>

using namespace std;

void UserInput(int& iInputNum1, int& iInputNum2)
{
	// Variables to capture user input
	string strUserInputNum1;
	string strUserInputNum2;
	bool bIsNumber = true;

	// Ask user for input
	do
	{
		printf("Type in a number: ");
		getline(cin, strUserInputNum1);

		bIsNumber = true;
		for (int i = 0; i < strUserInputNum1.length(); i++)								// Loop through each character of the string
			if (strUserInputNum1[i] < '0' || strUserInputNum1[i] > '9')					// If out of range
				if (strUserInputNum1[i] != '-')											// If it is not a negative sign
					bIsNumber = false;													// Change it to false
	} while (!bIsNumber || strUserInputNum1.length() == 0);								// Loop through if the bool is false or if the string wasn't entered
	
	iInputNum1 = atoi(strUserInputNum1.c_str());										// Convert the string and assign to the reference variable

	// Ask user for the second input
	do
	{
		printf("Type in another number: ");
		getline(cin, strUserInputNum2);

		bIsNumber = true;
		for (int i = 0; i < strUserInputNum2.length(); i++)								// Loop through each character of the string
			if (strUserInputNum2[i] < '0' || strUserInputNum2[i] > '9')					// If out of range
				if (strUserInputNum2[i] != '-')											// If it is not a negative sign
					bIsNumber = false;													// Change it to false
	} while (!bIsNumber || strUserInputNum2.length() == 0);								// Loop through if the bool is false or if the string wasn't entered

	iInputNum2 = atoi(strUserInputNum2.c_str());										// Convert the string and assign to the reference variable
}

void Arithmetic(int& iInputNum1, int& iInputNum2, int& iAdd, int& iSubtract, int& iMultiply, double& dDivide)
{
	// Do the arithmetic and store them
	iAdd = iInputNum1 + iInputNum2;
	iSubtract = iInputNum1 - iInputNum2;
	iMultiply = iInputNum1 * iInputNum2;
	dDivide = (1.0)*iInputNum1 / iInputNum2;											// dDivide is a double because division is not always even, which means it could be a decimal
}


int main()
{
	// Variables for user input
	int iFirstNum;
	int iSecondNum;

	// Variables for arithmetic
	int iSum;
	int iDifference;
	int iProduct;
	double dQuotient;

	// Call functions to ask for user input and then output the calculated values
	UserInput(iFirstNum, iSecondNum);
	Arithmetic(iFirstNum, iSecondNum, iSum, iDifference, iProduct, dQuotient);

	// Display the arithmetic
	printf("%i + %i = %i\n", iFirstNum, iSecondNum, iSum);
	printf("%i - %i = %i\n", iFirstNum, iSecondNum, iDifference);
	printf("%i * %i = %i\n", iFirstNum, iSecondNum, iProduct);
	printf("%i / %i = %f\n", iFirstNum, iSecondNum, dQuotient);

	// Blank lines
	printf("\n\n");
}

