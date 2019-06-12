#include "Button.h"

void Button::Execute()
{
	WinExec("C:\\DigExhibits\\TouchTableAppLauncherMain\\TouchTableAppKiller\\TouchTableAppKiller.bat", SW_HIDE);
}

bool Button::IsPointOnButton(Point point)
{

	int windowWidth = glutGet(GLUT_WINDOW_WIDTH),
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

	Point percentOfClick = {
		point.x / windowWidth,
		point.y / windowHeight
	};

	Point MinPercent = {
		(left + 1.0f) / 2.0f,
		(top + 1.0f) / 2.0f
	};

	Point MaxPercent = {
		(right + 1.0f) / 2.0f,
		(bottom + 1.0f) / 2.0f
	};

	if (percentOfClick >= MinPercent &&
		percentOfClick <= MaxPercent)
		return true;

	return false;
}

Button::Button(float _top,
	float _bottom,
	float _left,
	float _right)
{
	top = _top;
	bottom = _bottom;
	left = _left;
	right = _right;
	SetColor(colorActive);
}

Button::~Button()
{
}

void Button::Down(Point point)
{
	if(IsPointOnButton(point))
		SetColor(colorPressed);
}

void Button::Up(Point point)
{
	if (IsPointOnButton(point)) {
		Execute();
		//SetColor(colorActive);
	}
	else {
		SetColor(colorActive);
	}
}

void Button::Draw()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);   
	glColor3f(
		color[0],
		color[1], 
		color[2]); 
	
	glVertex2f(left, top);
	glVertex2f(right, top);
	glVertex2f(right, bottom);
	glVertex2f(left, bottom);
	glEnd();
	glFlush();

}

void Button::Text(float x, float y, char* text)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.6f, 0.6f, 0.6f);
	glRasterPos2f(.92, -.2);
	glEnable(GL_BLEND);
	const char* p = text;
	do glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12 , toupper(*p)); while (*(++p));


	glMatrixMode(GL_PROJECTION);
	glPopMatrix(); 
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void Button::Animate() {
	float difference[3] = {
		colorActive[0] - colorPressed[0],
		colorActive[1] - colorPressed[1],
		colorActive[2] - colorPressed[2]
	};
	for (int i = 0; i <= 1000; i++) {
		float n0 = ((float)i / 100);
		float n1 = (difference[1] * n0);
		float number = colorPressed[1] + n1;
		SetColor(
			colorPressed[0] + (difference[0] * ((float)i / 100)),
			colorPressed[1] + (difference[1] * ((float)i / 100)),
			colorPressed[2] + (difference[2] * ((float)i / 100)));
	}
}

void Button::SetColor(float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
	Draw();
}

void Button::SetColor(float newColor[3]) {
	color[0] = newColor[0];
	color[1] = newColor[1];
	color[2] = newColor[2];
	Draw();
}


