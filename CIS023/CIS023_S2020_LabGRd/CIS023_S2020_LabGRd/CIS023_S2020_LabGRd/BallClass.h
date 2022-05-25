// Module:	BallClass.h
// Author:	Miguel Antonio Logarta
// Date:	February 19, 2020
// Purpose:	Header file for BallClass.cpp
//			Creation, movement, destruction of ellipses

#pragma once
class BallClass
{
public:
	BallClass();							// constructor

	void Draw(HDC);							// answer WM_PAINT
	bool Move(HWND);						// move graphic, return false when graphic off screeen
	RECT GetInvalidateRect();				// calculate rectangle for PAINT

	// Structure to replace int with doubles in POINT and RECT
	struct dRECT
	{
		double left;
		double top;
		double right;
		double bottom;
	};

	struct dPOINT
	{
		double x;
		double y;
	};



private:
//	RECT rDim;								// dimensions, location and size of ellypse
	int r, g, b;							// color
	RECT rRectangle;						// return value for GetInvalidateRect()
//	POINT pSpeed;							// Horz and vert speed

	// Specials for granulated movement
	dRECT dDim;								// Dimensions with doubles
	dPOINT dSpeed;							// Motion, with doubles


	int GetRandomInt(int, int);				// return random integer

};

