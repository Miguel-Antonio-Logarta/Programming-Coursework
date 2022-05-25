// Project: AnimationClass.h
// Author:	Miguel Antonio Logarta
// Date:	February 10, 2020
// Purpose: Header file for AnimationClass.cpp

#pragma once
class AnimationClass
{
public:
	void Initialize(int);								// Set default values
	void Draw(HDC, HINSTANCE);						// Answer the WM_PAINT message
	void NextFrame(HWND);							// Advance to the next frame in the animation

private:

	int iResourceID;								// ID number of graphic resource
	POINT pLocation;								// x, y location of graphic
	POINT pSize;									// x, y size of graphic
	int iCurrentFrame;								// Frame number (1 through 10)
};

