// Module:	CIS023_S2020_Lab1-9 Miguel Antonio Logarta.cpp : Defines the entry point for the application.
// Author:	Miguel Antonio Logarta
// Date:	January 22, 2020
//Purpose:	Review the steps necessary to interact with a file.
//			Add controls to a window.
//			Review interaction with buttonsand edit controls.
//			Review the declarationand interaction with an array.
//			Learn the steps necessary to create a working listbox.
//			Add text items to a listbox.

#include "framework.h"
#include "CIS023_S2020_Lab1-9 Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Load;									// Handle to button
HWND hWnd_ListBox;								// Handle to listbox

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
    LoadStringW(hInstance, IDC_CIS023S2020LAB19MIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LAB19MIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LAB19MIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LAB19MIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 200, 300, nullptr, nullptr, hInstance, nullptr);

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
				if (LOWORD(lParam) == (WORD)hWnd_Load)
				{
					ifstream fInput;						// File handle
					string strLine[100];					// Array to hold file input
					TCHAR szOutput[255];					// Output to listbox
					int iIndex = 0;							// Array index

					// Open the file
					fInput.open("CIS023_S2020_Lab1-9_data.txt");

					if (fInput.is_open())					// Did the file open
					{
						// Read a line from the file
						getline(fInput, strLine[iIndex++]);

						// Read and process until end of file
						while (fInput.good())
						{
							getline(fInput, strLine[iIndex++]);
						}
						fInput.close();						// Close the file

						iIndex = 0;							// Reset the array index

						// Loop through string array until an empty element
						while (strLine[iIndex] != "")
						{
							
							size_t pReturnValue;			// Return value for mbstowcs_s

							mbstowcs_s(						// Convert string to TCHAR
								&pReturnValue,				// Return value
								szOutput,					// Destination TCHAR
								255,						// Size of destination TCHAR
								strLine[iIndex++].c_str(),	// Source string
								255);						// Max chars to convert

							SendMessage(					// Send message to a window
								hWnd_ListBox,				// Target window (the listbox)
								LB_ADDSTRING,				// Append string to list
								NULL,						// Not used
								LPARAM(szOutput));			// TCHAR
						}
					}
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

		// Create button
		hWnd_Load = CreateWindow(
			TEXT("BUTTON"),						// Type
			TEXT("LOAD"),						// Text on button
			WS_VISIBLE | WS_CHILD |				// Options
			BS_DEFPUSHBUTTON,
			50, 180, 90, 30,					// Location and size
			hWnd, NULL, NULL, NULL);			// Parent

		// Create listbox
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),					// Type
			TEXT(""),							// Listboxes have no text value
			WS_VISIBLE | WS_CHILD |				// Options
			WS_VSCROLL | WS_BORDER,
			20, 20, 150, 140,					// Location and size
			hWnd, NULL, NULL, NULL);			// Parent

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
