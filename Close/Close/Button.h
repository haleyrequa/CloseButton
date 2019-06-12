#pragma once


#include <GL/glut.h> 
#include <GL/gl.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream> 
#include "Point.h"
#include <cmath>
#include <string.h>

class Button
{
private:
	float colorActive[3] = { 0.1675f, 0.2019f, 0.25f };
	float colorPressed[3] = { 0.187f, 0.2508f, 0.34f }; 

	float color[3];
	float top,
		bottom,
		left,
		right;

	void Execute();
	bool IsPointOnButton(Point point);
	void Animate();
	void SetColor(float r, float g, float b);
	void SetColor(float color[3]);

public :

	Button(float top,
		float bottom,
		float left,
		float right);
	~Button();
	void Down(Point p);
	void Up(Point p);
	void Draw();
	void Text(float x, float y, char* text);
};


