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


bool cameraturn = false;//false�� ī�޶� 0���� ������, true�� �¿츦 ���Ǵ� ������