// Project:	CIS023_S2020_LabGRd.cpp
// Author:	Miguel Antonio Logarta
// Date:	February 19, 2020
// Purpose:	Review creating an animation class definition
//			Review creating and moving multiple graphic objects based on timers
//			Code independent movement

#include "framework.h"
#include "CIS023_S2020_LabGRd.h"

#define MAX_LOADSTRING 100
#define WM_TIMER_CREATE 2001
#define WM_TIMER_MOVE 2002
#define MAX_BALL 10

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

BallClass* Ball[MAX_BALL];						// Array of pointers to objects

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS023S2020LABGRD, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LABGRD));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LABGRD));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LABGRD);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// reduce flicker by double-buffering 

		// get window client rectangle sizes
		RECT rClient;
		int cx, cy;
		GetClientRect(hWnd, &rClient);
		cx = rClient.right - rClient.left;
		cy = rClient.bottom - rClient.top;

		// create memory device
		HDC memdc = CreateCompatibleDC(hdc);			// create memory copy of dc
		unsigned bpp = GetDeviceCaps(hdc, BITSPIXEL);	// discover color depth
		HBITMAP hBmp = CreateBitmap(cx, cy, 1, bpp, NULL); // create bitmap for background
		HBITMAP hTmpBmp = (HBITMAP)SelectObject(memdc, (HGDIOBJ)hBmp); // fill memory dc

		// draw GDI background
		FillRect(memdc, &rClient, (HBRUSH)GetStockObject(WHITE_BRUSH));


		// draw here
		for (int i = 0; i < MAX_BALL; i++)
			if (Ball[i])								// If object exists
				Ball[i]->Draw(memdc);					// Call Draw

		//update the main DC
		BitBlt(hdc, 0, 0, cx, cy, memdc, 0, 0, SRCCOPY); // blt memory dc to window dc

		// clean up
		SelectObject(memdc, (HGDIOBJ)hTmpBmp);			// return to original dc
		DeleteDC(memdc);								// delete temp dc
		DeleteObject(hBmp);								// delete object

		// end
		EndPaint(hWnd, &ps);
		}
        break;
	case WM_TIMER:
		if (wParam == WM_TIMER_CREATE)
		{
			for (int i = 0; i < MAX_BALL; i++)			// Look through array
				if (!Ball[i])							// If NOT an object at this element
				{
					Ball[i] = new BallClass();			// Create new object
					break;								// Look no further
				}
		}
		else if (wParam == WM_TIMER_MOVE)
		{
			for (int i = 0 ; i < MAX_BALL; i++)			// Run through array
				if (Ball[i])							// If this element has an object
				{
					// Call Move, capture return code
					bool bContinue = Ball[i]->Move(hWnd);

					// Force WM_PAINT
					InvalidateRect(hWnd, 
						&Ball[i]->GetInvalidateRect(), 
						FALSE);							// FALSE = force background paint

					if (!bContinue)						// If Move says done with this object
					{
						delete Ball[i];					// Delete the object
						Ball[i] = nullptr;				// Make sure address is empty
					}
				}
		}
		break;
	case WM_CREATE:

		// Create timers
		SetTimer(hWnd, WM_TIMER_CREATE, 500, NULL);
		SetTimer(hWnd, WM_TIMER_MOVE, 100, NULL);

		// Null object array
		for (int i = 0; i < MAX_BALL; i++)
			Ball[i] = nullptr;

		break;
    case WM_DESTROY:
		// Delete objects
		for (int i = 0; i < MAX_BALL; i++)
			if (Ball[i])
				Ball[i] = nullptr;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
