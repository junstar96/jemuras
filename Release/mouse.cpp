#include"myhead.h"



void donmouse(int x, int y)
{
	cout << "비클릭중" << endl;
}

void movemouse(int x, int y)
{
	float realx = x / (float)650 * mywline - mywline / 2;
	float realy = (650 - y) / (float)650 * mywline - mywline / 2;
	
	cout << realx << ", " << realy << ", " << mousex << ", " << mousey << endl;

	
}

//mouse click x : x / (double)특정 포인트 * mywline, y : (특정 - y) / (double)특정 * myhline;

void mouseboard(int button, int status, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
	{

			mousex = x / (float)650 * mywline - mywline / 2;
			mousey = (650 - y) / (float)650 * mywline - mywline / 2;


			mousecameramove = true;
			
		
	}						

	if (button == GLUT_LEFT_BUTTON && status == GLUT_UP)
	{
		mousecameramove = false;
	}
	glutPostRedisplay();
}