#pragma once

/**
@file		CMain.h
@date		2014/8/25
@author		Vallista
@brief		메인을 받는 곳
*/

class CMain : public CSingleton<CMain>
{
private:
	HDC							m_hDC;
	HWND						m_hWnd;
	HDC							m_hBackBuffer;
	HINSTANCE					m_hIns;
	HBITMAP						m_hBitmap;
	HBITMAP						m_hBitmap2;
	GdiplusStartupInput			m_GdiplusStartupInput;
	ULONG_PTR					m_GdiplusToken;

	POINT						m_cPos;

public:
	CMain(){};
	~CMain(){};

	bool Init(HWND hWnd);
	void Update(float dt);
	void Render();
	void Destroy();

	void GDIStart();

	void setHDC(HDC hdc);
	void setHINSTANCE(HINSTANCE hIns);

};