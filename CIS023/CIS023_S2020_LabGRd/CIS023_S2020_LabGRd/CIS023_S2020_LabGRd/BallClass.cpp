// Module:	BallClass.h
// Author:	Miguel Antonio Logarta
// Date:	February 19, 2020
// Purpose:	Implementation file for BallClass
//			Creation, movement, destruction of ellipses

#include "framework.h"
#include "CIS023_S2020_LabGRd.h"

BallClass::BallClass()
{
	// start location and size
	dDim.left = 0.0;								// start at upper left corner
	dDim.top = 0.0;
	double dSize = GetRandomInt(10, 25);			// balls are round
	dDim.right = dSize;								// set ball size
	dDim.bottom = dSize;

	// pick a color
	r = GetRandomInt(0, 255);						// red
	g = GetRandomInt(0, 255);						// green
	b = GetRandomInt(0, 255);						// blue

	// Set speeds
	dSpeed.x = GetRandomInt(1, 15);					// Set horizontal speed
	dSpeed.y = GetRandomInt(1, 15);					// Set vertical speed

}

void BallClass::Draw(HDC hdc)
{
	// create brushes
	HBRUSH brush, oldBrush;
	brush = CreateSolidBrush(RGB(r, g, b));
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	// Convert double dimensions to int for draw command
	RECT rDim;
	rDim.left = trunc(dDim.left);
	rDim.right = trunc(dDim.right);
	rDim.top = trunc(dDim.top);
	rDim.bottom = trunc(dDim.bottom);

	// draw spheare
	Ellipse(hdc, rDim.left, rDim.top, rDim.right, rDim.bottom);

	// release brushes
	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

}

bool BallClass::Move(HWND hWnd)
{
	// Get window rectangle
	RECT rClient;							// Get size of window
	GetClientRect(hWnd, &rClient);			

	// Check for stopped balls
	if (dDim.bottom > rClient.bottom - 5.0 &&
		dSpeed.y > -1.0 &&
		dSpeed.y < 1.0)
		return false;						// Delete this object

	// Check for collision
	if (dDim.left <= 0.0)					// Hit left wall?
		dSpeed.x = abs(dSpeed.x);			
	if (dDim.top <= 0.0)					// Hit the top?
		dSpeed.y = abs(dSpeed.y);
	if (dDim.right >= rClient.right)		// Hit the right wall?
		dSpeed.x = abs(dSpeed.x) * -1;		
	if (dDim.bottom >= rClient.bottom)		// Did we hit the bottom
		dSpeed.y = abs(dSpeed.y) * -1;

	// Reduce speed due to gravity
	if (dSpeed.y < 0.0)						// If moving up
		dSpeed.y *= 0.90;					// Reduce the speed by 10%
	if (dSpeed.y > 0.0)						// If moving down
		dSpeed.y *= 1.05;					// 5% increase

	if (dSpeed.y > -0.5 && dSpeed.y < 0.5)	// If moving really slow
		dSpeed.y = 1.0;						// Start to fall

	// Reduce horizontal speed due to gravity
	dSpeed.x *= 0.99;						// 1% horizontal speed reduction

	// Move
	dDim.left += dSpeed.x;					// Move horizontally
	dDim.right += dSpeed.x;
	dDim.top += dSpeed.y;					// Move vertically
	dDim.bottom += dSpeed.y;

	return TRUE;
}

RECT BallClass::GetInvalidateRect()
{
	// rRectangle = rDim;						// default return value

	// Copy double dimension to int rect
	rRectangle.left = trunc(dDim.left);
	rRectangle.right = trunc(dDim.right);
	rRectangle.top = trunc(dDim.top);
	rRectangle.bottom = trunc(dDim.bottom);

	// Make adjustments for movement
	if (dSpeed.x < 0.0)						// If moving left
		rRectangle.right -= (dSpeed.x - 1.0);
	if (dSpeed.x > 0.0)						// If moving right
		rRectangle.left -= dSpeed.x;

	if (dSpeed.y < 0.0)						// If moving up 
		rRectangle.bottom -= (dSpeed.y - 1.0);
	if (dSpeed.y > 0.0)
		rRectangle.top -= dSpeed.y;

	return rRectangle;
}


int BallClass::GetRandomInt(int iMin, int iMax)
{
	random_device rd;								// non-deterministic generator
	mt19937 gen(rd());								// to seed mersenne twister.
	uniform_int_distribution<> dist(iMin, iMax);	// distribute results inside center rect

	return dist(gen);								// return random # between iMin and iMax

}
