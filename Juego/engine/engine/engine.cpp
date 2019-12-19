#include <iostream>
#include <GL/glut.h>
#include <string>
#include "Game.h"

using namespace std;

///////////////////////////////////////// VARIABLES GLOBALES ////////////////////////////////////////////

char title[] = "Motor con POO";								// TÃ­tulo de la ventana
int windowWidth = 640;												// Ancho inicial de la ventana
int windowHeight = 480;												// Alto inicial de la ventana
int windowPositionX = 300;											// PosiciÃ³n X de la esquina superior izquierda
int windowPositionY = 200;											// PosiciÃ³n Y de la esquina superior izquierda

bool fullScreenMode = false;										// Modo ventana o modo pantalla completa

/////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////// FUNCIONES AUXILIARES///////////////////////////////////////////

void writeLine(string text)
{
	std::cout << text << "\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////// CAMBIANDO COSAS... //////////////////////////////////////////

Game theGame {};

void initObjects()
{
	theGame.Create();
}

void drawObjects()
{
	theGame.Render();
}

void update()
{
	theGame.Update();
}

void processMouseMovement(int x, int y)
{
	theGame.ProcessMouseMovement(x, y);
}

void processKeyPressed(unsigned char key, int px, int py)
{
	theGame.ProcessKeyPressed(key, px, py);
}

void processMouseClick(int button, int state, int x, int y)
{
	theGame.ProcessMouseClick(button, state, x, y);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////// FUNCIONES OPENGL //////////////////////////////////////////////

void idle(void)
{
	update();
	glutPostRedisplay();   // Post a re-paint request to activate display()
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
	glLoadIdentity();                // Reset the model-view matrix

	drawObjects();

	glutSwapBuffers();

}

void mouseMoved(int x, int y)
{
	processMouseMovement(x, y);
	glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y)
{
	processMouseClick(button, state, x, y);
}

void keyPressed(unsigned char key, int px, int py) {
	processKeyPressed(key, px, py);
	glutPostRedisplay();											//repintado en cuanto se pueda
}

void specialKeys(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_F11:												// F11: activa/desactiva el modo pantalla completa
		fullScreenMode = !fullScreenMode;							// Cambio de estado
		if (fullScreenMode)											// Modo pantalla completa
		{
			windowPositionX = glutGet(GLUT_WINDOW_X);				// Se guarda la posiciÃ³n para restaurarla posteriormente
			windowPositionY = glutGet(GLUT_WINDOW_Y);
			windowWidth = glutGet(GLUT_WINDOW_WIDTH);
			windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
			glutFullScreen();										// Paso a pantalla completa
		}
		else														// Modo ventana
		{
			glutReshapeWindow(windowWidth, windowHeight);			// Paso a modo ventana
			glutPositionWindow(windowPositionX, windowPositionY);   // PosiciÃ³n de la ventana
		}
		break;
	}
}

void initGraphics()
{
	glEnable(GL_DEPTH_TEST);										// Uso de depth buffer
	glEnable(GL_LIGHTING);											// CÃ¡lculo de colores de los vÃ©rtices conforme a parÃ¡metros de iluminaciÃ³n
	glEnable(GL_LIGHT0);											// Uso de luz 0 para cÃ¡lculo de iluminaciÃ³n
	glEnable(GL_COLOR_MATERIAL);									// ParÃ¡metros de material aplicables al color
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);							// Fija el color de fondo 
	initObjects();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;									// Para evitar dividir entre 0
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;			// CÃ¡lculo de la relaciÃ³n de aspecto de la nueva ventaÃ±a
	glViewport(0, 0, width, height);								// Set the viewport to cover the new window
	glMatrixMode(GL_PROJECTION);									// To operate on the Projection matrix
	glLoadIdentity();												// Reset the projection matrix
	gluPerspective(60.0f, aspectRatio, 1.0f, 200.0f);				// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_MODELVIEW);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////// MAIN //////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	writeLine("Inicio del motor...");

	writeLine("Generando ventana...");
	glutInit(&argc, argv);											// Inicializa GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);		// doble bÃºfer, modo RGBA, depth buffer
	glutInitWindowSize(windowWidth, windowHeight);					// Fija el tamaÃ±o inicial de la ventana (ancho y alto)
	glutInitWindowPosition(windowPositionX, windowPositionY);		// PosiciÃ³n inicial de la ventana (esquina superior izquierda)
	glutCreateWindow(title);										// Crea una ventana con el tÃ­tulo dado

	writeLine("Registrando funciones de tratamiento de eventos...");
	glutReshapeFunc(reshape);										// Register la funciÃ³n a ejecutar con el evento de redimensionado de la ventana
	glutDisplayFunc(display);										// Registra la funciÃ³n a ejecutar con el evento de repintado de la ventana
	glutKeyboardFunc(keyPressed);									// Registra la funciÃ³n a ejecutar con el evento de tecla pulsada
	glutSpecialFunc(specialKeys);									// Registra la funciÃ³n a ejecutar con el evento de tecla especial pulsada
	glutMotionFunc(mouseMoved);										// Registra la funciÃ³n a ejecutar con el evento de movimiento del ratÃ³n
	glutMouseFunc(mouseClicked);									// Registra la funciÃ³n a ejecutar con el evento de clic del ratÃ³n
	glutIdleFunc(idle);												// Registra la funciÃ³n a ejecutar cuando no se tiene que atender ningÃºn evento

	writeLine("Iniciando grÃ¡ficos...");
	initGraphics();													// InicializaciÃ³n de OpenGL

	writeLine("Iniciando bucle infinito...");
	writeLine("Pulsa F11 para activar/desactivar el modo pantalla completa");
	glutMainLoop();													// Entra en el bucle infinito de tratamiento de eventos

	return 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////