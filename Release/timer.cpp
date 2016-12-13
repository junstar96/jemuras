#include"myhead.h"

void anorderpoint()
{
	if (lebber)
	{
		if (speed <= 2.5 && speed >= -2.5)
		{
			speed -= gas;
		}
		else if (speed > 2.5)
		{
			speed = 2.5;
		}
		else if (speed < -2.5)
		{
			speed = -2.5;
		}
	}
	else if (!lebber)
	{
		if (speed <= 2.5 && speed >= -2.5)
		{
			speed += gas;
		}
		else if (speed > 2.5)
		{
			speed = 2.5;
		}
		else if (speed < -2.5)
		{
			speed = -2.5;
		}
	}

	
	life += speed;

	if (!gasfull)
	{
		if (gas > -1.57)
		{
			gas -= 0.002;
		}
		
	}
	else
	{
		if (gas < 1.57)
		{
			gas += 0.002;
		}
	}
	if (life < 0)
	{
		exit(1);
	}

	if (life > 10000)
	{
		exit(1);
	}

	if (gas < -1.57)
	{
		exit(1);
	}

	if (gas > 1.57)
	{
		exit(1);
	}
}

void gltimer(int value)
{
	static int weatherchange = 0;
	static float starmove = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (lineup[i][j] == false)
			{
				line[i][j][1] -= 1.0f;
				if (line[i][j][1] < -mywline / 4)
				{
					lineup[i][j] = true;
				}
			}
			else if (lineup[i][j] == true)
			{
				line[i][j][1] += 1.0f;
				if (line[i][j][1] > mywline / 4)
				{
					lineup[i][j] = false;
				}

			}
		}
	}

	for (int i = 0; i < 1000; ++i)
	{
		if (snow[i][2] < 0)
		{
			for (int j = 0; j < 2; ++j)
			{
				snow[i][j] = rand() % (int)mywline - mywline / 2;
			}
			snow[i][2] = rand() % 120 + mywline / 2;
		}
		else
		{
			snow[i][2] -= 1.0f;
		}
	}

	lightPos[0][0] = xmove;
	lightPos[0][1] = ymove - mywline;
	lightPos[0][2] = zmove + 100;

	lightPos[1][0] = xmove + mywline*3;
	lightPos[1][1] = ymove - mywline / 2;
	lightPos[1][2] = zmove + 10000;

	

	if (weatherchange > 1200)
	{
		weatherchange = 0;
		weather = (weather + 1)%4;
	}
	else
	{
		weatherchange += 1;
	}


	if (mousecameramove == true)
	{
		if (mousex > 0)
		{
			rolling += 0.03;
			if (rolling > 6.27 && rolling <= 6.29)
			{
				rolling = 0.0;
			}
		}
		else
		{
			rolling -= 0.03;
			if (rolling < -6.27 && rolling >= -6.29)
			{
				rolling = 0.0;
			}
		}
	}

	//cout << rolling << endl;

	if (trainnum < 90)
	{
		if (trainmove < 0.99)
		{
			trainmove += 0.01 + (speed + 2.5)/300.0f;
		}
		else if (trainmove >= 0.99)
		{
			trainmove = 0;
			trainnum += 1;
		}
	}
	else if (trainnum >= 90)
	{
		exit(1);
	}
	
	xmove = ((1 - trainmove))*trainreil[trainnum][0] + trainmove*trainreil[trainnum + 1][0];
	ymove = ((1 - trainmove))*trainreil[trainnum][1] + trainmove*trainreil[trainnum + 1][1];
	zmove = ((1 - trainmove))*trainreil[trainnum][2] + (trainmove)*trainreil[trainnum + 1][2] + mywline/2 + mywline / 4;

	

	for (int i = 0; i < 1000; ++i)
	{
		switch (i % 2)
		{
		case 0:
			if (star[i][0] > 3.14)
			{
				star[i][0] = 0.0;
			}
			else
			{
				star[i][0] += 0.001;
			}

			if (star[i][1] > 3.14)
			{
				star[i][1] = 0.0;
			}
			else
			{
				star[i][1] += 0.001;
			}

			break;
		case 1:
			if (star[i][0] < -3.14)
			{
				star[i][0] = 0.0;
			}
			else
			{
				star[i][0] -= 0.001;
			}

			if (star[i][1] < -3.14)
			{
				star[i][1] = 0.0;
			}
			else
			{
				star[i][1] -= 0.001;
			}


			break;
		}
	}

	if (lebberuptimer <= 0)
	{
		lebber = false;
		gasfull = false;
		lebberuptimer = 0;
	}
	else if (lebberuptimer > 0)
	{
		lebberuptimer -= 1;
	}

	anorderpoint();

	AmbientLight[1][0] = 0.3 - 0.05*weather;
	AmbientLight[1][1] = 0.3 - 0.05*weather;
	AmbientLight[1][2] = 0.3 - 0.05*weather;

	

	
	glutTimerFunc(10, gltimer, 1);
	glutPostRedisplay();

	

	
}
