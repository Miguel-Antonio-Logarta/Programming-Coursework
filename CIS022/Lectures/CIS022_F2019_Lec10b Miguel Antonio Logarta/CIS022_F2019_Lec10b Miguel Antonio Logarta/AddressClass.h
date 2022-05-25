// Project: AddressClass.h
// Author:	Miguel Antonio Logarta
// Date:	November 25, 2019
// Purpose: Header file for storage class

#pragma once
class AddressClass
{
public:
	// Mutators
	void SetLastName(string);						// Set strLast
	void SetFirstName(string);						// Set strFirst
	void SetStreet(string);							// Set strStreet
	void SetCity(string);							// Set strCity
	void SetState(string);							// Set strState
	void SetZip(string);							// Set strZip
	void SetPhone(string);							// Set strPhone

	// Accessors
	string GetLastName();							// Return strLast
	string GetFirstName();							// Return strFirst
	string GetStreet();								// Return strStreet
	string GetCity();								// Return strCity
	string GetState();								// Return strState
	string GetZip();								// Return strZip
	string GetPhone();								// Return strPhone


private:

	string strLast;									// Last name
	string strFirst;								// First name
	string strStreet;								// Street address
	string strCity;									// City name
	string strState;								// 2-letter state abbreviation
	string strZip;									// Postal zip code
	string strPhone;								// 10-digit phone number

};

