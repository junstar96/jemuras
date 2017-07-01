#include"myhead.h"



void glkeyboard(unsigned char bkey, int x, int y)
{
	switch (bkey)
	{
	case 'i':
	case 'I':
		break;
	case 'q':
	case 'Q':
		setreset();//초기화하는 버튼
		break;
	case 's':
	case 'S':
		if (cameraturn)
		{
			cameraturn = false;
		}
		else
		{
			cameraturn = true;
		}
		break;
	case 'w':
	case 'W':
		break;
	case 'x':
	case 'X':
		break;
	case 'y':
	case 'Y':
		break;
	case 'z':
	case 'Z':
		break;
	case 'e':
	case 'E':
		break;
	case ']':
	case '{':
		break;
	case '[':
	case '}':
		break;
	case 'a':
	case 'A':
		break;
	case '1':
		speen[2] += 0.2f;
		break;
	case '2':
		speen[2] -= 0.2f;
		break;
	case '3':
		
		break;
	case '4':
		break;
	}

}

void boardvecter(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		xmove -= 5.0f;
		break;
	case GLUT_KEY_RIGHT:
		xmove += 5.0f;
		break;
	case GLUT_KEY_UP:
		zmove += 5.0f;
		break;
	case GLUT_KEY_DOWN:
		zmove -= 5.0f;
		break;
	}
	cout <<"xmove :" << xmove << "," <<"zmove :"<<zmove << endl;
}