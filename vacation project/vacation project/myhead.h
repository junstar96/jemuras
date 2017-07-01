#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<Windows.h>
#include<mmstream.h>
#include"MMsystem.h"
#include<gl/glut.h>
#include<gl/GL.h>
#include<gl/GLU.h>

#include<ctime>
#include<cstdlib>
#include<cmath>


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
using std::string;


class character
{
protected:
	string name;//이름
	int hp;//체력, 다 달면 죽음
	int atp;//공격력, 랜덤 수치로 결정 예상(rand()%10~15 정도, 이걸 뺄 수도 있음)
public:
	character() : hp(0), atp(0), name("clear"){} //초기 상태
	
	void gethp(int HP) { hp = HP; }; //이것은 체력값을 받는 것입니다.
	void settingatp(int ATP) { atp = ATP; };//공격값을 받을 일이 있을 때
	virtual void upgrateATP() = 0;//업그레이드 등을 통해 공격력에 변화가 생길 때

	virtual void characterkeymove() = 0; //키를 통해 조작을 한다고 했을 때 반응할 것

	
};



void RenderScene(void);//이미지 출력용
void ChangeSize(int w, int h);//크기가 바뀌었을 때를 위한 것
void glkeyboard(unsigned char bkey, int x, int y);//키보드 버튼을 알려줌
void mouseboard(int button, int status, int x, int y);//마우스 클릭
void gltimer(int value);//타이머
void mainmenu(int button);//메뉴창을 알려줌
void donmouse(int x, int y);//마우스가 아무런 일도 하지 않을 때 관여
void movemouse(int x, int y);//마우스가 움직일 때 관여
void setreset();//현 상황을 초기로 되돌려버리는 함수

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);//이미지를 받아오는 함수, 현재 손 보고 있는 중

void boardvecter(int key, int x, int y);//보드에 존재하고 있는 파일, 화살표등을 건든다.




extern int w, h;  //화면의 넓이값
extern float xmove, ymove, zmove;//방향을 움직이는 것이다.
extern float speen[3];//순서대로 xyz 회전을 마우스로 한다. 

extern float mousex, mousey;//마우스가 찍힌 장소값을 입력하는 것





extern GLfloat AmbientLight[8][4];//앰비언트갑
extern GLfloat DiffuseLight[8][4];//디퓨즈값
extern GLfloat SpecularLight[8][4];//스펙큘러값
extern GLfloat lightPos[8][4];//빛의 위치


extern bool cameraturn; // 참이냐 거짓이냐 체크로 카메라뷰를 바꾸자