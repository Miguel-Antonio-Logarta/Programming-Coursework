// Project: CIS023_S2020_LabGRc Miguel Antonio Logarta.cpp : Defines the entry point for the application.
// Author:	Miguel Antonio Logarta
// Date:	February 12, 2020
// Purpose:	Create an array of pointers to objects
//			Move multiple graphic objects based on timers

#include "framework.h"
#include "CIS023_S2020_LabGRc Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100
#define MAX_BALL 10								// Size of array
#define WM_TIMER_CREATE 2001					// Timer to create objects
#define WM_TIMER_MOVE 2002						// Timer to move objects

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
    LoadStringW(hInstance, IDC_CIS023S2020LABGRCMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LABGRCMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LABGRCMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LABGRCMIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 200, 200, nullptr, nullptr, hInstance, nullptr);

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
            
			// Get window client size
			RECT rClient;
			int cx, cy;
			GetClientRect(hWnd, &rClient);
			cx = rClient.right - rClient.left;					// Get width and height 
			cy = rClient.bottom - rClient.top;

			// Create memory device 
			HDC memdc = CreateCompatibleDC(hdc);				// Create memory copy of dc
			unsigned bpp = GetDeviceCaps(						// Discover color depth
				hdc, BITSPIXEL);
			HBITMAP hBmp = CreateBitmap(						// Create bitmap for background
				cx, cy, 1, bpp, NULL);
			HBITMAP hTmpBmp =									// Fill memory dc
				(HBITMAP)SelectObject(memdc, (HGDIOBJ)hBmp);

			// Draw GDI background
			FillRect(memdc, &rClient, (HBRUSH)GetStockObject(WHITE_BRUSH));
			
			// Draw GDI graphic
			for (int i = 0; i < MAX_BALL; i++)					// Look through array
				if (Ball[i])									// If this object exists
					Ball[i]->Draw(memdc);							// Draw the object

			// Draw the main DC
			BitBlt(hdc, 0, 0, cx, cy, memdc, 0, 0, SRCCOPY);
            EndPaint(hWnd, &ps);

			// Clean up
			SelectObject(memdc, (HGDIOBJ)hTmpBmp);
			DeleteDC(memdc);
			DeleteObject(hBmp);
        }
        break;
	case WM_TIMER:
	{
		if (wParam == WM_TIMER_CREATE)
		{
			for (int i = 0; i < MAX_BALL; i++)					// Look through array
			{
				if (!Ball[i])									// If this object has not been created yet
				{
					Ball[i] = new BallClass((i + 1)* 10);		// Create object
					break;										// Jump out of for loop
				}
			}
		}
		if (wParam == WM_TIMER_MOVE)
		{
			for (int i = 0; i < MAX_BALL; i++)					// Look through array
			{
				if (Ball[i])									// If object exists
					if (Ball[i]->Move(hWnd))					// Move the object
					{
						InvalidateRect(
							hWnd,								// Force paint message
							&Ball[i]->GetInvalidRect(),
							FALSE);
					}
					else
					{
						InvalidateRect(hWnd,					// Force paint message
							&Ball[i]->
							GetInvalidRect(),
							FALSE);
						delete Ball[i];							// Delete object
						Ball[i] = nullptr;						// Make sure address is empty
					}
			}
		}
	}
		break;
	case WM_CREATE:
		// Ball[0] = new BallClass(0);

		// Create timers
		SetTimer(hWnd, WM_TIMER_CREATE, 500, NULL);
		SetTimer(hWnd, WM_TIMER_MOVE, 100, NULL);

		break;
    case WM_DESTROY:
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
