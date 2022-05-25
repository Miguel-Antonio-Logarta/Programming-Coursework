// Module:	MessageClass.h
// Project:	CIS022_F2019_Lec10a
// Author:	Miguel Antonio Logarta
// Date:	November 18, 2019
// Purpose: Implementation file for MessageClass
//			Mimic MessageBox() function

#include "CIS022_F2019_Lec10a.h"									// Project header

void MessageClass::MessageBox(string strMessage)
{
	printf("%s\n", strMessage.c_str());								// Display the message
}

void MessageClass::MessageBox(string strMessage, int emphasis, string strTitle)		
{
	cout << endl;													// New line

	char c;															// Emphasis
	switch (emphasis)
	{
	case 0: c = '!'; break;										// !
	case 1: c = '?'; break;									// ?
	case 2: c = 'i'; break;										// i
	case 3: c = ';'; break;										// ;
	default: c = '*'; break;
	}

	// Build top line
	printf("%c%c ", c, c);
	printf("%s ", strTitle.c_str());								// Title in top row
	for (int i = strTitle.length() + 4; i < strMessage.length() + 4; i++)
		printf("%c", c);
	cout << endl;													// Blank line

	// Border line
	printf("%c", c);
	for (int i = 0; i < strMessage.length() + 2; i++)
		printf(" ");
	printf("%c", c);
	cout << endl;													// New line

	// Message
	printf("%c ", c);
	printf("%s", strMessage.c_str());
	printf(" %c", c);
	cout << endl;

	// Border line
	printf("%c", c);
	for (int i = 0; i < strMessage.length() + 2; i++)
		printf(" ");
	printf("%c", c);
	cout << endl;													// New line

	// Bottom line
	for (int i = 0; i < strMessage.length() + 4; i++)
		printf("%c", c);
	cout << endl;


	cout << endl;													// New line

}
