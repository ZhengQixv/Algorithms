#include "GL/glut.h"    
#include <stdio.h>    
#include <Windows.h>    
#include <stdlib.h>    
#include <math.h>

GLfloat ctrlPoints[4][4][3] =
{
	{
		{ -0.8f, -0.7f, 0.2f }, { -0.3f, -0.6f, 0.2f }, { 0.2f, -0.65f, 0.3f }, { 0.7f, -0.7f, 0.2f }
	},
	{
		{ -0.9f, -0.2f, 0.3f }, { -0.3f, -0.6f, 0.2f }, { 0.3f, -0.2f, 0.4f },	{ 0.75f, -0.2f, 0.3f },
	},
	{
		{ -0.9f, 0.3f, 0.3f }, { -0.3f, 0.2f, 0.5f }, { 0.25f, 0.25f, 0.6f },	{ 0.8f, 0.3f, 0.3f },
	},
	{
		{ -0.8f, 0.8f, 0.1f }, { -0.3f, 0.8f, 0.2f }, { 0.2f, 0.85f, 0.1f },	{ 0.7f, 0.8f, 0.1f },
	}
};





void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(-65.0, 1.0, 0.3, 0.2);


	GLfloat ps[11][4][3];
	for (int j = 0; j < 4; j++) {
		GLint i = 0;
		for (double t = 0.0; t <= 1.0; t += 0.1)
		{

			double a1 = pow((1 - t), 3);
			double a2 = pow((1 - t), 2) * 3 * t;
			double a3 = 3 * t*t*(1 - t);
			double a4 = t * t*t;
			ps[i][j][0] = a1 * ctrlPoints[0][j][0] + a2 * ctrlPoints[1][j][0] + a3 * ctrlPoints[2][j][0] + a4 * ctrlPoints[3][j][0];
			ps[i][j][1] = a1 * ctrlPoints[0][j][1] + a2 * ctrlPoints[1][j][1] + a3 * ctrlPoints[2][j][1] + a4 * ctrlPoints[3][j][1];
			ps[i][j][2] = a1 * ctrlPoints[0][j][2] + a2 * ctrlPoints[1][j][2] + a3 * ctrlPoints[2][j][2] + a4 * ctrlPoints[3][j][2];
			i = i + 1;
		}
	}


	GLfloat ps1[11][11][3];
	for (int j = 0; j < 11; j++) {
		GLint i = 0;
		for (double t = 0.0; t <= 1.0; t += 0.1)
		{
			double a1 = pow((1 - t), 3);
			double a2 = pow((1 - t), 2) * 3 * t;
			double a3 = 3 * t*t*(1 - t);
			double a4 = t * t*t;
			ps1[j][i][0] = a1 * ps[j][0][0] + a2 * ps[j][1][0] + a3 * ps[j][2][0] + a4 * ps[j][3][0];
			ps1[j][i][1] = a1 * ps[j][0][1] + a2 * ps[j][1][1] + a3 * ps[j][2][1] + a4 * ps[j][3][1];
			ps1[j][i][2] = a1 * ps[j][0][2] + a2 * ps[j][1][2] + a3 * ps[j][2][2] + a4 * ps[j][3][2];
			i = i + 1;
		}
	}


	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 11; i++) {
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 11; j++)
			glVertex3fv(&ps1[i][j][0]);
		glEnd();

		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 11; j++)
			glVertex3fv(&ps1[j][i][0]);
		glEnd();
	}


	/* The following code displays the control points as dots. */
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);

	for (int i = 0; i < 4; i++) {
		glBegin(GL_POINTS);
		for (int j = 0; j < 4; j++)
			glVertex3fv(&ctrlPoints[i][j][0]);
		glEnd();
	}


	glColor3f(0.0, 1.0, 1.0);
	for (int i = 0; i < 4; i++) {
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 4; j++)
			glVertex3fv(&ctrlPoints[i][j][0]);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 4; j++)
			glVertex3fv(&ctrlPoints[j][i][0]);
		glEnd();
	}

	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("opengl1");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}