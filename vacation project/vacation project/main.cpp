#include"myhead.h"



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


	lightPos[0][0] = xmove;
	lightPos[0][1] = ymove;
	lightPos[0][2] = zmove;
	lightPos[0][3] = 1.0f;

	lightPos[1][0] = mywline*50;
	lightPos[1][1] = mywline*200;
	lightPos[1][2] = 0.0f;
	lightPos[1][3] = 1.0f;

}

void setreset()
{
	lightinit();
	for (int i = 0; i < 3; ++i)
	{
		speen[i] = 0.0f;
	}
}

void setupRC()
{
	
		glEnable(GL_DEPTH_TEST);  // 은면 제거
		glFrontFace(GL_CCW);   // 앞면 설정  
		glEnable(GL_CULL_FACE);  // 내부는 잘라낸다  
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 배경색 설정
}

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));

	
	lightinit();



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(650, 650);
	glutCreateWindow("study");
	/*glutDisplayFunc(sin);
	glutReshapeFunc(resin);*/
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(glkeyboard);
	glutSpecialFunc(boardvecter);
	glutMouseFunc(mouseboard);
	glutMotionFunc(movemouse);
	glutPassiveMotionFunc(donmouse);
	glutTimerFunc(100, gltimer, 1);
	setupRC();


	GLint sub = glutCreateMenu(mainmenu);
	glutAddMenuEntry("cull", 1);
	glutAddMenuEntry("small", 2);
	glutAddMenuEntry("normal", 3);
	glutAddMenuEntry("green", 11);
	glutAddMenuEntry("three or two", 12);
	glutAddMenuEntry("blue", 13);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

	
	glutMainLoop();

	

}


