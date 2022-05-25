// Project: CIS022_F2019_HW10 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	December 3, 2019
// Purpose: Define classes
//			Create objects from user-defined classes
//			Interact with objects
//			Main module


#include "CIS022_F2019_HW10 Miguel Antonio Logarta.h"	 	// project header

int main()
{
	PayrollClass Payroll;	 								// payroll object

	// load the file into the time card array
	if (Payroll.LoadFile("CIS022_F2019_HW10_data.csv"))
	{
		Payroll.CalculatePay();	 							// calculate gross pay
		Payroll.Display();	 								// display values
		Payroll.Save("payroll.csv");	 					// save data to output file
	}

	cout << endl << endl << endl;	 						// blank lines
}