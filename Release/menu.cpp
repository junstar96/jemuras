#include"myhead.h"


void mainmenu(int button)
{
	switch (button)
	{
	case 1:
		if (cull == false)
		{
			cull = true;
		}
		else
		{
			cull = false;
		}
		break;
	case 2:
		if (smooth == false)
		{
			smooth = true;
		}
		else
		{
			smooth = false;
		}
		break;
	case 3:
		if (shade == false)
		{
			shade = true;
		}
		else
		{
			shade = false;
		}
		break;
	case 11:
		if (camera == false)
		{
			camera = true;
		}
		else
		{
			camera = false;
		}
		break;
	case 12:
		if (!right)
		{
			right = true;
		}
		else
		{
			right = false;
		}
		break;
	/*case 13:
		break;*/
	}
	glutPostRedisplay();
}