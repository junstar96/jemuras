#pragma once

#include<gl/glut.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<iostream>

#include<ctime>
#include<cstdlib>
#include<cmath>

#include<Windows.h>
#include<mmstream.h>
#define rad 0.1
#define angle 3.1415912 / 180.0
#define maxangle  360
#define xlinelen 160
#define ylinelen 120
#define mywline 800.0
#define myhline 600.0
#define myzline 400.0

#pragma comment(lib, "winmm.lib")


using std::cout;
using std::cin;
using std::endl;

struct point  // vec 0, 1, 2
{
	float x, y, z;
	float vec;

	int vecx, vecy, vecz;

	float colx, coly, colz;

	float wide; 
	float down;

	float size[2];

	bool bigger;

	void col(float s1, float s2, float s3)
	{
		colx = s1;
		coly = s2;
		colz = s3;
	}

	void init(float t1, float t2, float t3)
	{
		x = t1;
		y = t2;
		z = t3;
	}

};

struct clickpoint
{
	float pp[3];
	bool drawing;
	clickpoint* next;
};

GLvoid sin(GLvoid);
GLvoid resin(int x, int y);
void glkeyboard(unsigned char bkey, int x, int y);
void mouseboard(int button, int status, int x, int y);
void gltimer(int value);
void mainmenu(int button);
void donmouse(int x, int y);
void movemouse(int x, int y);
void starinit();


void boardvecter(int key, int x, int y);

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);


extern int w, h;



extern float xmove, ymove, zmove;

extern bool cull, smooth, shade;



extern float mousex, mousey;

extern GLfloat ctrp[100][3];

extern int pointnum;

extern bool camera;

extern GLfloat line[3][3][3];

extern bool lineup[3][3];

extern GLfloat waveline[3][100][3];

extern bool cameraview;


extern bool right;

extern GLfloat AmbientLight[8][4];
extern GLfloat DiffuseLight[8][4];
extern GLfloat SpecularLight[8][4];
extern GLfloat lightPos[8][4];

extern GLfloat snow[1000][3];

extern GLfloat trainreil[100][3];

extern float rolling;

extern int weather;

extern bool mousecameramove;

extern int  trainnum;

extern float trainmove;

extern float alphago;

extern GLfloat star[1000][3];

extern float life, speed;

extern float gas;

extern bool gasfull;

extern bool lebber;

extern int lebberuptimer;