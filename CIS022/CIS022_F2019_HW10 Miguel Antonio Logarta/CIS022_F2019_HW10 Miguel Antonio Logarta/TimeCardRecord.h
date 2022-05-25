// Project: CIS022_F2019_HW10 Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	December 3, 2019
// Purpose: Header file for TimeCardRecord Class
#pragma once
class TimeCardRecord
{
public:
	// Mutators
	void SetLastName(string);
	void SetFirstName(string);
	void SetCity(string);
	void SetWageAmount(double);
	void SetNumberOfHours(double);
	void SetGrossPay(double);

	// Accessors
	string GetLastName();
	string GetFirstName();
	string GetCity();
	double GetWageAmount();
	double GetNumberOfHours();
	double GetGrossPay();

private:
	// Members that will hold the data
	string strLastName;
	string strFirstName;
	string strCity;
	double dWageAmount;
	double dNumberOfHours;
	double dGrossPay;
};

