// Project: BallClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	February 12, 2020
// Purpose:	Implementation file for BallClass. GDI graphic control

#include "framework.h"
#include "CIS023_S2020_LabGRc Miguel Antonio Logarta.h"

BallClass::BallClass(int Y)
{
	// Set size and location
	rDim.left = 0;									// Start at left of the window
	rDim.top = Y;									// Top as specified in the main module
	rDim.right = 10;								// Sphere is 10 x 10
	rDim.bottom = Y + 10;

	// Pick a color
	r = GetRandomInt(0, 255);						// Red
	g = GetRandomInt(0, 255);						// Green
	b = GetRandomInt(0, 255);						// Blue
}

void BallClass::Draw(HDC hdc)
{
	// Create brushes
	HBRUSH brush, oldBrush;							// Graphic brushes
	brush = CreateSolidBrush(RGB(r, g, b));			// Create a brush of a certain color
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	// Draw spheres
	Ellipse(
		hdc,										// Current screen
		rDim.left,									// Dimensions
		rDim.top,
		rDim.right,
		rDim.bottom);

	// Release brushes
	SelectObject(hdc, oldBrush);					// Put the old brush back
	DeleteObject(brush);							// Delete the brush used in the this method
}

bool BallClass::Move(HWND hWnd)
{
	// Calculate new position
	rDim.left++;
	rDim.right++;

	// Get client window dimensions
	RECT rClient;
	GetClientRect(hWnd, &rClient);

	// Check if graphic hit right side of window
	if (rDim.right > rClient.right)
		return false;

	return true;									// Keep moving
}

RECT BallClass::GetInvalidRect()
{
	rReturn = rDim;									// Initialize return value

	rReturn.left -= 2;								// Moves right, so stretch rect to the left

	return rReturn;									// Return invalidate rect
}

int BallClass::GetRandomInt(int iMin, int iMax)
{
	random_device rd;								// Non-deterministic generator
	mt19937 gen(rd());								// See mersenne twister
	uniform_int_distribution<> dist(iMin, iMax);	// Set limits

	return dist(gen);								// Return random number
}
