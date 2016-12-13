#include"myhead.h"

float mousex = 0.0f, mousey = 0.0f;

int wavenum = 0;

GLfloat waveline[3][100][3];

int movecamera[3] = { 0,0,0 };

point board[5];


GLfloat ctrp[100][3];

int pointnum = 0;

bool lineup[3][3];

GLfloat AmbientLight[8][4];
GLfloat DiffuseLight[8][4];
GLfloat SpecularLight[8][4];
GLfloat lightPos[8][4];

GLfloat snow[1000][3];

GLfloat trainreil[100][3];

GLfloat star[1000][3];

GLfloat traint = 0.0;
int trainpoint = 0;

int w, h;

float xmove = 0, ymove = 0, zmove = 0;

float xspeen = 0.0, yspeen = 0.0, zspeen = 0.0;


GLfloat rebirth[100][3];


bool cull = false, smooth = false, shade = false;

GLfloat line[3][3][3] = { { { -mywline / 2, -mywline / 8, -mywline / 2 },{ 0.0f, -mywline / 8, -mywline / 2 },{ mywline / 2, -mywline / 8, -mywline / 2 } },
{ { -mywline / 2, 0.0, 0.0 },{ 0.0f, 0.0f, 0.0 },{ mywline / 2, 0.0, 0.0 } },
{ { -mywline / 2, mywline / 8, mywline / 2 },{ 0.0f, mywline / 8, mywline / 2 },{ mywline / 2, mywline / 8, mywline / 2 } } };


int weather = 0;

int trainnum = 0;

float trainmove = 0;

bool mousecameramove = false;

float rolling = 0;

bool cameraview = false;
float alphago = 0.5;

bool camera = false;
bool right = false;

float life = 5000.0, speed = 0.0;

float gas = 0.0;

bool gasfull = false;

bool lebber = false;

int lebberuptimer = 0;