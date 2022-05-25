// Module:	CIS023_S2020_Lab12b Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	March 4, 2020
// Purpose:	Learn the syntax of template functions
//			Implement template function in a program

#include "framework.h"
#include "CIS023_S2020_Lab12b Miguel Antonio Logarta.h"
#include "Useful.h"								// Template classes

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// handles to window controls
HWND hWndIntIn;
HWND hWndIntoTCHAR;
HWND hWndDouble;
HWND hWndDoubletoTCHAR;
HWND hWndTCHARIn;
HWND hWndStringtoTCHAR;
HWND hWndConvertInttoTCHAR;
HWND hWndConvertDoubletoTCHAR;
HWND hWndConvertStringtoTCHAR;

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
    LoadStringW(hInstance, IDC_CIS023S2020LAB12BMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LAB12BMIGUELANTONIOLOGARTA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LAB12BMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LAB12BMIGUELANTONIOLOGARTA);
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
      CW_USEDEFAULT, 0, 300, 400, nullptr, nullptr, hInstance, nullptr);

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
				// TCHAR to int and back to TCHAR
				if (LOWORD(lParam) == (WORD)hWndConvertInttoTCHAR)
				{
					TCHAR szInput[TCHAR_SIZE];								// Input buffer
					int iConvert;											// Converted from input buffer
					TCHAR szOutput[TCHAR_SIZE];								// Output buffer

					// Get user input from edit control
					GetWindowText(											// Get Text from edit control
						hWndIntIn,											// Handle to control
						szInput,											// Destination TCHAR
						TCHAR_SIZE);										// Size of destination TCHAR

					// Convert user input TCHAR to int
					iConvert = TCHARtoInt(szInput);

					// Convert the converted int back to a TCHAR
					InttoTCHAR(iConvert, szOutput);

					// Set output static control
					SetWindowText(											// Output text to label
						hWndIntoTCHAR,										// Handle to label
						szOutput);											// Output buffer
				}

				// TCHAR to double and back to TCHAR
				if (LOWORD(lParam) == (WORD)hWndConvertDoubletoTCHAR)
				{
					TCHAR szInput[TCHAR_SIZE];								// Input buffer
					double dConvert;										// Converted from input buffer
					TCHAR szOutput[TCHAR_SIZE];								// Output buffer

					// Get user input from edit control
					GetWindowText(											// Get Text from edit control
						hWndDouble,											// Handle to control
						szInput,											// Destination TCHAR
						TCHAR_SIZE);										// Size of destination TCHAR

					// Convert the input TCHAR to a double
					dConvert = TCHARtoDouble(szInput);

					// Convert the converted double to a TCHAR
					DoubleToTCHAR(dConvert, szOutput, 2);



					// Set output static control
					SetWindowText(											// Output text to label
						hWndDoubletoTCHAR,									// Handle to label
						szOutput);											// Output buffer
				}
				
				// TCHAR to string and back to TCHAR
				if (LOWORD(lParam) == (WORD)hWndConvertStringtoTCHAR)
				{

					TCHAR szInput[TCHAR_SIZE];								// Input buffer
					string strConvert;										// Converted from input buffer
					TCHAR szOutput[TCHAR_SIZE];								// Output buffer

					// Get user input from edit control
					GetWindowText(											// Get Text from edit control
						hWndTCHARIn,											// Handle to control
						szInput,											// Destination TCHAR
						TCHAR_SIZE);										// Size of destination TCHAR

					// Convert input TCHAR to string
					TCHARtoString(szInput, &strConvert);
					// Convert the converted string to a TCHAR
					StringtoTCHAR(&strConvert, szOutput);

					// Set output static control
					SetWindowText(											// Output text to label
						hWndStringtoTCHAR,									// Handle to label
						szOutput);											// Output buffer
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
			// buttons
			hWndConvertInttoTCHAR = CreateWindow(TEXT("BUTTON"),
				TEXT("Integer to TCHAR"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 10, 200, 30, hWnd, NULL, NULL, NULL);

			hWndConvertDoubletoTCHAR = CreateWindow(TEXT("BUTTON"),
				TEXT("Double to TCHAR"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 100, 200, 30, hWnd, NULL, NULL, NULL);

			hWndConvertStringtoTCHAR = CreateWindow(TEXT("BUTTON"),
				TEXT("String to TCHAR"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 190, 200, 30, hWnd, NULL, NULL, NULL);


			// edit controls (user input)
			hWndIntIn = CreateWindow(TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER, // number only
				10, 50, 60, 20, hWnd, NULL, NULL, NULL);

			hWndDouble = CreateWindow(TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
				10, 140, 100, 20, hWnd, NULL, NULL, NULL);

			hWndTCHARIn = CreateWindow(TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
				10, 230, 100, 20, hWnd, NULL, NULL, NULL);


			// static controls (output labels)
			hWndIntoTCHAR = CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				130, 50, 100, 20, hWnd, NULL, NULL, NULL);

			hWndDoubletoTCHAR = CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				130, 140, 100, 20, hWnd, NULL, NULL, NULL);

			hWndStringtoTCHAR = CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				130, 230, 100, 20, hWnd, NULL, NULL, NULL);


			// put my name on it for the screenshot
			SetWindowText(hWnd, TEXT("CIS023_S2020_Lab12b Mark Berrett"));
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
