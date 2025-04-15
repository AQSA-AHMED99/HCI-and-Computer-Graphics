#include <iostream>
#include <GL/freeglut.h>
#include <cmath> // For sin, cos

// Function to draw a circle (used for sun, clouds, and knocker)
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // center
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Function to draw a tree
void drawTree(float x, float y) {
    // Trunk
    glColor3f(0.4f, 0.26f, 0.13f); // Brown
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, y + 30);
        glVertex2f(x, y + 30);
    glEnd();

    // Leaves - three circles
    glColor3f(0.0f, 0.6f, 0.2f); // Green
    drawCircle(x + 5, y + 45, 15, 50);
    drawCircle(x - 5, y + 35, 15, 50);
    drawCircle(x + 15, y + 35, 15, 50);
}

// Function to draw a rectangle (used for window frame)
void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

// Function to draw a line (used for cross lines in windows)
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

// Display function
void display() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f);  // Sky blue
    glClear(GL_COLOR_BUFFER_BIT);

    // Grass
    glColor3f(0.0f, 0.8f, 0.2f); // Green
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(400, 0);
        glVertex2f(400, 100);
        glVertex2f(0, 100);
    glEnd(); 
    
// Road 
glColor3f(0.8f, 0.7f, 0.7f); // Dark gray for the road
glBegin(GL_POLYGON);
    glVertex2f(190, 100);  // Top left (aligned under the door)
    glVertex2f(180, 0);    // Bottom left
    glVertex2f(220, 0);    // Bottom right
    glVertex2f(210, 100);  // Top right
glEnd();

    // House base
    glColor3f(1.0f, 0.41f, 0.71f); // Pink
    glBegin(GL_POLYGON);
        glVertex2f(100, 100);
        glVertex2f(300, 100);
        glVertex2f(300, 250);
        glVertex2f(100, 250);
    glEnd();

    // Roof
    glColor3f(0.7f, 0.2f, 0.2f);  // Dark red
    glBegin(GL_TRIANGLES);
        glVertex2f(80, 250);
        glVertex2f(320, 250);
        glVertex2f(200, 350);
    glEnd();

    // Door
    glColor3f(0.4f, 0.2f, 0.0f);  // Brown
    glBegin(GL_POLYGON);
        glVertex2f(180, 100);
        glVertex2f(220, 100);
        glVertex2f(220, 180);
        glVertex2f(180, 180);
    glEnd();

    // Door knocker (small circle)
    glColor3f(0.6f, 0.6f, 0.6f); // Silver
    drawCircle(200, 140, 5, 50);

    // Left window
    glColor3f(1.0f, 0.85f, 0.9f); // Lighter pink
    glBegin(GL_POLYGON);
        glVertex2f(120, 180);
        glVertex2f(150, 180);
        glVertex2f(150, 210);
        glVertex2f(120, 210);
    glEnd();

    // Window frame for left window
    glColor3f(0.0f, 0.0f, 0.0f); // Black for frame
    drawRectangle(120, 180, 150, 210);

    // Cross lines for left window
    glColor3f(0.0f, 0.0f, 0.0f); // Black for cross lines
    drawLine(120, 180, 150, 210); // Top-left to bottom-right
    drawLine(150, 180, 120, 210); // Top-right to bottom-left

    // Right window
    glColor3f(1.0f, 0.85f, 0.9f); // Lighter pink
    glBegin(GL_POLYGON);
        glVertex2f(250, 180);
        glVertex2f(280, 180);
        glVertex2f(280, 210);
        glVertex2f(250, 210);
    glEnd();

    // Window frame for right window
     glColor3f(0.0f, 0.0f, 0.0f); // Black for frame
    drawRectangle(250, 180, 280, 210);

    // Cross lines for right window
    glColor3f(0.0f, 0.0f, 0.0f); // Black for cross lines
    drawLine(250, 180, 280, 210); // Top-left to bottom-right
    drawLine(280, 180, 250, 210); // Top-right to bottom-left

    // Sun
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    drawCircle(350, 350, 30, 100);

    // Clouds
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawCircle(80, 360, 20, 100);
    drawCircle(100, 370, 25, 100);
    drawCircle(120, 360, 20, 100);

    drawCircle(220, 340, 18, 100);
    drawCircle(240, 350, 22, 100);
    drawCircle(260, 340, 18, 100);

    // Trees
    drawTree(50, 100);
    drawTree(320, 100);

    glFlush();
}

// Setup
void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
    glMatrixMode(GL_MODELVIEW);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My Aesthetic House Scene");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
