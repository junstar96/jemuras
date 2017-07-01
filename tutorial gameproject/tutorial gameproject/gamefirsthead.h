#pragma once
#include<windows.h>
#include<iostream>
#include<cmath>
#include<tchar.h>
#include<gdiplus.h>
#include<atlimage.h>
//#include<afxwin.h>
#include"..\tutorial gameproject\resource.h"
#define xwire 800
#define ywire 600
#define BSIZE 40
using std::cout;
using std::endl;
using std::string;
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

extern HINSTANCE hinst;



LRESULT CALLBACK wndProc(HWND hwnd, UINT ismg, WPARAM wParam, LPARAM lParam);

void outfromfile(TCHAR filename[], HWND hwnd);

double lengthpts(int x1, int y1, int x2, int y2);

BOOL incircle(int x, int y, int mx, int my);

