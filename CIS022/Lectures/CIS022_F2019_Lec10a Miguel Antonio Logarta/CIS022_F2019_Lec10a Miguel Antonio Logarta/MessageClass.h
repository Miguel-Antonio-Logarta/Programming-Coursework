// Module:	MessageClass.h
// Project:	CIS022_F2019_Lec10a
// Author:	Miguel Antonio Logarta
// Date:	November 18, 2019
// Purpose: Header file for MessageClass
//			Mimic MessageBox() function

#pragma once
class MessageClass
{
public:

	void MessageBox(string);													// Simple message box

	void MessageBox(string, int, string);										// Overloaded message box

};

