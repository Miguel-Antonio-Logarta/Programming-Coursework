// Project: CIS022_F2019_Lec10a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 18, 2019
// Purpose:	Define a class
//			Create and interact with objects
//			Pass parameters to an object

//#include <iostream>
//#include <string>
//
//using namespace std;

#include "CIS022_F2019_Lec10a.h"							// Project header

int main()
{
	MyClass MyObject;										// Obsentiate an object type of MyClass

	MyObject.SayHello();									// Call method

	MessageClass MessageObject;								// Obsteniate
	MessageObject.MessageBox("Hello my good sir.");

	MessageObject.MessageBox("Welcome to CIS 001 from Miguel",
		0,
		"Hello");

	MessageObject.MessageBox("Why did the chicken cross the road",
		1, "Why");

	MessageObject.MessageBox("To get to the other side",
		2, "Because");

	MessageObject.MessageBox("That is all", 3, "Thank you");

	cout << endl << endl;									// Blank lines
}
