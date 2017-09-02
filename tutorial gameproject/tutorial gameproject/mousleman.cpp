#include"mousleman.h"

void general::onpaint(HDC hdc)
{
	image->StretchBlt(hdc, 0, 0, 800, 600, SRCCOPY);
}

void general::get_image()
{
	imagename = _T("����ٹ��.png");

	HRESULT hresult = image->Load(imagename);

	if (FAILED(hresult))
	{
		exit(1);

	}
}