// Project: CIS023_S2019_Lab10b Miguel Antonio Logarta.cpp : Defines the entry point for the application.
// Author:	Miguel Antonio Logarta
// Date:	January 29, 2020
// Purpose:	Add a method to a class definition
//			Pass parameters to an object
//			Receive a return value from an object
//

#include "framework.h"
#include "CIS023_S2019_Lab10b Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

HWND hWnd_Show;
HWND hWnd_Input_1;
HWND hWnd_Input_2;
HWND hWnd_Output;

MyClass* MyObject;								// Pointer to MyClass object

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_CIS023S2019LAB10BMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2019LAB10BMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2019LAB10BMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2019LAB10BMIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 300, 250, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:


				if (LOWORD(lParam) == (WORD)hWnd_Show)
				{
					TCHAR	szInput_1[TCHAR_SIZE];				// From edit 1
					TCHAR	szInput_2[TCHAR_SIZE];				// From edit 2
					TCHAR*	szReturn;							// Return from MyObject

					if (!MyObject)								// If object has not been created
						MyObject = new MyClass;					// Create the object

					// Get user input
					SendMessage(								// Send a message to a window
						hWnd_Input_1,							// 1st edit box
						WM_GETTEXT,								// Get text
						TCHAR_SIZE,								// How many chars
						LPARAM(szInput_1));						// Destination

					SendMessage(								// Send a message to a window
						hWnd_Input_2,							// 1st edit box
						WM_GETTEXT,								// Get text
						TCHAR_SIZE,								// How many chars
						LPARAM(szInput_2));						// Destination

					// Send user input to object for cancatination
					szReturn = MyObject->Manipulate(szInput_1, szInput_2);

					// Display return value
					SetWindowText(								// Send text to a control
						hWnd_Output,							// Output label
						szReturn);								// Source TCHAR
				}
				break;
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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:

		CreateWindow(
			TEXT("STATIC"),				// Label
			TEXT("Enter text:"),		// Text on Label
			WS_VISIBLE | WS_CHILD,		// Options
			10, 10, 75, 20,				// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window

		CreateWindow(
			TEXT("STATIC"),				// Label
			TEXT("Enter text:"),		// Text on Label
			WS_VISIBLE | WS_CHILD,		// Options
			10, 50, 75, 20,				// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window

		hWnd_Input_1 = CreateWindow(
			TEXT("EDIT"),				// Edit control for user input
			TEXT(""),					// Initialize blank
			WS_VISIBLE | WS_CHILD |		// Options
			WS_BORDER | ES_AUTOHSCROLL,
			110, 10, 100, 20,			// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window

		hWnd_Input_2 = CreateWindow(
			TEXT("EDIT"),				// Edit control for user input
			TEXT(""),					// Initialize blank
			WS_VISIBLE | WS_CHILD |		// Options
			WS_BORDER | ES_AUTOHSCROLL,
			110, 50, 100, 20,			// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window

		hWnd_Output = CreateWindow(
			TEXT("STATIC"),				// Edit control for user input
			TEXT(""),					// Initialize blank
			WS_VISIBLE | WS_CHILD |		// Options
			WS_BORDER,
			10, 150, 250, 20,			// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window

		// Button
		hWnd_Show = CreateWindow(
			TEXT("BUTTON"),				// Edit control for user input
			TEXT("SHOW"),					// Initialize blank
			WS_VISIBLE | WS_CHILD |		// Options
			BS_DEFPUSHBUTTON,
			90, 100, 90, 30,			// Location and size
			hWnd, NULL, NULL, NULL);	// Parent window




		break;
    case WM_DESTROY:

		if (MyObject)					// If object exists
			delete MyObject;			// Delete my object
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
