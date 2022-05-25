// Module:	CIS023_S2020_Lab12a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	March 2, 2020
// Purpose: Work with an abstract class
//			Review reading data from a text file
//			Perform operations on an abstract class
//			Learn how to convert algorithms into virtual functions
//			Review listbox interaction

#include "framework.h"
#include "CIS023_S2020_Lab12a Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100
#define SIZE_ARRAY 9999

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_ListBox;								// handle to list box
HWND hWnd_Largest;								// buttons
HWND hWnd_Search;								//
HWND hWnd_Largest_Out;							// output message
HWND hWnd_Input;								// user input
HWND hWnd_Found;								// found message


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool LoadFile();								// Load text file into listbox
int NumberList[SIZE_ARRAY];						// Array to hold file contents

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
    LoadStringW(hInstance, IDC_CIS023S2020LAB12AMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LAB12AMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LAB12AMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LAB12AMIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 400, 400, nullptr, nullptr, hInstance, nullptr);

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
			case BN_CLICKED:								// Capture buttons
				if (LOWORD(lParam) == (WORD)hWnd_Largest)	// Largest button
				{
					TCHAR szBuffer[100];					// For output
					int iLargest = 0;						// Largset number found in array
					int iPosition;							// Where largest was found

					iPosition =								// Capture position of largest item in array
						Functions::Largest(					// Virtual function
							NumberList,						// Array for search
							SIZE_ARRAY,						// Size of array
							iLargest);						// Largest value found by function

					_itot_s(								// Convert int to TCHAR
						iLargest,							// Input int
						szBuffer,							// TCHAR
						100,								// Size of TCHAR
						10);								// Radix

					SetWindowText(							// Display
						hWnd_Largest_Out,					// Handle to label
						szBuffer);							// Text to display

					ShowWindow(hWnd_Largest_Out, TRUE);		// Show value

					SendMessage(							// Select item in listbox
						hWnd_ListBox,						// Handle to listbox
						LB_SETCURSEL,						// Set selection
						iPosition,							// Item in listbox to select
						NULL);								// lparam not used
				}
				if (LOWORD(lParam) == (WORD)hWnd_Search)	// Search button
				{
					TCHAR szBuffer[100];					// Output TCHAR
					int iSearchValue = 0;					// User input
					int iPosition = -1;						// Where in array the number was found

					GetWindowText(							// Get User Input
						hWnd_Input,							// Input edit box
						szBuffer,							// Destination TCHAR
						100);								// Size of TCHAR

					iSearchValue =							// Convert user input to number
						_tstoi(								// Convert TCHAR to int
							szBuffer);						// Source TCHAR

					iPosition =								// Find out where value is located
						Functions::Search(					// Call virtual function
							NumberList,						// Array
							SIZE_ARRAY,						// Size of array
							iSearchValue);					// Value to look for

					SendMessage(							// Show position
						hWnd_ListBox,						// Handle to listbox
						LB_SETCURSEL,						// Set selection
						iPosition,							// Which item to select (-1 turns off)
						NULL);								// lparam not used

					if (iPosition == -1)					// If value is not found
					{
						SendMessage(						// 
							hWnd_Found,						// Output message label
							WM_SETTEXT,						// Set its text
							NULL,							// wparam not used
							(LPARAM)TEXT("Not Found"));		// Text to display
					}
					else									// If the value is found
					{
						SendMessage(						// 
							hWnd_Found,						// Output message label
							WM_SETTEXT,						// Set its text
							NULL,							// wparam not used
							(LPARAM)TEXT("Found"));			// Text to display
					}

					ShowWindow(hWnd_Found, TRUE);			// Show message
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
	{
		// create list box
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),								// type of object
			TEXT(""),										// starts blank (filled later)
			WS_VISIBLE | WS_CHILD |							// attributes
			WS_VSCROLL | WS_BORDER,							// NOT SORTED!
			20, 50, 75, 175,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		// buttons
		hWnd_Largest = CreateWindow(TEXT("BUTTON"),
			TEXT("Largest"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 50, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Search = CreateWindow(TEXT("BUTTON"),
			TEXT("Search"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 100, 90, 30, hWnd, NULL, NULL, NULL);

		// labels
		CreateWindow(TEXT("STATIC"),
			TEXT("Numbers"),
			WS_VISIBLE | WS_CHILD,
			20, 20, 75, 30, hWnd, NULL, NULL, NULL);

		// output
		hWnd_Largest_Out = CreateWindow(
			TEXT("STATIC"),
			TEXT("(largest)"),
			!WS_VISIBLE | WS_CHILD,							// not visible
			250, 55, 60, 30, hWnd, NULL, NULL, NULL);

		// input
		hWnd_Input = CreateWindow(
			TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER, // number only
			250, 105, 60, 20, hWnd, NULL, NULL, NULL);

		// result
		hWnd_Found = CreateWindow(
			TEXT("STATIC"),
			TEXT("Not Found"),
			!WS_VISIBLE | WS_CHILD,							// not visible
			250, 150, 100, 20, hWnd, NULL, NULL, NULL);

		if (!LoadFile())
		{
			ShowWindow(hWnd_Found, TRUE);					// Show error messages
		}


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

bool LoadFile()
{
	ifstream inFile;							// File handle

	// Open the file
	inFile.open("CIS023_S2020_Lab12a_data.txt");

	if (inFile.is_open())						// Did the file open?
	{
		string strFileIn;						// Holds input from file

		for (int i = 0; i < SIZE_ARRAY; i++)	// Read entire file
		{
			getline(inFile, strFileIn, '\n');	// Read a line from the file
			NumberList[i] =						// Store a line in the array
				atoi(strFileIn.c_str());		// Convert to integer
		}

		inFile.close();							// Close the file
	}
	else
		return false;							// File not found

	TCHAR szBuffer[100];						// Output to listbox

	for (int i = 0; i < SIZE_ARRAY; i++)		// Roll through array
	{
		_itot_s(								// Convert int to TCHAR
			NumberList[i],						// Source integer
			szBuffer,							// Destinatino TCHAR
			100,								// Size of destination TCHAR
			10);								// Radix

		SendMessage(							// Send a message
			hWnd_ListBox,						// To the lsitbox
			LB_ADDSTRING,						// Add a string
			NULL,								// wmparam not used
			(LPARAM)szBuffer);
	}

	return true;								// File loaded okay
}