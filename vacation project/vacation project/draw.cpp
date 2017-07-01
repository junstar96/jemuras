#include"myhead.h"


GLubyte *pBytes; // 데이터를 가리킬 포인터
BITMAPINFO *info; // 비트맵 헤더 저장할 변수

GLuint textures[6];

void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;
	// h가 0일 때
	if (h == 0)
		h = 1;
	// 윈도우의 폭과 넓이 설정
	glViewport(0, 0, w, h);
	//원근투영 사용
	GLfloat fAspect;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (float)w / (float)h;
	gluPerspective(60.0, fAspect, 1.0, 10000.0);
	glTranslatef(0.0f, 0.0f, -300.0f);
	glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
	// 모델 뷰 행렬 스택 재설정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSwapBuffers();
}

void makefield()//여기다가 이미지를 넣기 위해 한 번 새로 만들어보자
{
	glPushMatrix();
	glTranslatef(0.0f, -200.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	


	glTexCoord2f(1, 1);
	glVertex3f(-1000.0f, 0.0f, 1000.0f);
	glTexCoord2f(0, 1);
	glVertex3f(1000.0f, 0.0f, 1000.0f);
	glTexCoord2f(0, 0);
	glVertex3f(1000.0f, 0.0f, -1000.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-1000.0f, 0.0f, -1000.0f);
	glEnd();

	glPopMatrix();
}

void RenderScene(void)
{
	glGenTextures(6, textures);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	pBytes = LoadDIBitmap("texture1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	pBytes = LoadDIBitmap("texture2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[2]);
	pBytes = LoadDIBitmap("texture3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[3]);
	pBytes = LoadDIBitmap("texture4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[4]);
	pBytes = LoadDIBitmap("texture5.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[5]);
	pBytes = LoadDIBitmap("texture6.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 100, 100, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);


	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glDisable (GL_CULL_FACE);


	glLoadIdentity();

	if (cameraturn)
	{
		gluLookAt(xmove, ymove, zmove, xmove + mywline / 2 * sin(speen[0]), ymove + mywline/2 * sin(speen[1]), zmove + mywline / 2 * cos(speen[0]) * cos(speen[1]), 0.0, 1.0, 0.0);
	}
	else
	{
		gluLookAt(xmove + mywline / 2 * sin(speen[0]), ymove + mywline / 2 * sin(speen[1]), zmove + mywline / 2 * cos(speen[0]) * cos(speen[1]) , xmove, ymove, zmove, 0.0, 1.0, 0.0);
	}

	glPushMatrix();

	//밑에 좌표축을 나타내는 선들
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);//x축
	glEnd();


	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);//y축
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);//z축
	glEnd();

	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
	
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	{
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
		//앞면
		//  glColor3f(1.0f,1.0f,0.0f);  // Yellow
		glTexCoord2f(1, 1);
		glVertex3f(50.0, 50.0, 50.0f);
		//  glColor3f(1.0f,0.0,1.0f);  // Magenta
		glTexCoord2f(0, 1);
		glVertex3f(-50.0, 50.0, 50.0f);
		//  glColor3f(0.0f,1.0f,1.0f);  // Cyan
		glTexCoord2f(0, 0);
		glVertex3f(-50.0, -50.0, 50.0f);
		//  glColor3f(0.0f,0.0f,1.0f);  // Blue
		glTexCoord2f(1, 0);
		glVertex3f(50.0, -50.0, 50.0f);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glBegin(GL_QUADS);
	{
		//뒷면
		//  glColor3f(1.0f,1.0f,1.0f);  // White
		glTexCoord2f(1, 1);
		glVertex3f(-50.0, 50.0, -50.0);
		//  glColor3f(0.0f,1.0f,0.0f);  // Green
		glTexCoord2f(0, 1);
		glVertex3f(50.0, 50.0, -50.0);
		//  glColor3f(1.0f,0.0f,0.0f);  // Red
		glTexCoord2f(0, 0);
		glVertex3f(50.0f, -50.0f, -50.0f);
		//  glColor3f(0.0f,0.0f,0.0f);  // Black
		glTexCoord2f(1, 0);
		glVertex3f(-50.0, -50.0, -50.0);

	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_QUADS);
	{
		//윗면
		//  glColor3f(1.0f,0.0,1.0f);  // Magenta
		glTexCoord2f(1, 1);
		glVertex3f(-50.0, 50.0, 50.0f);
		//  glColor3f(1.0f,1.0f,0.0f);  // Yellow
		glTexCoord2f(0, 1);
		glVertex3f(50.0, 50.0, 50.0f);
		//  glColor3f(0.0f,1.0f,0.0f);  // Green
		glTexCoord2f(0, 0);
		glVertex3f(50.0, 50.0, -50.0);
		//  glColor3f(1.0f,1.0f,1.0f);  // White
		glTexCoord2f(1, 0);
		glVertex3f(-50.0, 50.0, -50.0);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	{
		//아랫면
		//  glColor3f(1.0f,0.0f,0.0f);  // Red
		glTexCoord2f(1, 1);
		glVertex3f(50.0f, -50.0f, -50.0f);
		//  glColor3f(0.0f,0.0f,0.0f);  // Black
		glTexCoord2f(0, 1);
		glVertex3f(50.0, -50.0, 50.0f);
		//  glColor3f(0.0f,1.0f,1.0f);  // Cyan
		glTexCoord2f(0, 0);
		glVertex3f(-50.0, -50.0, 50.0f);
		//  glColor3f(0.0f,0.0f,1.0f);  // Blue
		glTexCoord2f(1, 0);
		glVertex3f(-50.0, -50.0, -50.0);

	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glBegin(GL_QUADS);
	{
		//왼면
		//  glColor3f(1.0f,0.0,1.0f);  // Magenta
		glTexCoord2f(1, 1);
		glVertex3f(-50.0, 50.0, 50.0f);
		//  glColor3f(1.0f,1.0f,1.0f);  // White
		glTexCoord2f(0, 1);
		glVertex3f(-50.0, 50.0, -50.0);
		//  glColor3f(0.0f,0.0f,0.0f);  // Black
		glTexCoord2f(0, 0);
		glVertex3f(-50.0, -50.0, -50.0);
		//  glColor3f(0.0f,1.0f,1.0f);  // Cyan
		glTexCoord2f(1, 0);
		glVertex3f(-50.0, -50.0, 50.0f);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glBegin(GL_QUADS);
	{
		//오른면
		//  glColor3f(0.0f,1.0f,0.0f);  // Green
		glTexCoord2f(1, 1);
		glVertex3f(50.0, 50.0, -50.0);
		//  glColor3f(1.0f,1.0f,0.0f);  // Yellow
		glTexCoord2f(0, 1);
		glVertex3f(50.0, 50.0, 50.0f);
		//  glColor3f(0.0f,0.0f,1.0f);  // Blue
		glTexCoord2f(0, 0);
		glVertex3f(50.0, -50.0, 50.0f);
		//  glColor3f(1.0f,0.0f,0.0f);  // Red
		glTexCoord2f(1, 0);
		glVertex3f(50.0f, -50.0f, -50.0f);
	}
	glEnd();




	makefield();

	glPopMatrix();
	glutSwapBuffers();
}



void basicsetting()//반사광이나 이면 지우기 등을 할 때
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
}

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info)
{
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	// 바이너리 읽기 모드로 파일을 연다
	if ((fp = fopen(filename, "rb")) == NULL)
		return NULL;
	// 비트맵 파일 헤더를 읽는다.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) {
		fclose(fp);
		return NULL;
	}
	// 파일이 BMP 파일인지 확인한다.
	if (header.bfType != 'MB') {
		fclose(fp);
		return NULL;
	}
	// BITMAPINFOHEADER 위치로 간다.
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	// 비트맵 이미지 데이터를 넣을 메모리 할당을 한다.
	if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
		fclose(fp);
		exit(0);
		return NULL;
	}
	// 비트맵 인포 헤더를 읽는다.
	if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// 비트맵의 크기 설정
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth *
		(*info)->bmiHeader.biBitCount + 7) / 8.0 *
		abs((*info)->bmiHeader.biHeight);
	// 비트맵의 크기만큼 메모리를 할당한다.
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// 비트맵 데이터를 bit(GLubyte 타입)에 저장한다.
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) {
		free(*info); free(bits);
		fclose(fp);
		return NULL;
	}
	fclose(fp);
	return bits;
}


