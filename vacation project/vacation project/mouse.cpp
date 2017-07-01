#include"myhead.h"



void donmouse(int x, int y)//마우스를 움직이지 않을 때
{
	mousex = 0;
	mousey = 0;
}

void movemouse(int x, int y)//마우스를 움직일 때
{
	float realx = x / (float)650 * mywline - mywline / 2;
	float realy = (650 - y) / (float)650 * mywline - mywline / 2;
	
	if (realx < mousex)
	{
		speen[0] += 0.03f;
	}
	else if (realx > mousex)
	{
		speen[0] -= 0.03f;
	}

	if (realy < mousey)
	{
		if (speen[1] < 0.78f)
		{
			speen[1] += 0.03f;
		}
		else
		{
			speen[1] = 0.78f;
		}
	}
	else if (realy > mousey)
	{
		if (speen[1] > -0.78f)
		{
			speen[1] -= 0.03f;
		}
		else
		{
			speen[1] = -0.78f;
		}
	}

	mousex = realx;
	mousey = realy;

	cout << speen[0] << "," << speen[1] << endl;
	
}

//mouse click x : x / (double)특정 포인트 * mywline, y : (특정 - y) / (double)특정 * myhline;

void mouseboard(int button, int status, int x, int y)//마우스를 클릭했을 때
{
	if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
	{

			mousex = x / (float)650 * mywline - mywline / 2;
			mousey = (650 - y) / (float)650 * mywline - mywline / 2;
			
		
	}						

	if (button == GLUT_LEFT_BUTTON && status == GLUT_UP)
	{
	}
	glutPostRedisplay();
}