#include"myhead.h"



void reilinit()
{
	int last = 0;
	int t = 0;
	for (int i = 0; i < 100; ++i)
	{
		t = rand() % 3;
		if (i == 0)
		{
			trainreil[i][0] = 0.0f;
			trainreil[i][1] = 0.0f;
			trainreil[i][2] = -mywline / 2;
		}
		else
		{
			trainreil[i][1] = trainreil[i - 1][1] + mywline*4;
			if (last != 1)
			{
				trainreil[i][0] = trainreil[i - 1][0];
			}
			else
			{
				switch (t)
				{
				case 0:
					trainreil[i][0] = trainreil[i - 1][0] - mywline;
					break;
				case 1:
					trainreil[i][0] = trainreil[i - 1][0];
					break;
				case 2:
					trainreil[i][0] = trainreil[i - 1][0] + mywline;
					break;
				}
			}
			trainreil[i][2] = trainreil[i - 1][2] + mywline;
		}

		
		last = t;
	}
}

void lightinit()
{
	for (int i = 0; i < 8; ++i)
	{
		AmbientLight[i][0] = 0.2f;
		AmbientLight[i][1] = 0.2f;
		AmbientLight[i][2] = 0.2f;
		AmbientLight[i][3] = 1.0f;
		DiffuseLight[i][0] = 1.0f;
		DiffuseLight[i][1] = 1.0f;
		DiffuseLight[i][2] = 1.0f;
		DiffuseLight[i][3] = 1.0f;
		SpecularLight[i][0] = 1.0;
		SpecularLight[i][1] = 1.0;
		SpecularLight[i][2] = 1.0;
		SpecularLight[i][3] = 1.0;
	}

	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			snow[i][j] = rand() % (int)mywline - mywline / 2;
		}
		snow[i][2] = rand() % ((int)mywline*2);
	}

	lightPos[0][0] = xmove;
	lightPos[0][1] = ymove;
	lightPos[0][2] = zmove;
	lightPos[0][3] = 1.0f;

	lightPos[1][0] = xmove + 200;
	lightPos[1][1] = ymove - mywline / 2;
	lightPos[1][2] = zmove + 1000;
	lightPos[1][3] = 1.0f;
}

void starinit()
{
	for (int i = 0; i < 1000; ++i)
	{
		star[i][0] = (rand() % 628 - 314) / 100.0;
		star[i][1] = star[i][0];
		star[i][2] = (rand() % 314 - 157) / 100.0;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			switch (i)
			{
			case 0:
			case 2:
				lineup[i][j] = false;
				break;
			case 1:
				lineup[i][j] = true;
				break;
			}
		}
	}

	lightinit();
	reilinit();
	starinit();

	

	
	

	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(650, 650);
	glutCreateWindow("study");
	glutDisplayFunc(sin);
	glutReshapeFunc(resin);
	glutKeyboardFunc(glkeyboard);
	glutSpecialFunc(boardvecter);
	glutMouseFunc(mouseboard);
	glutMotionFunc(movemouse);
	glutTimerFunc(100, gltimer, 1);
	glEnable(GL_DEPTH_TEST);
	

	GLint sub = glutCreateMenu(mainmenu);
	glutAddMenuEntry("cull", 1);
	glutAddMenuEntry("small", 2);
	glutAddMenuEntry("normal", 3);
	glutAddMenuEntry("green", 11);
	glutAddMenuEntry("three or two", 12);
	/*glutAddMenuEntry("blue", 13);*/
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	
	glutMainLoop();

	

}