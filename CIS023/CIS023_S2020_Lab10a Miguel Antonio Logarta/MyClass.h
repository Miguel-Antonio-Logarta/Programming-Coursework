// Module:	MyClass.h
// Author:	Miguel Antonio Logarta
// Date:	January 27, 2020
// Purpose: Header file for MyClass.cpp
//			"Add some class"

#pragma once
class MyClass
{
public:
	MyClass();						// Constructor. Executes when obstentiated
	~MyClass();						// Destructor. Executes when object falls out of scope

	void SayHello();				// Message method
private:
};

