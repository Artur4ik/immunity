#include <iostream>
#include "glut.h"

int W_WIDTH = 1024, W_HEIGHT = 768; // Ширина и высота окна

using namespace std;

void idle() // Ожидание 
{
	glutPostRedisplay(); // Каждый раз перерисовываем сцену, даже если нет изменений
}

void display() // Рисование на сцене
{
	glMatrixMode(GL_MODELVIEW); // Не трогать
	glLoadIdentity();           //
	glClearColor(0, 0, 0, 0); // Задаём цвет очистки окна (черный)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищаем все буферы 
	gluPerspective(60, W_WIDTH / W_HEIGHT, 1, 100); // Задаём обзор
	glRotated(90, 0, 1, 0); // Поворачиваем камеру на ось х (по умолчанию смотрит на -z)
	glViewport(0, 0, W_WIDTH, W_HEIGHT); // Задаем, как изображение с камеры переносится в окно
	glEnable(GL_DEPTH_TEST); // Включаем глубину

	// Как рисовать кубики, круги и некоторые другие фигуры
	glColor3d(1, 0, 1); // Задаем цвет (0-1 RGB)
	glPushMatrix(); // 
	glTranslated(10, 0, 0); // Координаты, где хотим нарисовать
	glutSolidCube(1); // В данном случае рисуем куб с размером стороны 1
	glPopMatrix(); // 


	glFlush();         // Выводим всё на экран
	glutSwapBuffers(); //
}

void keyboard(unsigned char key, int x, int y) // Вызывается при нажатии кнопки клавиатуры
{
	cout << "Нажата клавиша: " << key << endl; // Пример использования
}

void mouse(int button, int state, int x, int y) // Вызывается при нажатии кнопки мыши
{
	if (state == GLUT_DOWN) // Если мы зажали кнопку
	{
		cout << "Клик мышкой: X: " << x << ", Y: " << y << endl; // Пример использования
	}
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "RUS"); // Загрузка русских букв в консоль
	glutInit(&argc, argv);                                     //
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Начальная инициализация OpenGL
	glutInitWindowSize(W_WIDTH, W_HEIGHT); // Задаем ширину и высоту окна
	glutInitWindowPosition(0, 0); // Задаем позицию окна
	glutCreateWindow("Иммунитет - спаси своей организм от мелких дерзких йоб!"); // Создаем окно
	glutIdleFunc(idle);         //
	glutDisplayFunc(display);   // Подключаем функции для событий
	glutKeyboardFunc(keyboard); //
	glutMouseFunc(mouse);       //

	glutMainLoop(); // Запускаем OpenGL
	return 0;
}