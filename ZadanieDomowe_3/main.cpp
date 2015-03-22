#include <iostream>

#include <GL/freeglut.h>

const int glutWindowWidth = 640;
const int glutWindowHeight = 480;
float poruszanieX[3] = { 0, 0.8, -0.8 };			//os x figur
float poruszanieY[3] = { 0, 0, 0 };			//os y figur
int numer = 0;				//liczba odpowiadajaca figurze
int kolor = 0;				//kolor figury

int zastapienie[3] = { 0, 0, 0 };
float proportion = (float)glutWindowWidth / (float)glutWindowHeight;

/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'e')			//obsluga klawiatury
	{
		numer++;
		if (numer > 2)
		{
			numer = 0;
		}
	}
	if (key == 'q')
	{
		numer--;
		if (numer < 0)
		{
			numer = 2;
		}
	}
	if (key == 'w')
	{
		poruszanieY[numer] += 0.1;

	}
	else if (key == 's')
	{
		poruszanieY[numer] -= 0.1;
	}
	if (key == 'd')
	{
		poruszanieX[numer] += 0.1;
	}
	else if (key == 'a')
	{
		poruszanieX[numer] -= 0.1;
	}

	if (key == 'i')
	{
		zastapienie[numer] = 0;
	}
	if (key == 'o')
	{
		zastapienie[numer] = 1;
	}
	else if (key == 'p')
	{
		zastapienie[numer] = 2;
	}
}

void DrawRectangle(int n, float x,float y)			//rysowanie kwadratu
{
	float height = 0.5;
	float width = 0.5;

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	//glRotated(0, 1.0, 0.0, 0.0);
	//glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0.0, 0.0, 0.0, 1.0);

	glTranslated(poruszanieX[n]+x, poruszanieY[n]+y, 0);

	if (numer == n)			//kolory jakie moze przyjmowac kwadrat
	{
		if (kolor == 0)
		{

			glColor3d(1.0, 0.0, 0.0);
		}
		else if (kolor == 1)
		{
			glColor3d(0.0, 1.0, 0.0);
		}
		else
		{
			glColor3d(0.0, 0.0, 1.0);
		}
	}
	else
	{
		glColor3d(0.0, 0.0, 0.0);
	}
	glBegin(GL_POLYGON);
	{
		glVertex3d(-width / 2, height / 2, 0);
		glVertex3d(width / 2, height / 2, 0);
		glVertex3d(width / 2, -height / 2, 0);
		glVertex3d(-width / 2, -height / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

void DrawCircle(int n,float xc,float yc)		//rysowanie kola
{
	float r = 0.25;

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	//glRotated(0, 1.0, 0.0, 0.0);
	//glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0.0, 0.0, 0.0, 1.0);

	glTranslated(poruszanieX[n]+xc, poruszanieY[n]+yc, 0);

	if (numer == n)				//kolory jakie moze przyjmowac kolo
	{
		if (kolor == 0)
		{

			glColor3d(1.0, 0.0, 0.0);
		}
		else if (kolor == 1)
		{
			glColor3d(0.0, 1.0, 0.0);
		}
		else
		{
			glColor3d(0.0, 0.0, 1.0);
		}
	}
	else
	{
		glColor3d(0.0, 0.0, 0.0);
	}

	float d;

	glBegin(GL_POLYGON);
	{

		for (int i = 0; i < 360; i += 1)
		{
			d = (i / 180.0) * 3.14;
			glVertex3d(r*cos(d), r*sin(d), 0);


		}
	}
	glEnd();
	glPopMatrix();
}

void DrawHexagon(int n, float xs, float ys)		//rysowanie szesciokata
{
	float r = 0.25;

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	//glRotated(0, 1.0, 0.0, 0.0);
	//glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0.0, 0.0, 0.0, 1.0);

	glTranslated(poruszanieX[n] + xs, poruszanieY[n] + ys, 0);

	if (numer == n)		//kolory jakie moze przyjmowac szesciokat
	{
		if (kolor == 0)
		{

			glColor3d(1.0, 0.0, 0.0);
		}
		else if (kolor == 1)
		{
			glColor3d(0.0, 1.0, 0.0);
		}
		else
		{
			glColor3d(0.0, 0.0, 1.0);
		}
	}
	else
	{
		glColor3d(0.0, 0.0, 0.0);
	}

	float d;

	glBegin(GL_POLYGON);
	{

		for (int i = 0; i < 360; i += 60)
		{
			d = (i / 180.0) * 3.14;
			glVertex3d(r*cos(d), r*sin(d), 0);


		}
	}
	glEnd();
	glPopMatrix();
}

static void display(void)		//wyswietlenie
{
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glPushMatrix();
	
	for (int i = 0; i < 3; i++)		//zmiana figur
	{

		if (zastapienie[i] == 0)
		{

			DrawRectangle(i, 0, 0);
		}
		else if (zastapienie[i] == 1)
		{
			DrawCircle(i, 0, 0);
		}
		else if (zastapienie[i] == 2)
		{
			DrawHexagon(i, 0, 0);

		}

	}

	

	glutSwapBuffers();
}

void Change_color(int v)		//mruganie
{
	kolor++;
	if (kolor > 2)
	{
		kolor = 0;
	}
	glutTimerFunc(500, Change_color, 0);
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	//printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// set white as clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutKeyboardFunc(Keyboard);
	glutTimerFunc(500, Change_color, 0);
	glutMainLoop();

	return 0;
}