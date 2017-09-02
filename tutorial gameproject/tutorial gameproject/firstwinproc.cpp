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
	CString stringimage = _T("제길바밤바.png");
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

	int boil_x = windowrect.right / 5; int boil_y = windowrect.bottom / 5; //이 두 개는 이미지를 나누기 위해 사용한 변수

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
	//키보드를 이용하여 흰 공간을 다른 걸로 채운다, 1이 오른쪽, 2가 왼쪽, 3이 위쪽, 4가 아래쪽

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

	TCHAR str[100], filestr[100] = _T("start.txt");//str은 모르겠고 filestr은 위치를 저장하는 것
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0");


	static HBITMAP hbit;//이미지를 위한 
	static RECT windowrect;//윈도우 크기
	static int ypos;//글씨가 내려오게 하는 것
	TCHAR word[] = _T("대한민국");

	
	static POINT ball_line;
	static POINT line_fin;
	static float rad;
	static float line_r;

	static bool draw_line;//가볍게 공 선그리기 연습

	static int count;//글을 쓰기 위한 것
	static int oldx, oldy, newx, newy;//도형의 크기
	static int pict_position[25];//총 
	static int sel_position;//빈 공간의 번호
	int move_white_box;//키보드를 이용하여 흰 공간을 다른 걸로 채운다, 1이 오른쪽, 2가 왼쪽, 3이 위쪽, 4가 아래쪽
	int mx, my;//마우스 선택시의 클릭부
	int fin_answer;//종료명령 메세지 박스 생성
	static bool selection;//마우스 클릭 여부
	static bool show_real_image;//중간에 원본 이미지를 보여달라고 할 때 쓸 것

	CHOOSEFONT font;//이미지같은 폰트
	static COLORREF fcolor;//폰트 색
	HFONT nfont, oldfont;//뉴 올드 폰트
	static LOGFONT logfont;//폰트 기억
	/*HPEN hpen, oldpen;
	HBRUSH hbrush, oldbrush;*/

	



	switch (ismg)
	{
	case WM_CREATE://생성칸
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
		case VK_RIGHT://방향키 오른쪽
			break;
		case VK_LEFT://방향키 왼쪽
			break;
		case VK_UP://방향키 위쪽

			break;
		case VK_DOWN://방향키 아래쪽

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

	case WM_MOUSEMOVE://마우스 움직임
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

	case WM_CHAR://글자입력칸
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

	case WM_PAINT://그림, 페인팅
	{
		GetClientRect(hwnd, &windowrect);
		hdc = BeginPaint(hwnd, &ps);//이건 핸들
									//여기서부터

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
		

		//여기까지가 선언하는 위치로




		SelectObject(hdc, oldfont);
		DeleteObject(nfont);
		//여기서부터
		/*SelectObject(hdc, oldpen);
		DeleteObject(hpen);



		SelectObject(hdc, oldbrush);
		DeleteObject(hbrush);*/
		//여기까지가 삭제를 담당한다.
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_TIMER://타이머 설정
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
				_stprintf_s(str, _T("%s 파일로 저장하시겠습니까?"), SaveFile.lpstrFile);
				MessageBox(hwnd, str, _T("저장하기 선택"), MB_OK);
			}

			break;
		case ID_finish:
			fin_answer = MessageBox(hwnd, _T("파일을 저장하고 끝내시겠습니까?"), _T("끝내기 선택"), MB_YESNOCANCEL);
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