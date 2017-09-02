#include"total head.h"
#define py 3.1415926535897
#define deg2rad py/180


HINSTANCE hinst;

void textprint(HDC hdc, int x, int y, TCHAR text[])
{
	SetTextColor(hdc, RGB(255, 255, 255));
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			TextOut(hdc, x + i, y + j, text, _tcslen(text));
		}
	}
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, x, y, text, _tcslen(text));
}

void cimagetest(HDC hdc)
{
	CString stringimage = _T("����ٹ��.png");
	CImage* image = new CImage;

	HRESULT hresult = image->Load(stringimage);

	if (FAILED(hresult))
	{
		exit(1);

	}

	//image.BitBlt(hdc, 0, 0, SRCCOPY);
	image->StretchBlt(hdc, 0, 0, 800, 600, SRCCOPY);

	
	delete image;
}


void real_picture(HDC hdc, HBITMAP hbit, RECT windowrect)
{
	HDC memdc;
	HBITMAP oldbit;

	memdc = CreateCompatibleDC(hdc);
	/*if (hbit == NULL)
	{
		hbit = CreateCompatibleBitmap(hdc, 520, 480);
	}*/
	oldbit = (HBITMAP)SelectObject(memdc, hbit);
	

	SetBkMode(memdc, TRANSPARENT);

	StretchBlt(hdc, 0, 0, windowrect.right, windowrect.bottom, memdc, 0, 0, 520, 480, SRCCOPY);

	

	SelectObject(memdc, oldbit);
	DeleteDC(memdc);
}

void suffle_list(int list_len, int list[])
{
	int list1 = 0, list2 = 0;
	for (int i = 0; i < list_len * 2; ++i)
	{
		list1 = rand() % (list_len);
		list2 = rand() % (list_len);
		int temp = list[list1];
		list[list1] = list[list2];
		list[list2] = temp;
	}
	
}

void puzzle_picture(HDC hdc, HBITMAP hbit, RECT windowrect, int pict_position[], int sel_position)
{
	HDC memdc;
	HBITMAP oldbit;

	memdc = CreateCompatibleDC(hdc);
	oldbit = (HBITMAP)SelectObject(memdc, hbit);

	SelectObject(memdc, oldbit);
	DeleteDC(memdc);
}

void blind_picture(HDC hdc, HBITMAP hbit, RECT windowrect, int list[], int sel_pict)
{
	HDC memdc;
	HBITMAP oldbit;

	int boil_x = windowrect.right / 5; int boil_y = windowrect.bottom / 5; //�� �� ���� �̹����� ������ ���� ����� ����

	memdc = CreateCompatibleDC(hdc);
	oldbit = (HBITMAP)SelectObject(memdc, hbit);

	for (int i = 0; i < 25; ++i)
	{
		if (list[i] != sel_pict)
		{
			StretchBlt(hdc, boil_x*(i%5), boil_y*(i/5), boil_x, boil_y, memdc, 104*(list[i]%5), 96*(list[i]/5), 104, 96, SRCCOPY);
		}
	}

	SelectObject(memdc, oldbit);
	DeleteDC(memdc);
}

void first_suffle_picture(int pict_position[])
{
	for (int i = 1; i < 25; ++i)
	{
		for (int j = i; j < i; ++j)
		{
			pict_position[i] = rand() % 24 + 1;
			if (pict_position[j] == pict_position[i])
				continue;
		}
	}
}

void check_move_white_box(int sel_positon, int pict_position[], int move_white_box)
{
	//Ű���带 �̿��Ͽ� �� ������ �ٸ� �ɷ� ä���, 1�� ������, 2�� ����, 3�� ����, 4�� �Ʒ���

	switch (move_white_box)
	{
	case 1:
		if (sel_positon % 5 < 4)
		{
			
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}


}

void init_re_point(POINT& ball_line, POINT& line_fin)
{
	ball_line.x = 100;
	ball_line.y = 100;

	line_fin.x = 300;
	line_fin.y = 0;
}

void line_r_check(POINT& ball_line, POINT& line_fin, float& line_r)
{
	line_r = sqrt((ball_line.x - line_fin.x)*(ball_line.x - line_fin.x) + (ball_line.y - line_fin.y)*(ball_line.y - line_fin.y));
}

void move_ball(POINT& ball_line, POINT& line_fin, float rad, float line_r)
{
	ball_line.x = line_fin.x + line_r*cos(rad);
	ball_line.y = line_fin.y + line_r*sin(rad);
}


LRESULT CALLBACK wndProc(HWND hwnd, UINT ismg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	OPENFILENAME startfile;
	OPENFILENAME SaveFile;

	TCHAR str[100], filestr[100] = _T("start.txt");//str�� �𸣰ڰ� filestr�� ��ġ�� �����ϴ� ��
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0");


	static HBITMAP hbit;//�̹����� ���� 
	static RECT windowrect;//������ ũ��
	static int ypos;//�۾��� �������� �ϴ� ��
	TCHAR word[] = _T("���ѹα�");

	
	static POINT ball_line;
	static POINT line_fin;
	static float rad;
	static float line_r;

	static bool draw_line;//������ �� ���׸��� ����

	static int count;//���� ���� ���� ��
	static int oldx, oldy, newx, newy;//������ ũ��
	static int pict_position[25];//�� 
	static int sel_position;//�� ������ ��ȣ
	int move_white_box;//Ű���带 �̿��Ͽ� �� ������ �ٸ� �ɷ� ä���, 1�� ������, 2�� ����, 3�� ����, 4�� �Ʒ���
	int mx, my;//���콺 ���ý��� Ŭ����
	int fin_answer;//������ �޼��� �ڽ� ����
	static bool selection;//���콺 Ŭ�� ����
	static bool show_real_image;//�߰��� ���� �̹����� �����޶�� �� �� �� ��

	CHOOSEFONT font;//�̹������� ��Ʈ
	static COLORREF fcolor;//��Ʈ ��
	HFONT nfont, oldfont;//�� �õ� ��Ʈ
	static LOGFONT logfont;//��Ʈ ���
	/*HPEN hpen, oldpen;
	HBRUSH hbrush, oldbrush;*/

	



	switch (ismg)
	{
	case WM_CREATE://����ĭ
		move_white_box = 0;
		ypos = -30;
		GetClientRect(hwnd, &windowrect);
		count = 0;
		oldx = newx = 50;   oldy = newy = 50;
		selection = FALSE;
		hbit = (HBITMAP)LoadBitmap(hinst, MAKEINTRESOURCE(IDB_BITMAP2));
		SetTimer(hwnd, 1, 70, NULL);
		show_real_image = TRUE;
		init_re_point(ball_line, line_fin);
		rad = 0.0;
		draw_line = false;
		line_r = 0;

		for (int i = 0; i < 25; ++i)
		{
			pict_position[i] = i;
		}
		sel_position = 0;
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_RIGHT:
			move_white_box = 1;
			check_move_white_box(sel_position, pict_position, move_white_box);
			break;

		case VK_LEFT:
			move_white_box = 2;
			check_move_white_box(sel_position, pict_position, move_white_box);
			break;

		case VK_UP:
			move_white_box = 3;
			check_move_white_box(sel_position, pict_position, move_white_box);
			break;
		case VK_DOWN:
			move_white_box = 4;
			check_move_white_box(sel_position, pict_position, move_white_box);
			break;

		case VK_SPACE:
			
			if (draw_line == false)
			{
				line_r_check(ball_line, line_fin, line_r);
				draw_line = true;
			}
			else
				draw_line = false;
			break;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT://����Ű ������
			break;
		case VK_LEFT://����Ű ����
			break;
		case VK_UP://����Ű ����

			break;
		case VK_DOWN://����Ű �Ʒ���

			break;
		case VK_RETURN:
			break;
		}
		InvalidateRgn(hwnd, NULL, FALSE);
		break;

	case WM_LBUTTONDOWN:
		selection = TRUE;



		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		selection = FALSE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE://���콺 ������
		hdc = GetDC(hwnd);

		if (selection)
		{
			SetROP2(hdc, R2_XORPEN);
			SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			MoveToEx(hdc, oldx, oldy, NULL);
			LineTo(hdc, newx, newy);
			MoveToEx(hdc, oldx, oldy, NULL);
			LineTo(hdc, mx, my);
			newx = mx, newy = my;
		}
		ReleaseDC(hwnd, hdc);
		break;

	case WM_CHAR://�����Է�ĭ
		hdc = GetDC(hwnd);

		switch (wParam)
		{
		case VK_BACK:
			if (count > 0)
			{
				count--;
			}
			break;
		default:
			str[count++] = wParam;
			break;
		}



		str[count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_PAINT://�׸�, ������
	{
		GetClientRect(hwnd, &windowrect);
		hdc = BeginPaint(hwnd, &ps);//�̰� �ڵ�
									//���⼭����

		nfont = CreateFontIndirect(&logfont);
		oldfont = (HFONT)SelectObject(hdc, nfont);
		SetTextColor(hdc, fcolor);

		Ellipse(hdc, ball_line.x - 50, ball_line.y - 50, ball_line.x + 50, ball_line.y + 50);
		if (draw_line == true)
		{
			MoveToEx(hdc, ball_line.x, ball_line.y, NULL);
			LineTo(hdc, line_fin.x, line_fin.y);
		}
		/*memdc = CreateCompatibleDC(hdc);
		memdc2 = CreateCompatibleDC(memdc);
		if (hbit == NULL)
		{
			hbit = CreateCompatibleBitmap(hdc, 520, 480);
		}
		oldbit = (HBITMAP)SelectObject(memdc, hbit);
		oldbit2 = (HBITMAP)SelectObject(memdc2, hbit2);
		BitBlt(memdc, 0, 0, 520, 480, memdc2, 0, 0, SRCCOPY);
		
		SetBkMode(memdc, TRANSPARENT);

		
		BitBlt(hdc, 0, 0, 520, 480, memdc, 0, 0, SRCCOPY);*/
	
		/*if (show_real_image)
		{
			real_picture(hdc, hbit, windowrect);
		}
		else
		{
			blind_picture(hdc, hbit, windowrect, pict_position, sel_position);
		}*/

		
		


		/*SelectObject(memdc, oldbit);
		SelectObject(memdc2, oldbit2);
		DeleteDC(memdc2);
		DeleteDC(memdc);*/
		

		//��������� �����ϴ� ��ġ��




		SelectObject(hdc, oldfont);
		DeleteObject(nfont);
		//���⼭����
		/*SelectObject(hdc, oldpen);
		DeleteObject(hpen);



		SelectObject(hdc, oldbrush);
		DeleteObject(hbrush);*/
		//��������� ������ ����Ѵ�.
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_TIMER://Ÿ�̸� ����
		switch (wParam)
		{
		case 1:
			ypos += 1;
			if (ypos > windowrect.bottom) ypos = -30;

			if (draw_line)
			{
				rad += deg2rad;
				move_ball(ball_line, line_fin, rad, line_r);
			}
			

			InvalidateRgn(hwnd, NULL, TRUE);
			return 0;
			break;
		case 2:
			break;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_newfile:
			memset(&startfile, 0, sizeof(OPENFILENAME));
			startfile.lStructSize = sizeof(OPENFILENAME);
			startfile.hwndOwner = hwnd;
			startfile.lpstrFilter = filter;
			startfile.lpstrFile = filestr;
			startfile.nMaxFile = 100;
			startfile.lpstrInitialDir = _T(".");

			if (GetOpenFileName(&startfile) != 0)
			{
				outfromfile(startfile.lpstrFile, hwnd);
			}
			InvalidateRgn(hwnd, NULL, TRUE);
			break;
		case ID_savefile:
			memset(&SaveFile, 0, sizeof(OPENFILENAME));
			SaveFile.lStructSize = sizeof(OPENFILENAME);
			SaveFile.hwndOwner = hwnd;
			SaveFile.lpstrFilter = filter;
			SaveFile.lpstrFile = filestr;
			SaveFile.nMaxFile = 256;
			SaveFile.lpstrInitialDir = _T(".");
			if (GetSaveFileName(&SaveFile) != 0)
			{
				_stprintf_s(str, _T("%s ���Ϸ� �����Ͻðڽ��ϱ�?"), SaveFile.lpstrFile);
				MessageBox(hwnd, str, _T("�����ϱ� ����"), MB_OK);
			}

			break;
		case ID_finish:
			fin_answer = MessageBox(hwnd, _T("������ �����ϰ� �����ðڽ��ϱ�?"), _T("������ ����"), MB_YESNOCANCEL);
			if (fin_answer == IDYES || fin_answer == IDNO)
			{
				PostQuitMessage(0);
			}
			break;

		case ID_font:
			memset(&font, 0, sizeof(CHOOSEFONT));
			font.lStructSize = sizeof(CHOOSEFONT);
			font.hwndOwner = hwnd;
			font.lpLogFont = &logfont;
			font.Flags = CF_EFFECTS | CF_SCREENFONTS;
			if (ChooseFont(&font) != 0)
			{
				fcolor = font.rgbColors;
				InvalidateRgn(hwnd, NULL, TRUE);
			}
			break;
		case ID_rewind:
		{
			show_real_image = TRUE;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
			break;
		case ID_gamestart:
		{
			suffle_list(25, pict_position);
			show_real_image = FALSE;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
			break;
		case ID_gamereset:
		{
			show_real_image = FALSE;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
			break;

		}
		break;
	case WM_DESTROY:
		DeleteObject(hbit);
		/*DeleteObject(hbit2);*/
		KillTimer(hwnd, 1);
		KillTimer(hwnd, 2);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, ismg, wParam, lParam);
}