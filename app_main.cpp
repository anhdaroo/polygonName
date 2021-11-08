#include <iostream>
#include <cmath>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif




// Store the width and height of the window
int width = 640, height = 640;


//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    

    // Draw stuff here

    
    //A
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(-.95, -.5, 0);
    glVertex3f(-.65, .5, 0);
    glVertex3f(-.6, .5, 0);
    glVertex3f(-.9, -.5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(-.6, .5, 0);
    glVertex3f(-.3, -.5, 0);
    glVertex3f(-.35, -.5, 0);
    glVertex3f(-.65, .5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(-.73, .05, 0);
    glVertex3f(-.8, 0, 0);
    glVertex3f(-.45, 0, 0);
    glVertex3f(-.48, .05, 0);
    glEnd();

    //N
    glBegin(GL_POLYGON);
    
    glColor3f(1,1,1);
    glVertex3f(.4, .5, 0);
    glVertex3f(.4, -.5, 0);
    glVertex3f(.45, -.5, 0);
    glVertex3f(.45, .5, 0);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glColor3f(1,1,1);
    glVertex3f(.9, .5, 0);
    glVertex3f(.9, -.5, 0);
    glVertex3f(.95, -.5, 0);
    glVertex3f(.95, .5, 0);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glColor3f(1,1,1);
    glVertex3f(.45, .5, 0);
    glVertex3f(.95, -.5, 0);///////////////////
    glVertex3f(.9, -.5, 0);
    glVertex3f(.4, .5, 0);
    
    glEnd();
    //End
    
    //N
    glBegin(GL_POLYGON);
    
    glColor3f(1,1,0);
    glVertex3f(1.75, .5, 0);
    glVertex3f(1.75, -.5, 0);
    glVertex3f(1.80, -.5, 0);
    glVertex3f(1.80, .5, 0);
    
    glEnd();
    

    glBegin(GL_POLYGON);

    glColor3f(1,1,0);
    glVertex3f(2.25, .5, 0);
    glVertex3f(2.25, -.5, 0);
    glVertex3f(2.3, -.5, 0);
    glVertex3f(2.3, .5, 0);

    glEnd();
    
    glBegin(GL_POLYGON);
    
    glColor3f(1,1,0);
    glVertex3f(1.8, .5, 0);
    glVertex3f(2.3, -.5, 0);
    glVertex3f(2.25, -.5, 0);
    glVertex3f(1.75, .5, 0);
    
    glEnd();

    

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -4.0;
	const double appXmax = 4.0;
	const double appYmin = -4.0;
	const double appYmax = 4.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks


	// Start the main loop
	glutMainLoop();
}
