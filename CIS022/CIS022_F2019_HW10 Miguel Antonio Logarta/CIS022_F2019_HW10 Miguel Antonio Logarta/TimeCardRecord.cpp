// Project: CIS022_F2019_HW10 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	December 3, 2019
// Purpose: Implementation file for storage class TimeCardRecord
#include "CIS022_F2019_HW10 Miguel Antonio Logarta.h"

void TimeCardRecord::SetLastName(string strIn)
{
	strLastName = strIn;
}

void TimeCardRecord::SetFirstName(string strIn)
{
	strFirstName = strIn;
}

void TimeCardRecord::SetCity(string strIn)
{
	strCity = strIn;
}

void TimeCardRecord::SetWageAmount(double dIn)
{
	dWageAmount = dIn;
}

void TimeCardRecord::SetNumberOfHours(double dIn)
{
	dNumberOfHours = dIn;
}

void TimeCardRecord::SetGrossPay(double dIn)
{
	dGrossPay = dIn;
}

string TimeCardRecord::GetLastName()
{
	return strLastName;
}

string TimeCardRecord::GetFirstName()
{
	return strFirstName;
}

string TimeCardRecord::GetCity()
{
	return strCity;
}

double TimeCardRecord::GetWageAmount()
{
	return dWageAmount;
}

double TimeCardRecord::GetNumberOfHours()
{
	return dNumberOfHours;
}

double TimeCardRecord::GetGrossPay()
{
	return dGrossPay;
}
