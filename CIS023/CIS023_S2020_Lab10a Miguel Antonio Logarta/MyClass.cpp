// Module:	MyClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	January 27, 2020
// Purpose: Implementation file for MyClass.cpp
//			"Add some class"

#include "CIS023_S2020_Lab10a Miguel Antonio Logarta.h"

MyClass::MyClass()
{
	MessageBox(NULL,
		TEXT("MyClass constructuor"),
		TEXT("MyClass"),
		NULL);
}

MyClass::~MyClass()								// When you close the message box, this one will pop up after it is destroyed
{
	MessageBox(NULL,
		TEXT("MyClass deconstructuor"),
		TEXT("MyClass"),
		NULL);
}

void MyClass::SayHello()
{
	MessageBox(NULL,
		TEXT("MyClass SayHello() method"),
		TEXT("MyClass"),
		NULL);
}
