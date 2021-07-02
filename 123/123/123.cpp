// 123.cpp : Definiuje punkt wejścia dla aplikacji.
//

#include "framework.h"
#include "123.h"
#include <gdiplus.h>


#define ID_1 555
#define ID_2 556
#define ID_3 557
#define ID_4 558


using namespace Gdiplus;


bool dzwig = true;
int waga = 4999;
LPWSTR WAGA;
HWND hText;
DWORD dlugosc;
LPWSTR Bufor;
bool podnoszenie;
bool full;
bool lewa = false;
bool prawa = false;
int x = 320;
int y = 300;


void draw(HDC hdc);

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

// Przekaż dalej deklaracje funkcji dołączone w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
   
    // TODO: W tym miejscu umieść kod.
  
    
    // Inicjuj ciągi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY123, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjowanie aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY123));

    MSG msg;

    // Główna pętla komunikatów:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return 0;//(int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  PRZEZNACZENIE: Rejestruje klasę okna.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY123));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY123);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

   

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   PRZEZNACZENIE: Zapisuje dojście wystąpienia i tworzy okno główne
//
//   KOMENTARZE:
//
//        W tej funkcji dojście wystąpienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyświetlane okno główne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojście wystąpienia w naszej zmiennej globalnej
    

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   
    hText = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE, 650, 5, 300, 25, hWnd, NULL, hInstance, NULL);
   
    SetWindowText(hText, L"4999");
   HWND przycisk1;
   HWND przycisk2;
   HWND przycisk3;
   HWND przycisk4;
  przycisk1 = CreateWindowEx(0, L"BUTTON", L"PODNIES", WS_CHILD | WS_VISIBLE,
      650, 35, 150, 30, hWnd, (HMENU)ID_1, hInstance, NULL);
  przycisk2 = CreateWindowEx(0, L"BUTTON", L"OPUSC ", WS_CHILD | WS_VISIBLE,
      800, 35, 150, 30, hWnd, (HMENU)ID_2, hInstance, NULL);
  przycisk3 = CreateWindowEx(0, L"BUTTON", L"LEWA ", WS_CHILD | WS_VISIBLE,
      650, 70, 150, 30, hWnd, (HMENU)ID_3, hInstance, NULL);
  przycisk4 = CreateWindowEx(0, L"BUTTON", L"PRAWA ", WS_CHILD | WS_VISIBLE,
      800, 70, 150, 30, hWnd, (HMENU)ID_4, hInstance, NULL);
 
  
   

   if(!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   
    UpdateWindow(hWnd);
   
   

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
// 

//
//  PRZEZNACZENIE: Przetwarza komunikaty dla okna głównego.
//
//  WM_COMMAND  - przetwarzaj menu aplikacji
//  WM_PAINT    - Maluj okno główne
//  WM_DESTROY  - opublikuj komunikat o wyjściu i wróć
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    
   
    switch (message)
    {
 
    case WM_COMMAND:
        {
   
       
        
        
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
           
            case ID_1:
                
                dlugosc = GetWindowTextLength(hText);
                Bufor = (LPWSTR)GlobalAlloc(GPTR, dlugosc + 1);
                GetWindowText(hText, Bufor, dlugosc + 1);
                
                waga = _wtoi(Bufor);
                
                 
                if (waga < 5000) {
                    full = true;
                    podnoszenie = true;
                }   else {
                    //MessageBox(hWnd, L"Przedmiot jest za ciezki.", L"Blad", MB_ICONINFORMATION);
                    full = false;
                }
               
               
                InvalidateRect(hWnd, 0, TRUE); 
                break;
            case ID_2:

                dlugosc = GetWindowTextLength(hText);
                Bufor = (LPWSTR)GlobalAlloc(GPTR, dlugosc + 1);
                GetWindowText(hText, Bufor, dlugosc + 1);
                waga = _wtoi(Bufor);
                WAGA = Bufor;
                if (waga < 5000) {
                    full = true;
                    podnoszenie = false;
                }
                else {
                    //MessageBox(hWnd, L"Przedmiot jest za ciezki.", L"Blad", MB_ICONINFORMATION);
                    full = false;
                    }
                
                 
                InvalidateRect(hWnd, 0, TRUE);
                break;
            case ID_3:

                dlugosc = GetWindowTextLength(hText);
                Bufor = (LPWSTR)GlobalAlloc(GPTR, dlugosc + 1);
                GetWindowText(hText, Bufor, dlugosc + 1);
                waga = _wtoi(Bufor);
                WAGA = Bufor;
                if (waga < 5000) {
                    full = true;
                    prawa = false;
                    lewa = true;
                }
                else {
                    //MessageBox(hWnd, L"Przedmiot jest za ciezki.", L"Blad", MB_ICONINFORMATION);
                    full = false;
                }

                 
                InvalidateRect(hWnd, 0, TRUE);
                break;
            case ID_4:

                dlugosc = GetWindowTextLength(hText);
                Bufor = (LPWSTR)GlobalAlloc(GPTR, dlugosc + 1);
                GetWindowText(hText, Bufor, dlugosc + 1);
                waga = _wtoi(Bufor);
                WAGA = Bufor;
                if (waga < 5000) {
                    full = true;
                    lewa = false;
                    prawa = true;
                }
                else {
                    //MessageBox(hWnd, L"Przedmiot jest za ciezki.", L"Blad", MB_ICONINFORMATION);
                    full = false;
                }

                 
                InvalidateRect(hWnd, 0, TRUE);
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
            // TODO: Tutaj dodaj kod rysujący używający elementu hdc...
            draw(hdc);
            EndPaint(hWnd, &ps);
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

// Procedura obsługi komunikatów dla okna informacji o programie.
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
void draw(HDC hdc) {
    
    Gdiplus::Graphics gf(hdc);
    Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0));
   
    Gdiplus::SolidBrush brush1(Gdiplus::Color(255, 255, 255, 0));
    Gdiplus::SolidBrush brush2(Gdiplus::Color(255, 0, 0, 0));
    Gdiplus::SolidBrush brush3(Gdiplus::Color(255, 0, 255, 0));
    Gdiplus::SolidBrush bialy(Gdiplus::Color(255, 255, 255, 255));
    

    if (full == false) {
        gf.FillRectangle(&brush1, 120, 40, 10, 350);
        gf.FillRectangle(&brush1, 90, 70, 300, 10);
        gf.FillRectangle(&brush2, 60, 60, 50, 50);
        gf.DrawLine(&pen, y+25, 80, y+25, x);           //lina
        gf.FillRectangle(&brush3, y, x, 50, 60);    // ladunek
        gf.FillRectangle(&brush2, 70, 380, 600, 10); 
    }
         if (full == true) {
        gf.FillRectangle(&brush1, 120, 40, 10, 350);
        gf.FillRectangle(&brush1, 90, 70, 300, 10);
        gf.FillRectangle(&brush2, 60, 60, 50, 50);
        gf.DrawLine(&pen, y+25, 80, y+25, x);           //lina
        gf.FillRectangle(&brush3, y, x, 50, 60);    // ladunek
        gf.FillRectangle(&brush2, 70, 380, 600, 10);
    }
            

    if (podnoszenie == true && full == true && x > 150 && lewa == false && prawa == false) {

        for (int i = 0; i < 17; i++) {
            x -= 1;
            gf.FillRectangle(&brush1, 120, 40, 10, 350);
            gf.FillRectangle(&brush1, 90, 70, 300, 10);
            gf.FillRectangle(&brush2, 60, 60, 50, 50);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            
            Sleep(10);
            gf.DrawLine(&pen, y+25, 80, y+25, x);
            gf.FillRectangle(&brush3, y, x, 50, 60);
            gf.FillRectangle(&bialy, y-1, x + 60, 52, 60);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);

        }

    }
    if (podnoszenie == false && full == true && x < 320 && lewa==false && prawa==false) {

        for (int i = 0; i < 17; i++) {
            x += 1;
            gf.FillRectangle(&brush1, 120, 40, 10, 350);
            gf.FillRectangle(&brush1, 90, 70, 300, 10);
            gf.FillRectangle(&brush2, 60, 60, 50, 50);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            Sleep(10);
            gf.FillRectangle(&bialy, y-1, x - 60, 52, 60);
            gf.FillRectangle(&brush3, y, x, 50, 60);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            gf.DrawLine(&pen, y+25, 80, y+25, x);
        }
    }

    if (prawa == true && full == true && y < 340) {

        for (int i = 0; i < 10; i++) {
            y += 1;
            gf.FillRectangle(&brush1, 120, 40, 10, 350);
            gf.FillRectangle(&brush1, 90, 70, 300, 10);
            gf.FillRectangle(&brush2, 60, 60, 50, 50);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            Sleep(10);
            gf.FillRectangle(&bialy, y - 50, x, 52, 60);
            gf.FillRectangle(&brush3, y, x, 50, 60);
            gf.FillRectangle(&bialy, y, x + 60, 52, 60);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            gf.DrawLine(&pen, y+25, 80, y+25, x);
            gf.FillRectangle(&brush1, 120, 40, 10, 350);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            gf.FillRectangle(&bialy, y + 15, 80, 10, x - 80);
        }
        prawa = false;
    }

    if (lewa == true && full == true && y > 150) {

        for (int i = 0; i < 10; i++) {
            y -= 1;
            gf.FillRectangle(&brush1, 120, 40, 10, 350);
            gf.FillRectangle(&brush1, 90, 70, 300, 10);
            gf.FillRectangle(&brush2, 60, 60, 50, 50);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            Sleep(10);
            gf.FillRectangle(&bialy, y+50, x, 52, 60);
            gf.FillRectangle(&brush3, y, x, 50, 60);
            gf.FillRectangle(&bialy, y, x + 60, 52, 60);
            gf.FillRectangle(&brush2, 70, 380, 600, 10);
            gf.DrawLine(&pen, y+25, 80, y+25, x);
            gf.FillRectangle(&bialy, y+26, 80, 10, x-80);
        }
        lewa = false;
    }
            
        
    }
    
    
   
    
