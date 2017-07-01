#include "stdafx.h"

bool CMain::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	if (m_hWnd == NULL)
		return false;

	m_hDC = GetDC(m_hWnd);
	m_hBackBuffer = CreateCompatibleDC(m_hDC);
	m_hBitmap = LoadBitmap(m_hIns, MAKEINTRESOURCE(m_hBackBuffer));//CreateCompatibleBitmap(m_hDC, D_SCREEN_WIDTH, D_SCREEN_HEIGHT);
	SelectObject(m_hBackBuffer, (HBITMAP)m_hBitmap);
	ReleaseDC(m_hWnd, m_hDC);

	m_cPos.x = 10;
	m_cPos.y = 10;

	SetTimer(m_hWnd, 0, 10, NULL);

	return true;
}

void CMain::Update(float dt)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) m_cPos.x -= 1.0f;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) m_cPos.x += 1.0f;
}

void CMain::Render()
{
	HDC hdc = GetDC(m_hWnd);
	PatBlt(m_hBackBuffer, 0, 0, D_SCREEN_WIDTH, D_SCREEN_HEIGHT, BLACKNESS);

	Graphics graphics(hdc);

	Image		image(L"0.png");
	graphics.DrawImage(&image, m_cPos.x, m_cPos.y);

	BitBlt(m_hDC, 0, 0, D_SCREEN_WIDTH, D_SCREEN_HEIGHT, m_hBackBuffer, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, m_hDC);
}

void CMain::Destroy()
{
	KillTimer(m_hWnd, 0);

	SelectObject(m_hBackBuffer, m_hBitmap2);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hBackBuffer);
}

void CMain::GDIStart()
{
	GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, NULL);
}

void CMain::setHDC(HDC hdc)
{
	m_hDC = hdc;
}

void CMain::setHINSTANCE(HINSTANCE hIns)
{
	m_hIns = hIns;
}