#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	//!< �������� ����
	HINSTANCE					hInst;
	HWND						hWnd;
	WNDCLASS					WndClass;
	MSG							Message;
	RECT						Rect;

	//!< GDI+ ���� ����
	CMain::GetInstance()->GDIStart();

	//!< ������ ����
	Rect						= {0, 0, D_SCREEN_WIDTH, D_SCREEN_HEIGHT};
	hInst						= hInstance;
	WndClass.cbClsExtra			= 0;
	WndClass.cbWndExtra			= 0;
	WndClass.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance			= hInst;
	WndClass.lpfnWndProc		= (WNDPROC)WndProc;
	WndClass.lpszClassName		= D_GAME_NAME;
	WndClass.lpszMenuName		= NULL;
	WndClass.style				= CS_HREDRAW | CS_VREDRAW;
	
	//!< ������ ������ �Ѱ��ִ� ��
	RegisterClass(&WndClass);

	//!< �������� ũ�⸦ �Ȱ����� ���� (�̰� ���ϸ� ������ ũ�Ⱑ �ڽ� ������ ������ ��
	AdjustWindowRect(&Rect, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION, false);

	//!< �����츦 �޸𸮿� �ø�
	hWnd = CreateWindow(D_GAME_NAME, D_GAME_NAME, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION, D_SCREEN_XPOS, D_SCREEN_YPOS, D_SCREEN_WIDTH, D_SCREEN_HEIGHT, NULL, NULL, hInst, 0);
	
	//!< �ν��Ͻ� ������ ������
	CMain::GetInstance()->setHINSTANCE(hInst);

	//!< �ʱ�ȭ ���� (���� NULL ���� ������ false)
	if (!CMain::GetInstance()->Init(hWnd))
		return false;
			
	//!< �����츦 ȭ��� �׸�
	ShowWindow(hWnd, nCmdShow);

	//!< �޽��� ����
	while (1)
	{
		if (PeekMessage(&Message, 0, 0, 0, PM_REMOVE))		//!< �޽����� ������ ���
		{
			if (Message.message == WM_QUIT)
				break;

			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else                                                //!< �޽����� ������ �ʾ��� ���
		{
			CMain::GetInstance()->Update(0);
			CMain::GetInstance()->Render();
		}
	}

	//!< ������ ������ �޸� ����
	CMain::GetInstance()->Destroy();						

	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		case WM_TIMER:
			CMain::GetInstance()->Update(0);
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					CMain::GetInstance()->Destroy();
					PostQuitMessage(0);
				break;
			}
		break;
		case WM_DESTROY:
			CMain::GetInstance()->Destroy();
			PostQuitMessage(0);
			break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}