// Project:	CIS023_S2020_HW1-9 Miguel Antonio Logarta.cpp : Defines the entry point for the application.
// Author:	Miguel Antonio Logarta
// Date:	January 25, 2019
// Purpose:	Review reading data from a file
//			Review the use of arrays
//			Review the use of listboxes in Win32

#include "framework.h"
#include "CIS023_S2020_HW1-9 Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Load;									// Handle to button
HWND hWnd_ListBox1;								// Handle to listbox 1
HWND hWnd_ListBox2;								// Handle to listbox 2
HWND hWnd_ListBox3;								// Handle to listbox 3

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
    LoadStringW(hInstance, IDC_CIS023S2020HW19MIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020HW19MIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020HW19MIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);							// Change the background color to light gray COLOR_WINDOW+0
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020HW19MIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 570, 380, nullptr, nullptr, hInstance, nullptr);

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
					string strLine[3][100];					// 2D Array to hold file input
															// [type][name] <- what the array will hold
					TCHAR szOutput[255];					// Output to listbox
					int iTypeIndex = 0;						// Array index that holds the type
					int iNameIndex = 1;						// Array index that holds the names
					

					// Open the file
					fInput.open("CIS023_S2020_HW1-9_data.txt");

					if (fInput.is_open())
					{
						// Read a line from the file
						// Add the line to the array
						

						// Make the rows for the types. The names will go in these rows
						strLine[0][0] = "Male";
						strLine[1][0] = "Female";
						strLine[2][0] = "Last";

						// Read and process until it reaches the end of the file
						while (fInput.good())
						{
							getline(fInput, strLine[0][iNameIndex]);				// Get the male name
							getline(fInput, strLine[1][iNameIndex]);				// Get the female name
							getline(fInput, strLine[2][iNameIndex]);				// Get the last name
							iNameIndex += 1;										// Move on to the next column of names
						}
						fInput.close();												// Close the file

						iNameIndex = 1;												// Reset the array index for names

						// Loop through the array until there is an empty element
						while (strLine[0][iNameIndex] != "")
						{
							size_t pReturnValue;			// Return value for mbstowcs_s

							mbstowcs_s(						// Convert string to TCHAR
								&pReturnValue,				// Return value
								szOutput,					// Destination TCHAR
								255,						// Size of destination TCHAR
								strLine[0][iNameIndex++].c_str(),	// Source string
								255);						// Max chars to convert

							SendMessage(					// Send message to a window
								hWnd_ListBox1,				// Target window (the listbox)
								LB_ADDSTRING,				// Append string to list
								NULL,						// Not used
								LPARAM(szOutput));			// TCHAR
						}

						iNameIndex = 1;

						while (strLine[1][iNameIndex] != "")
						{
							size_t pReturnValue;			// Return value for mbstowcs_s

							mbstowcs_s(						// Convert string to TCHAR
								&pReturnValue,				// Return value
								szOutput,					// Destination TCHAR
								255,						// Size of destination TCHAR
								strLine[1][iNameIndex++].c_str(),	// Source string
								255);						// Max chars to convert

							SendMessage(					// Send message to a window
								hWnd_ListBox2,				// Target window (the listbox)
								LB_ADDSTRING,				// Append string to list
								NULL,						// Not used
								LPARAM(szOutput));			// TCHAR
						}

						iNameIndex = 1;

						while (strLine[2][iNameIndex] != "")
						{
							size_t pReturnValue;			// Return value for mbstowcs_s

							mbstowcs_s(						// Convert string to TCHAR
								&pReturnValue,				// Return value
								szOutput,					// Destination TCHAR
								255,						// Size of destination TCHAR
								strLine[2][iNameIndex++].c_str(),	// Source string
								255);						// Max chars to convert

							SendMessage(					// Send message to a window
								hWnd_ListBox3,				// Target window (the listbox)
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
			TEXT("BUTTON"),							// Type
			TEXT("LOAD"),							// Text on button
			WS_VISIBLE | WS_CHILD |					// Options
			BS_DEFPUSHBUTTON,
			235, 250, 90, 30,						// Location and size
			hWnd, NULL, NULL, NULL);				// Parent

		// Static text for Male (label)
		CreateWindow(								// Create a desktop object
			TEXT("STATIC"),							// Type label, or "STATIC"
			TEXT("Male"),							// Text on the control
			WS_VISIBLE | WS_CHILD,					// Options
			20, 10, 150, 30,						// x, y location and x, y size
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

		// Static text for Female (label)
		CreateWindow(								// Create a desktop object
			TEXT("STATIC"),							// Type label, or "STATIC"
			TEXT("Female"),							// Text on the control
			WS_VISIBLE | WS_CHILD,					// Options
			200, 10, 150, 30,						// x, y location and x, y size
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

		// Static text for Last Names (label)
		CreateWindow(								// Create a desktop object
			TEXT("STATIC"),							// Type label, or "STATIC"
			TEXT("Last"),							// Text on the control
			WS_VISIBLE | WS_CHILD,					// Options
			380, 10, 150, 30,						// x, y location and x, y size
			hWnd,									// Parent window
			NULL, NULL, NULL);						// Default

		// Create listbox 1
		hWnd_ListBox1 = CreateWindow(
			TEXT("LISTBOX"),						// Type
			TEXT(""),								// Listboxes have no text value
			WS_VISIBLE | WS_CHILD |					// Options
			WS_VSCROLL | WS_BORDER,
			20, 50, 150, 200,						// Location and size
			hWnd, NULL, NULL, NULL);				// Parent

		// Create listbox 2
		hWnd_ListBox2 = CreateWindow(
			TEXT("LISTBOX"),						// Type
			TEXT(""),								// Listboxes have no text value
			WS_VISIBLE | WS_CHILD |					// Options
			WS_VSCROLL | WS_BORDER,
			200, 50, 150, 200,						// Location and size
			hWnd, NULL, NULL, NULL);				// Parent

		// Create listbox 3
		hWnd_ListBox3 = CreateWindow(
			TEXT("LISTBOX"),						// Type
			TEXT(""),								// Listboxes have no text value
			WS_VISIBLE | WS_CHILD |					// Options
			WS_VSCROLL | WS_BORDER,
			380, 50, 150, 200,						// Location and size
			hWnd, NULL, NULL, NULL);				// Parent
		
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
