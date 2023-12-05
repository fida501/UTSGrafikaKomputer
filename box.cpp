/////////////////////////////////          
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cmath>
#include "getBMP.h"
#define M_PI 3.14159265358979323846264338327950288

// Variables for translation.
GLfloat translateX = 0.0;
GLfloat translateY = 0.0;
GLfloat objectRotation = 90.0f; // Initial rotation angle.
GLfloat rotationSpeed = 0.016f; // Adjust the rotation speed as needed.
GLuint textureID;

//Texture
static unsigned int texture[2]; // Array of texture ids.
static int id = 0;
// Load external textures.
void loadTextures()
{
	// Local storage for image data.
	imageFile* image[1];

	// Load the image.
	image[0] = getBMP("../../Textures/grass.bmp");

	// Create texture object texture[0]. 
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// Specify image data for currently active texture object.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);

	// Set texture parameters for wrapping.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture parameters for filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void loadTextures2()
{
	// Local storage for image data.
	imageFile* image[1];

	// Allocate memory for a 1x1 blue texture.
	unsigned char bluePixel[] = { 0, 0, 255, 255 };

	// Generate texture object texture[0].
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// Specify image data for the currently active texture object (1x1 blue pixel).
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, bluePixel);

	// Set texture parameters for wrapping.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture parameters for filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}


// Animation update routine.
void animate(void)
{
	// Update the rotation angle for animation.
	objectRotation += rotationSpeed;

	glutPostRedisplay(); // Request a redraw for the next frame.
}
// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menambahkan GL_DEPTH_BUFFER_BIT untuk depth testing.
	glLoadIdentity();

	// Modeling transformations.
	glTranslatef(translateX, translateY, -15.0);
	glRotatef(90.0f, 0.0, 0.0, 1.0); // Rotate about the z-axis.
	glRotatef(objectRotation, 1.0, 0.0, 0.0); // Rotate about the y-axis.

	// Set material properties for the cube.
	GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);

	// Create texture object texture[0]. 
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// Menggambar sisi-sisi kubus persegi panjang dengan warna-warni.
	//sglBegin(GL_QUADS);
	glBegin(GL_QUADS);

	// Front side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.5, 2.5, 5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.5, 2.5, 5.5);

	// Back side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.5, -2.5, -5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.5, -2.5, -5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.5, 2.5, -5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.5, 2.5, -5.5);

	// Right side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.5, -2.5, -5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.5, 2.5, -5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(5.5, 2.5, 5.5);

	// Left side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.5, -2.5, -5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(-5.5, 2.5, 5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.5, 2.5, -5.5);

	// Top side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.5, 2.5, 5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.5, 2.5, 5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.5, 2.5, -5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.5, 2.5, -5.5);

	// Bottom side
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.5, -2.5, 5.5);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.5, -2.5, -5.5);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.5, -2.5, -5.5);

	animate();
	glFlush();


	// Draw a circle in the middle of the front side.
	float centerX = 4.5;
	float centerY = 2.0;
	float radius = 0.2;
	int numSegments = 360;
	float angle;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < numSegments; i++) {
		angle = 2.0 * M_PI * i / numSegments;

		float x1 = centerX + radius * cos(angle);
		float y1 = centerY + radius * sin(angle);

		angle = 2.0 * M_PI * (i + 1) / numSegments;

		float x2 = centerX + radius * cos(angle);
		float y2 = centerY + radius * sin(angle);

		glVertex3f(centerX, centerY, 5.5); // Center of the circle
		glVertex3f(x1, y1, 5.5); // First point on the circumference
		glVertex3f(x2, y2, 5.5); // Second point on the circumference
	}
	glEnd();

	// Front (Red)
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(5.0, -0.0, 5.5);
	glVertex3f(4.0, -0.0, 5.5);
	glVertex3f(4.0, 0.5, 5.5);
	glVertex3f(5.0, 0.5, 5.5);
	glEnd();

	// Front (Blue)
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 1.3, 5.5);
	glVertex3f(4.0, 1.3, 5.5);
	glVertex3f(4.0, 0.8, 5.5);
	glVertex3f(5.0, 0.8, 5.5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	// Draw a simple wall in front of the rectangle.
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5); // Gray color for the wall.

	float zCoordinate = -7.0f;

	// Adjust the z-coordinate to be in front of the rectangle.
	glVertex3f(-10.0, -10.0, zCoordinate);   // Bottom-left corner
	glVertex3f(10.0, -10.0, zCoordinate);    // Bottom-right corner
	glVertex3f(10.0, 10.0, zCoordinate);     // Top-right corner
	glVertex3f(-10.0, 10.0, zCoordinate);    // Top-left corner
	glEnd();

	//DRAW LIGHT 

	glBindTexture(GL_TEXTURE_2D, 0);

	// Draw the light source (sphere) in front of the rectangle.
	glPushMatrix();
	glTranslatef(0.0, 0.0, 7.0); // Adjust the position of the sphere.
	glColor3f(1.0, 1.0, 0.0); // Set the color of the sphere.
	glutSolidSphere(0.3, 20, 20); // Draw a solid sphere.
	glPopMatrix();

	// Enable lighting for the light source.
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set up the position and properties of the light source.
	float lightPos[] = { 1.0, 1.0, 8.0, 1.0 }; // Position of the light in front of the rectangle.
	float lightAmb[] = { 0.2, 0.2, 0.2, 1.0 }; // Ambient light.
	float lightDiff[] = { 1.0, 1.0, 1.0, 1.0 }; // Diffuse light.
	float lightSpec[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular light.

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

	glutSwapBuffers();
}


// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// Create texture ids.
	glGenTextures(2, texture);

	// Load external texture.
 //   loadTextures();
	loadTextures2();
	// Set up texture environment parameters.
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// Enable texture mapping and depth testing.
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	//// Set up lighting.
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	//// Enable normalization of normals (important for proper lighting).
	//glEnable(GL_NORMALIZE);

	//// Set up a directional light in front of the rectangle.
	//float lightDir[] = { 0.0, 0.0, 1.0, 0.0 }; // Directional light along the positive z-axis (front).
	//float lightAmb[] = { 0.2, 0.2, 0.2, 1.0 };   // Ambient light.
	//float lightDiff[] = { 1.0, 1.0, 1.0, 1.0 };  // Diffuse light.
	//float lightSpec[] = { 1.0, 1.0, 1.0, 1.0 };  // Specular light.

	//glLightfv(GL_LIGHT0, GL_POSITION, lightDir);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	//switch (key)
	//{
	//case 'a':
	//    // Move left (decrement translateX).
	//    translateX -= 0.1;
	//    break;
	//case 'd':
	//    // Move right (increment translateX).
	//    translateX += 0.1;
	//    break;
	//case 'w':
	//    // Move up (increment translateY).
	//    translateY += 0.1;
	//    break;
	//case 's':
	//    // Move down (decrement translateY).
	//    translateY -= 0.1;
	//    break;
	//case 27:
	//    exit(0);
	//    break;
	//default:
	//    break;
	//}

	//glutPostRedisplay(); // Mark the window for a redraw.
	switch (key)
	{
	case 'a':
		objectRotation -= 5.0; // Rotate the object counterclockwise.
		break;
	case 'd':
		objectRotation += 5.0; // Rotate the object clockwise.
		break;
	default:
		break;
	}

	glutPostRedisplay(); // Redraw the scene.

}


// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}

