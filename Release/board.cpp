#include"myhead.h"



void glkeyboard(unsigned char bkey, int x, int y)
{
	switch (bkey)
	{
	case 'i':
	case 'I':
	{
		pointnum = 0;
	}
		break;
	case 'q':
	case 'Q':
		exit(1);
		break;
	case 's':
	case 'S':
		break;
	case 'w':
	case 'W':
		if ((rolling > 1.085 && rolling < 2.075) || (rolling < -3.925 && rolling > -5.495))
		{
			if (lebber == false)
			{
				lebber = true;
				gasfull = true;
				lebberuptimer = 300;
			}
		}
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
		alphago = 1;
		break;
	case '[':
	case '}':
		alphago = 0;
		break;
	case 'a':
	case 'A':
		break;
	case '1':
		cameraview = true;
		right = false;
		break;
	case '2':
		cameraview = false;
		right = false;
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
		xmove -= 3.0f;
		break;
	case GLUT_KEY_RIGHT:
		xmove += 3.0f;
		break;
	case GLUT_KEY_UP:
		ymove += 3.0f;
		break;
	case GLUT_KEY_DOWN:
		ymove -= 3.0f;
		break;
	}
}