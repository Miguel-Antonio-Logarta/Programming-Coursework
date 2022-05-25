// Module:	CIS023_S2020_LabIb Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	January 15, 2019
// Purpose: Review creation of a windows GIU (Win32) project in Visual C++
//			Learn how to add buttons and capture the button click event
//			Learn how to add edit controls and capture the text changed event
//			Learn how to add static controls and set the text at run-time
//			Learn how to create a message box

#include "framework.h"
#include "CIS023_S2020_LabIb Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_PushButton;							// Handle to controls
HWND hWnd_Input;								// Edit box
HWND hWnd_Output;								// Output label

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
    LoadStringW(hInstance, IDC_CIS023S2020LABIBMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LABIBMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LABIBMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LABIBMIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 650, 250, nullptr, nullptr, hInstance, nullptr);

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
			// Capture input text
			TCHAR szUserInput[255];						// User input from edit box

			if (HIWORD(wParam) == EN_CHANGE)			// Did text change
				if (LOWORD(lParam) == (WORD)hWnd_Input) // Input edit box?
				{
					GetWindowText(						// Get text from edit box
						hWnd_Input,						// Handle to edit box
						szUserInput,					// Destination TCHAR
						255);							// Max chars to get


					// Echo text to the output label
					SetWindowText(						// Set the text of the window
						hWnd_Output,					// Window (control) to set
						szUserInput);					// Text to set
				}



            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case BN_CLICKED:
				if (LOWORD(lParam) == (WORD)hWnd_PushButton)
				{
					// Display a message box
					MessageBox(
						NULL,							// Parent window
						TEXT("PUSH button clicked"),	// Text to display
						TEXT("BN_CLICKED"),				// Heading
						MB_RETRYCANCEL);				// Behavior
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

		// Static text (label)
		CreateWindow(								// Create a desktop object
			TEXT("STATIC"),							// Type label, or "STATIC"
			TEXT("Controls!"),						// Text on the control
			WS_VISIBLE | WS_CHILD,					// Options
			10, 10, 250, 30,						// x, y location and x, y size
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

		// Create a button
		hWnd_PushButton = CreateWindow(
			TEXT("BUTTON"),							// Push button
			TEXT("PUSH"),							// Text on button
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			60, 50, 90, 30,							// Location and size
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

		// Create edit control for user input
		hWnd_Input = CreateWindow(
			TEXT("EDIT"),							// User input
			TEXT(""),								// No default text
			WS_VISIBLE | WS_CHILD |					// Options
			WS_BORDER | ES_AUTOHSCROLL,				// Border for visibility, scroll
			20, 120, 100, 20,						// Location and size
			hWnd,
			NULL, NULL, NULL);

		// Create output line
		hWnd_Output = CreateWindow(					// Label
			TEXT("STATIC"),							// Label
			TEXT("blah, blah, blah, blah, blah, blah, blah, blah"),			
			WS_VISIBLE | WS_CHILD,					// Options
			159, 120, 1000, 30,
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

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
