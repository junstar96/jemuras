#include"myhead.h"

float mousex = 0.0f, mousey = 0.0f;

bool lineup[3][3];

GLfloat AmbientLight[8][4];
GLfloat DiffuseLight[8][4];
GLfloat SpecularLight[8][4];
GLfloat lightPos[8][4];
int w, h;

float xmove = 0, ymove = 0, zmove = 0;

float speen[3] = { 0.0, 0.0, 0.0 };

GLfloat rebirth[100][3];


bool cull = false, smooth = false, shade = false;


bool cameraturn = false;//false면 카메라가 0점을 보도록, true면 좌우를 살피는 식으로