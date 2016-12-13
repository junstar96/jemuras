#include"myhead.h"

GLvoid resin(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (right == true)
	{
		glOrtho(-mywline/2, mywline/2, -mywline/2, mywline/2, -mywline/2, mywline/2);// 이게 직각투영
	}
	else
	{
		gluPerspective(90.0f, w / h, 1.0, 200000); // 원근투영?
	}
	

	
	//glTranslatef(0.0, 0.0, -300.0);
	
	glMatrixMode(GL_MODELVIEW);
}

void reildraw()
{

	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	if(trainnum%2 == 0)
	{ 
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
	{
		glColor3f(0.0f, 0.0f, 1.0f);
	}
	glVertex3f(trainreil[trainnum][0] - mywline/8, trainreil[trainnum][1], trainreil[trainnum][2]);
	if (trainnum % 2 == 0)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	glVertex3f(trainreil[trainnum][0] + mywline / 8, trainreil[trainnum][1], trainreil[trainnum][2]);
	if (trainnum % 2 == 0)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	else
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	glVertex3f(trainreil[trainnum + 1][0] + mywline / 8, trainreil[trainnum + 1][1], trainreil[trainnum +1][2]);
	if (trainnum % 2 == 0)
	{
		glColor3f(0.0f, 0.0f, 1.0f);
	}
	else
	{
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	glVertex3f(trainreil[trainnum + 1][0] - mywline / 8, trainreil[trainnum + 1][1], trainreil[trainnum + 1][2]);

	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	if (trainnum % 2 == 0)
	{
		glColor3f(0.0f, 0.0f, 1.0f);
	}
	else
	{
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	glVertex3f(trainreil[trainnum + 1][0] - mywline / 8, trainreil[trainnum + 1][1], trainreil[trainnum + 1][2]);
	if (trainnum % 2 == 0)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	else
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	glVertex3f(trainreil[trainnum + 1][0] + mywline / 8, trainreil[trainnum + 1][1], trainreil[trainnum + 1][2]);
	if (trainnum % 2 == 0)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}

	glVertex3f(trainreil[trainnum + 2][0] + mywline / 8, trainreil[trainnum + 2][1], trainreil[trainnum + 2][2]);
	if(trainnum%2 == 0)
	{ 
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
	{
		glColor3f(0.0f, 0.0f, 1.0f);
	}
	glVertex3f(trainreil[trainnum + 2][0] - mywline / 8, trainreil[trainnum + 2][1], trainreil[trainnum + 2][2]);

	glEnd();


	glDisable(GL_COLOR_MATERIAL);
}

void woodprint()
{
	glDisable(GL_CULL_FACE);

	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


	glPushMatrix();
	glTranslatef(0.5*trainreil[trainnum][0] + 0.5*trainreil[trainnum + 1][0], 0.5*trainreil[trainnum][1] + 0.5*trainreil[trainnum + 1][1], 0.5*trainreil[trainnum][2] + 0.5*trainreil[trainnum + 1][2]);
	switch (trainnum % 2)
	{
	case 0:
		glPushMatrix();
		glTranslatef(-mywline / 2 - 160, 0.0f, mywline/3);
		glScalef(100, 100, mywline / 3 * 2);
		glColor3f(0.4f, 0.3f, 0.0f);
		glutSolidCube(1);

		glScalef(0.01, 0.01, 1.5 / mywline);
		glTranslatef(0.0f, 0.0f, mywline / 3);
		glPushMatrix();
		glScalef(300, 300, 150);
		glColor3f(0.27f, 0.78f, 0.24f);
		glutSolidCube(1);
		glPopMatrix();

		glPopMatrix();

		
		break;
	case 1:
		glPushMatrix();
		glTranslatef(mywline / 2 + 160, 0.0f, mywline / 3);
		glScalef(100, 100, mywline / 3 * 2);
		glColor3f(0.4f, 0.3f, 0.0f);
		glutSolidCube(1);


		glScalef(0.01, 0.01, 1.5 / mywline);
		glTranslatef(0.0f, 0.0f, mywline / 3);
		glPushMatrix();
		glScalef(300, 300, 150);
		glColor3f(0.27f, 0.78f, 0.24f);
		glutSolidCube(1);
		glPopMatrix();

		glPopMatrix();
		break;
	}
	glPopMatrix();



	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glEnable(GL_CULL_FACE);
	glDisable(GL_COLOR_MATERIAL);
}

void trainwall()
{
	glDisable(GL_CULL_FACE);

	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	

	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-mywline / 2, -mywline / 2, -mywline / 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-mywline / 2, mywline / 2, -mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-mywline / 2, mywline / 2, mywline / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-mywline / 2, -mywline / 2, mywline / 2);

	glEnd();

	glPushMatrix();
	glTranslatef(-mywline / 2, -mywline/4, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glScalef(1.0f, 50.0f, life / 20.0);

	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-mywline / 2, mywline / 4, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 50.0f, speed*50.0f + 250.0f);
	glutSolidCube(1);
	glPopMatrix();

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(mywline / 2, -mywline / 2, -mywline / 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(mywline / 2, -mywline / 2, mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(mywline / 2, mywline / 2, mywline / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(mywline / 2, mywline / 2, -mywline / 2);



	glEnd();

	glPushMatrix();
	static int lebberdown = -60;
	glTranslatef(mywline / 2, mywline / 4, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	if (lebber)
	{
		if (lebberdown <= -60)
		{
			lebberdown += 1;
		}
	}
	else
	{
		if (lebberdown >= -120)
		{
			lebberdown -= 1;
		}
	}
	glRotatef(lebberdown, 0.0f, 1.0f, 0.0f);
	glScalef(100, 50, 300);
	glutSolidCube(1);
	
	
	glPopMatrix();

	


	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-mywline / 2, mywline / 2, -mywline / 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(mywline / 2, mywline / 2, -mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(mywline / 2, mywline / 2, -mywline / 4);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-mywline / 2, mywline / 2, -mywline / 4);

	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-mywline / 2, -mywline / 2, -mywline/2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(mywline / 2, -mywline / 2, -mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(mywline / 2, mywline / 2, -mywline / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-mywline / 2, mywline / 2, -mywline / 2);



	glEnd();

	glBegin(GL_QUADS);//뒷면
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-mywline / 2, -mywline / 2, -mywline / 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-mywline / 2, -mywline / 2, mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(mywline / 2, -mywline / 2, mywline/2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(mywline / 2, -mywline / 2, -mywline / 2);

	glEnd();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	for (float i = 1.57; i > -gas; i -= 0.01)
	{ //y축은 -mywline / 2 이것이다.
		glVertex3f(200 * sin(i), -mywline / 2 + 20, 200 * cos(i));
	}

	glVertex3f(0.0f, -mywline / 2 + 20, 0.0f);
	glVertex3f(200 * sin(-1.57), -mywline / 2 + 20, 200 * cos(-1.57));

	glEnd();
	glPopMatrix();

	

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-mywline / 2, -mywline / 2, mywline / 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-mywline / 2, mywline / 2, mywline / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(mywline / 2, mywline / 2, mywline / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(mywline / 2, -mywline / 2, mywline / 2);

	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);
	glDisable(GL_COLOR_MATERIAL);
}

void stardraw()
{
	
	for (int i = 0; i < 1000; ++i)
	{
		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 128);

		glColor3f(1.0f, 1.0f, 1.0f);

		float starz = 1600.0f*cos(star[i][2]);
		float starx = sqrt(1600.0f*1600.0f - starz*starz)*cos(star[i][0]);
		float stary = sqrt(1600.0f*1600.0f - starz*starz)*sin(star[i][1]);

		glPushMatrix();
		glNormal3f(0.0, 0.0f, 1.0f);
		glTranslatef(starx, stary, starz);
		glutSolidSphere(10, 5, 5);

		glPopMatrix();
		glDisable(GL_COLOR_MATERIAL);
	}


	

}

void snowrain()
{
	

	for (int i = 0; i < 1000; ++i)
	{
		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 128);

		

		glPushMatrix();
		glNormal3f(0.0, 0.0f, 1.0f);
		glTranslatef(snow[i][0], snow[i][1], snow[i][2]);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidSphere(5, 10, 10);


		glPopMatrix();
		glDisable(GL_COLOR_MATERIAL);
	}

}

void weatherball()
{
	

	glDisable(GL_CULL_FACE);

	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	switch (weather)
	{
	case 0:
		glColor3f(0.3f, 0.5f, 0.7f);
		break;
	case 1:
		glColor3f(1.0f, 0.7f, 0.2f);
		break;
	case 2:
		glColor3f(0.2f, 0.2f, 0.4f);
		break;
	case 3:
		glColor3f(0.0f, 0.0f, 0.2f);
		break;
	}

	glNormal3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(1600, 100, 100);

	switch (weather)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		glPushMatrix();
		glEnable(GL_CULL_FACE);
		stardraw();
		glDisable(GL_CULL_FACE);
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		glEnable(GL_CULL_FACE);
		stardraw();
		glDisable(GL_CULL_FACE);
		glPopMatrix();
		break;
	}

	


	glEnable(GL_CULL_FACE);
	glDisable(GL_COLOR_MATERIAL);
}

void boardprint()
{
	glDisable(GL_CULL_FACE);

	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glColor3f(0.8f, 0.44f, 0.23f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -(mywline / 4) * 3);
	for (float i = 2.36; i >= 0.78f; i -= 0.01)
	{
		glVertex3f(1600 * cos(i), 1600 * sin(i), -mywline/4 - 25);
	}

	glEnd();

	glEnable(GL_CULL_FACE);
	glDisable(GL_COLOR_MATERIAL);
}

	


GLvoid sin(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	

	if (smooth == false)
	{
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glDisable(GL_DEPTH_TEST);
	}

	if (shade == false)
	{
		glShadeModel(GL_SMOOTH);
	}
	else
	{
		glShadeModel(GL_FLAT);
	}

	if (cull == false)
	{
		glEnable(GL_CULL_FACE);

	}
	else
	{
		glDisable(GL_CULL_FACE);
	}
	

	glFrontFace(GL_CCW);

	glLoadIdentity();

	gluLookAt(xmove, ymove, zmove, xmove + mywline/2*sin(rolling), ymove + mywline/2*cos(rolling), zmove, 0.0, 0.0, 1.0);

	glEnable(GL_LIGHTING);



	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight[0]);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight[0]);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight[0]);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos[0]);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight[1]);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight[1]);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight[1]);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos[1]);
	glEnable(GL_LIGHT1);

	

	reildraw();
	woodprint();


	glPushMatrix();
	glTranslatef(xmove, ymove, zmove);
	//glRotatef(movecamera[0], 0.0f, 0.0f, 1.0f);
	weatherball();
	trainwall();
	boardprint();
	/*glPushMatrix();
	glEnable(GL_BLEND);
	glTranslatef(0.0f, mywline/4, 0.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0, 0.0, 1.0, alphago);
	glutSolidCube(100);

	glDisable(GL_BLEND);
	glPopMatrix();*/
	

	glPopMatrix();

	
	/*glPushMatrix();

	glTranslatef(0.0f, 0.0f, -mywline/2);
	mainfield();

	glPopMatrix();*/

	/*glEnable(GL_BLEND);
	glTranslatef(0.0f, mywline / 4, 0.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0, 0.0, 1.0, 0.3);
	glutSolidCube(100);

	glDisable(GL_BLEND);*/


	glutSwapBuffers();
}