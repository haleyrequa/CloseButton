#pragma once

#include <windows.h>
#include <string.h>
#include <GL/glut.h> 
#include <math.h>
#include <cstdlib>
#include "Button.h"
#include "Point.h"


Button button = Button(-0.6f, 0.6f, 0.9f, 0.99f);

void display();
void RemoveHeader();
void MouseFunction(int button, int state, int x, int y);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	glutInit(&__argc, __argv);             // Initialize GLUT
	glutInitWindowSize(desktop.right, 50);   // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutCreateWindow("Close"); // Create a window with the given title

	RemoveHeader();
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMouseFunc(MouseFunction);
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;
}

void display() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	button.Draw();
	button.Text(0.0f, 0.0f, (char*)"close");

	glFlush();  // Render now
}

void RemoveHeader() {
	HWND hWnd = FindWindow(NULL, "Close");
	if (hWnd)
	{
		LONG lStyle = GetWindowLong(hWnd, GWL_STYLE);
		SetWindowLong(
			hWnd,
			GWL_STYLE,
			lStyle & WS_VISIBLE
		);

		SetWindowPos(
			hWnd, 
			HWND_TOPMOST, 
			0, 
			0, 
			glutGet(GLUT_WINDOW_WIDTH), 
			glutGet(GLUT_WINDOW_HEIGHT),
			SWP_NOOWNERZORDER);
	}
}

void MouseFunction(int b, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		button.Down(Point{(float)x, (float)y});
		display();
	}
	else if (state == GLUT_UP) {
		button.Up(Point{ (float)x, (float)y });
		display();
	}
}
