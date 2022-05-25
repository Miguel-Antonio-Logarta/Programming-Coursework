// Project:	CIS023_S2020_LabGRa Miguel Antonio Logarta.cpp : Defines the entry point for the application.
// Author:	Miguel Antonio Logarta
// Date:	February 5, 2020
// Purpose:	Load graphic files into the project resources
//			Load graphic resources into the program
//			Display graphics
//			Understand the WM_PAINT message
			
#include "framework.h"
#include "CIS023_S2020_LabGRa Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Bitmap handles
HBITMAP hBitmap1 = nullptr;						// 1st graphic resource (mountain)
HBITMAP hBitmap2 = nullptr;						// 2nd graphic resourec (sun)

int vert = 0;									// Location of sun
int horz = 0;									// Location of sun


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
    LoadStringW(hInstance, IDC_CIS023S2020LABGRAMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LABGRAMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LABGRAMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LABGRAMIGUELANTONIOLOGARTA);
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

			HDC hmemdc = nullptr;							// Copy of hdc
			BITMAP bitmap;									// Resource graphic

			// if (hBitmap1 == nullptr)						// Load resource (if not already)
			{
				hBitmap1 =									// Returns handle to bitmap
					(HBITMAP)LoadImage(						// Load image from resource
						hInst,								// Handle to code section
						MAKEINTRESOURCE(IDB_BITMAP1),		// ID # of the resource
						IMAGE_BITMAP,						// Type of resource
						0,									// X coordinate
						0,									// y coordinate
						NULL);								// Load instructions
			}

			hmemdc = CreateCompatibleDC(hdc);				// Make a copy of the dc
			SelectObject(hmemdc, hBitmap1);					// Load bitmap into memdc
			GetObject(hBitmap1, sizeof(BITMAP), &bitmap);	// Select object

			// Discover size of main window
			RECT rClient;									// x, y coordinate of main win
			GetClientRect(hWnd, &rClient);					// Get coordinates

			// Stretch background bitmap into window
			StretchBlt(										// Display bitmap, adjust size
				hdc,										// Destination device context
				0,											// x of the destination
				0,											// y of destination
				rClient.right,								// Width of bitmap
				rClient.bottom,								// Height of destination
				hmemdc,										// Source
				0,											// x of source
				0,											// y of source
				bitmap.bmWidth,								// Width of source
				bitmap.bmHeight,							// Height of source
				SRCCOPY);									// Copy bitmap to window

			// Load and display the sun on the background
			SelectObject(hmemdc, hBitmap2);					// Load bitmap into memdc
			GetObject(hBitmap2, sizeof(BITMAP), &bitmap);	// Select object

			// if (hBitmap2 == nullptr)						// Load resource (if not already)
			{
				hBitmap2 =									// Returns handle to bitmap
					(HBITMAP)LoadImage(						// Load image from resource
						hInst,								// Handle to code section
						MAKEINTRESOURCE(IDB_BITMAP2),		// ID # of the resource
						IMAGE_BITMAP,						// Type of resource
						0,									// X coordinate
						0,									// y coordinate
						NULL);								// Load instructions
			}

			SelectObject(hmemdc, hBitmap2);					// Load bitmap into memdc
			GetObject(hBitmap2, sizeof(BITMAP), &bitmap);	// Select object

			// Calc position of sun
			/*int vert = rClient.bottom / 3.75;
			int horz = rClient.right - bitmap.bmWidth;*/

			// Load second bitmap into first
			BitBlt(											// Display
				hdc,										// Destination dc
				//0,											// x of destination
				//0,											// y of destination
				horz,										// x of destination
				vert,										// y of destination
				bitmap.bmWidth,								// Width of destination
				bitmap.bmHeight,							// Height of destination
				hmemdc,										// Source
				0,											// x of source
				0,											// y of source
				SRCCOPY);									// Copy bitmap to window

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
	{
		horz++;												// Move to the right

		//RECT rSize = { horz, vert, 50, 50 };

		InvalidateRect(										// Forces a paint message
			hWnd,											// Main window
			//&rSize,											// Entire window
			//TRUE);											// True = whole window
			NULL,											// Entire window
			FALSE);											// Don't erase background

	}
		break;
	case WM_CREATE:
	{
		SetTimer(											// Create and start a time
			hWnd,											// Attached to this window
			WM_TIMER,										// Tick event
			16,												// Milliseconds between ticks
			NULL);											// Normal use
	}
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
