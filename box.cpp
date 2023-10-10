/////////////////////////////////          
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cmath>
#define M_PI 3.14159265358979323846264338327950288

// Variables for translation.
GLfloat translateX = 0.0;
GLfloat translateY = 0.0;

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menambahkan GL_DEPTH_BUFFER_BIT untuk depth testing.
    glLoadIdentity();

    // Modeling transformations.
    glTranslatef(translateX, translateY, -15.0);
    // Rotasi 90 derajat sekitar sumbu Y.
    glRotatef(90.0,20.0, -70.0, 110.0);

    // Menggambar sisi-sisi kubus persegi panjang dengan warna-warni.
    //sglBegin(GL_QUADS);
    glBegin(GL_QUADS);
    // ...
    // Sisi depan (merah).
    glVertex3f(-5.5, -2.5, 5.5);
    glVertex3f(5.5, -2.5, 5.5);
    glVertex3f(5.5, 2.5, 5.5);
    glVertex3f(-5.5, 2.5, 5.5);

    // Sisi belakang (hijau).

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-5.5, -2.5, -5.5);
    glVertex3f(5.5, -2.5, -5.5);
    glVertex3f(5.5, 2.5, -5.5);
    glVertex3f(-5.5, 2.5, -5.5);

    // Sisi atas (biru).

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-5.5, 2.5, 5.5);
    glVertex3f(5.5, 2.5, 5.5);
    glVertex3f(5.5, 2.5, -5.5);
    glVertex3f(-5.5, 2.5, -5.5);

    // Sisi bawah (kuning).
    glVertex3f(-5.5, -2.5, 5.5);
    glVertex3f(5.5, -2.5, 5.5);
    glVertex3f(5.5, -2.5, -5.5);
    glVertex3f(-5.5, -2.5, -5.5);

    // Sisi kiri (magenta).
    glVertex3f(-5.5, -2.5, 5.5);
    glVertex3f(-5.5, 2.5, 5.5);
    glVertex3f(-5.5, 2.5, -5.5);
    glVertex3f(-5.5, -2.5, -5.5);

    // Sisi kanan (cyan).
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(5.5, -2.5, 5.5);
    glVertex3f(5.5, 2.5, 5.5);
    glVertex3f(5.5, 2.5, -5.5);
    glVertex3f(5.5, -2.5, -5.5);

    glEnd();

    // Gambar kubus sebagai wireframe dengan GL_LINES.
    glBegin(GL_LINES);

    // Garis-garis depan kubus.
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.5, -2.5, 5.5);
    glVertex3f(5.5, -2.5, 5.5);

    glVertex3f(5.5, -2.5, 5.5);
    glVertex3f(5.5, 2.5, 5.5);

    glVertex3f(5.5, 2.5, 5.5);
    glVertex3f(-5.5, 2.5, 5.5);

    glVertex3f(-5.5, 2.5, 5.5);
    glVertex3f(-5.5, -2.5, 5.5);

    // Garis-garis belakang kubus.
//    glColor3f(0.0, 1.0, 0.0);  // Hijau
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.5, -2.5, -5.5);
    glVertex3f(5.5, -2.5, -5.5);

    glVertex3f(5.5, -2.5, -5.5);
    glVertex3f(5.5, 2.5, -5.5);




    // Garis-garis menghubungkan sisi-sisi kubus.
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.5, -2.5, 5.5);
    glVertex3f(-5.5, -2.5, -5.5);

    glVertex3f(5.5, -2.5, 5.5);
    glVertex3f(5.5, -2.5, -5.5);

    glVertex3f(5.5, 2.5, 5.5);
    glVertex3f(5.5, 2.5, -5.5);


    // Draw a circle in the middle of the front side.
    float centerX = 4.5;
    float centerY = 2.0;
    float radius = 0.2;
    int numSegments = 360;
    float angle;

    glColor3f(0.0, 0.0, 0.0);
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
    glVertex3f(-0.7, -0.3, 1.1);
    glVertex3f(0.7, -0.3, 1.1);
    glVertex3f(0.7, 0.3, 1.1);
    glVertex3f(-0.7, 0.3, 1.1);
    glEnd();

    // Front (Blue)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.7, 1.5, 1.1);
    glVertex3f(0.7, 1.5, 1.1);
    glVertex3f(0.7, 0.8, 1.1);
    glVertex3f(-0.7, 0.8, 1.1);
    glEnd();


    // Front (Red)
    glColor3f(1.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.7, 2.0, 1.1);
    glVertex3f(0.7, 2.0, 1.1);
    glVertex3f(0.7, 2.7, 1.1);
    glVertex3f(-0.7, 2.7, 1.1);
    glEnd();


    glFlush();
}


// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
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
    switch (key)
    {
    case 'a':
        // Move left (decrement translateX).
        translateX -= 0.1;
        break;
    case 'd':
        // Move right (increment translateX).
        translateX += 0.1;
        break;
    case 'w':
        // Move up (increment translateY).
        translateY += 0.1;
        break;
    case 's':
        // Move down (decrement translateY).
        translateY -= 0.1;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay(); // Mark the window for a redraw.

}

// Main routine.
int main(int argc, char **argv)
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

