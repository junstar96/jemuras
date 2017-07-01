#include"myhead.h"


void gltimer(int value)
{
	

	

	
	glutTimerFunc(10, gltimer, 1);
	glutPostRedisplay();

	

	
}
