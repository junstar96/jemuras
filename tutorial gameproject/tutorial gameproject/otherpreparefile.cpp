#include"gamefirsthead.h"

void outfromfile(TCHAR filename[], HWND hwnd)
{
	FILE* fptr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);

#ifdef _UNUCODE
	_tfopen_s(%fptr, filename, _T("r, ccs = UNICODE"));
#else
	_tfopen_s(&fptr, filename, _T("r"));
#endif
	while (_fgetts(buffer, 100, fptr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
		{
			buffer[_tcslen(buffer) - 1] = NULL;
			TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
			line++;
		}
	}
	fclose(fptr);
	ReleaseDC(hwnd, hdc);

}

double lengthpts(int x1, int y1, int x2, int y2)
{
	return (sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));
}

BOOL incircle(int x, int y, int mx, int my)
{
	if (lengthpts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
}

