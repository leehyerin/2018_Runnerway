#include "stdafx.h"

extern Ball ball;
extern Camera camera;
extern int scenenum;

inline void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p':		// test
		if (camera.GetLorB())
			camera.SetLorB(false);
		else
			camera.SetLorB(true);
		break;

	case 'l':		// test
		scenenum++;

		if (scenenum == 4)
			scenenum = 0;

		break;

	case VK_ESCAPE: case 'Q': case 'q':
		::PostQuitMessage(0);
		break;

	default:
		break;
	}
}

inline void SpecialKeyboard(int key, int x, int y)
{
	int mod = glutGetModifiers();

	if (mod == GLUT_ACTIVE_CTRL)
	{
		ball.SetIsJump(true);
	}

	if (camera.GetLorB())
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
		{
			ball.SetRotX(ball.GetRotX() - 3);
			ball.SetPosX(ball.GetRotX() - 1 * PI * ball.GetRadius() / 360);
		}
		break;

		case GLUT_KEY_RIGHT:
		{
			ball.SetRotX(ball.GetRotX() + 3);
			ball.SetPosX(ball.GetRotX() + 1 * PI * ball.GetRadius() / 360);
		}
		break;

		default:
			break;
		}
	}
}