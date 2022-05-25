// Project: BallClass.h
// Author:	Miguel Antonio Logarta
// Date:	February 12, 2020
// Purpose:	Header file for BallClass.h

#pragma once
class BallClass
{
public:
	BallClass(int);										// Contructor overload

	void Draw(HDC);										// Answer WM_PAINT
	bool Move(HWND);									// Move graphic
	RECT GetInvalidRect();								// Calculate rectangle for paint

private:

	RECT rDim;											// Dimension of sphere
	int r, g, b;										// Color
	RECT rReturn;										// Return value for GetInvalidRect()

	int GetRandomInt(int, int);							// Generate a random number
};

