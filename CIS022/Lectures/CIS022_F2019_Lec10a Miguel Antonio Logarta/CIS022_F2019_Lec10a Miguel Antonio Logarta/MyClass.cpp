// Module:	MyClass.h
// Project:	CIS022_F2019_Lec10a
// Author:	Miguel Antonio Logarta
// Date:	November, 18, 2019
// Purpose: Implementation for MyClass
//			Class code

#include "MyClass.h"												// Class header
#include "CIS022_F2019_Lec10a.h"									// Project header

MyClass::MyClass()
{
	printf("MyClass - Constructor\n");

}

MyClass::~MyClass()
{
	printf("MyClass - Destructor\n");


}

void MyClass::SayHello()
{
	printf("MyClass = Hello\n");
}
