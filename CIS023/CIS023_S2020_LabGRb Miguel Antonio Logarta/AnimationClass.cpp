// Project: AnimationClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	February 10, 2020
// Purpose: Resource file for AnimationClass
//			Resource animation

#include "framework.h"
#include "CIS023_S2020_LabGRb Miguel Antonio Logarta.h"

void AnimationClass::Initialize(int iItem)
{
	iResourceID = IDB_BITMAP1;			// 1st bitmap in sequence

	if (iItem == 0)
	{
		pLocation.x = -214;				// Starting location
		pLocation.y = 0;
	}
	else
	{
		pLocation.x = -628;
		pLocation.y = -72;
	}

	pSize.x = 214;						// Starting size
	pSize.y = 359;


}

void AnimationClass::Draw(HDC hdc, HINSTANCE hInst)
{
	// Load the bitmap from the resource
	HBITMAP bmpRunner = LoadBitmap(hInst, MAKEINTRESOURCE(iResourceID));

	// Create memory dc
	HDC memdc = CreateCompatibleDC(hdc);

	// Select the new bitmap
	HDC oldbmp = (HDC)SelectObject(memdc, bmpRunner);

	// Copy to dc
	/*BitBlt(hdc, pLocation.x, pLocation.y, pSize.x, pSize.y, memdc, 0, 0, SRCCOPY);*/

	// Stretch the bitmap to the device context
	StretchBlt(hdc, 
		pLocation.x, pLocation.y,				// Location
		pSize.x, pSize.y,						// Size
		memdc,									// Soure
		0, 0, 214, 359,							// Size of original bitmap
		SRCCOPY);								// Copy, no special effects

	// Restore the old bitmap
	SelectObject(memdc, oldbmp);
	
	// Clean up
	DeleteDC(memdc);
	DeleteObject(bmpRunner);

}

void AnimationClass::NextFrame(HWND hWnd)
{
	// Advance frame
	iResourceID++;						// Advance to the next frame
	if (iResourceID > IDB_BITMAP10)		// If past the last frame
		iResourceID = IDB_BITMAP1;		// Reset to the 1st frame

	// Move character
	pLocation.x += 6;
	pLocation.y += 2;

	// Resize character
	pSize.x++;
	pSize.y++;
}
