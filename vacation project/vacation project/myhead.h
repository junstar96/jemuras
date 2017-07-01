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
	string name;//�̸�
	int hp;//ü��, �� �޸� ����
	int atp;//���ݷ�, ���� ��ġ�� ���� ����(rand()%10~15 ����, �̰� �� ���� ����)
public:
	character() : hp(0), atp(0), name("clear"){} //�ʱ� ����
	
	void gethp(int HP) { hp = HP; }; //�̰��� ü�°��� �޴� ���Դϴ�.
	void settingatp(int ATP) { atp = ATP; };//���ݰ��� ���� ���� ���� ��
	virtual void upgrateATP() = 0;//���׷��̵� ���� ���� ���ݷ¿� ��ȭ�� ���� ��

	virtual void characterkeymove() = 0; //Ű�� ���� ������ �Ѵٰ� ���� �� ������ ��

	
};



void RenderScene(void);//�̹��� ��¿�
void ChangeSize(int w, int h);//ũ�Ⱑ �ٲ���� ���� ���� ��
void glkeyboard(unsigned char bkey, int x, int y);//Ű���� ��ư�� �˷���
void mouseboard(int button, int status, int x, int y);//���콺 Ŭ��
void gltimer(int value);//Ÿ�̸�
void mainmenu(int button);//�޴�â�� �˷���
void donmouse(int x, int y);//���콺�� �ƹ��� �ϵ� ���� ���� �� ����
void movemouse(int x, int y);//���콺�� ������ �� ����
void setreset();//�� ��Ȳ�� �ʱ�� �ǵ��������� �Լ�

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);//�̹����� �޾ƿ��� �Լ�, ���� �� ���� �ִ� ��

void boardvecter(int key, int x, int y);//���忡 �����ϰ� �ִ� ����, ȭ��ǥ���� �ǵ��.




extern int w, h;  //ȭ���� ���̰�
extern float xmove, ymove, zmove;//������ �����̴� ���̴�.
extern float speen[3];//������� xyz ȸ���� ���콺�� �Ѵ�. 

extern float mousex, mousey;//���콺�� ���� ��Ұ��� �Է��ϴ� ��





extern GLfloat AmbientLight[8][4];//�ں��Ʈ��
extern GLfloat DiffuseLight[8][4];//��ǻ�
extern GLfloat SpecularLight[8][4];//����ŧ����
extern GLfloat lightPos[8][4];//���� ��ġ


extern bool cameraturn; // ���̳� �����̳� üũ�� ī�޶�並 �ٲ���