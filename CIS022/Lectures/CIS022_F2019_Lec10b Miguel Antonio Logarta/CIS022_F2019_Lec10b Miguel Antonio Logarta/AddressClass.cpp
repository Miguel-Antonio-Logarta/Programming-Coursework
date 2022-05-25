// Project: AddressClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	November 25, 2019
// Purpose: Implementation file for storage class

#include "CIS022_F2019_Lec10b.h"									// Project header

void AddressClass::SetLastName(string strIn)
{
	strLast = strIn;
}

void AddressClass::SetFirstName(string strIn)
{
	strFirst = strIn;
}

void AddressClass::SetStreet(string strIn)
{
	strStreet = strIn;
}

void AddressClass::SetCity(string strIn)
{
	strCity = strIn;
}

void AddressClass::SetState(string strIn)
{
	strState = strIn;
}

void AddressClass::SetZip(string strIn)
{
	strZip = strIn;
}

void AddressClass::SetPhone(string strIn)
{
	strPhone = strIn;
}

string AddressClass::GetLastName()
{
	return strLast;
}

string AddressClass::GetFirstName()
{
	return strFirst;
}

string AddressClass::GetStreet()
{
	return strStreet;
}

string AddressClass::GetCity()
{
	return strCity;
}

string AddressClass::GetState()
{
	return strState;
}

string AddressClass::GetZip()
{
	return strZip;
}

string AddressClass::GetPhone()
{
	return strPhone;
}
