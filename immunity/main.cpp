#include <iostream>
#include "glut.h"

int W_WIDTH = 1024, W_HEIGHT = 768; // ������ � ������ ����

using namespace std;

void idle() // �������� 
{
	glutPostRedisplay(); // ������ ��� �������������� �����, ���� ���� ��� ���������
}

void display() // ��������� �� �����
{
	glMatrixMode(GL_MODELVIEW); // �� �������
	glLoadIdentity();           //
	glClearColor(0, 0, 0, 0); // ����� ���� ������� ���� (������)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������� ��� ������ 
	gluPerspective(60, W_WIDTH / W_HEIGHT, 1, 100); // ����� �����
	glRotated(90, 0, 1, 0); // ������������ ������ �� ��� � (�� ��������� ������� �� -z)
	glViewport(0, 0, W_WIDTH, W_HEIGHT); // ������, ��� ����������� � ������ ����������� � ����
	glEnable(GL_DEPTH_TEST); // �������� �������

	// ��� �������� ������, ����� � ��������� ������ ������
	glColor3d(1, 0, 1); // ������ ���� (0-1 RGB)
	glPushMatrix(); // 
	glTranslated(10, 0, 0); // ����������, ��� ����� ����������
	glutSolidCube(1); // � ������ ������ ������ ��� � �������� ������� 1
	glPopMatrix(); // 


	glFlush();         // ������� �� �� �����
	glutSwapBuffers(); //
}

void keyboard(unsigned char key, int x, int y) // ���������� ��� ������� ������ ����������
{
	cout << "������ �������: " << key << endl; // ������ �������������
}

void mouse(int button, int state, int x, int y) // ���������� ��� ������� ������ ����
{
	if (state == GLUT_DOWN) // ���� �� ������ ������
	{
		cout << "���� ������: X: " << x << ", Y: " << y << endl; // ������ �������������
	}
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "RUS"); // �������� ������� ���� � �������
	glutInit(&argc, argv);                                     //
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // ��������� ������������� OpenGL
	glutInitWindowSize(W_WIDTH, W_HEIGHT); // ������ ������ � ������ ����
	glutInitWindowPosition(0, 0); // ������ ������� ����
	glutCreateWindow("��������� - ����� ����� �������� �� ������ ������� ���!"); // ������� ����
	glutIdleFunc(idle);         //
	glutDisplayFunc(display);   // ���������� ������� ��� �������
	glutKeyboardFunc(keyboard); //
	glutMouseFunc(mouse);       //

	glutMainLoop(); // ��������� OpenGL
	return 0;
}