#include <GL/freeglut.h>
#include <iostream>

const int numBodyParts = 16;
float angles[numBodyParts] = { 0.0f };
int currentPart = 0;
float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 600, 600 };
int coloredBodyPartIndex = 0;
float color[3];

void drawRectangle(float width, float height) {
    //glLineWidth(1.5f);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    //std::cout << width<<height << std::endl;
    glVertex2f(-width / 2, 0);
    glVertex2f(width / 2, 0);
    glVertex2f(width / 2, height);
    glVertex2f(-width / 2, height);
    glVertex2f(-width / 2, 0);
    glEnd();
}

void drawFoot(float width, float height) {
    //glLineWidth(1.5f);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    //std::cout << width<<height << std::endl;
    glVertex2f(-width / 2 - 0.15, 0);
    glVertex2f(width / 2 - 0.15, 0);
    glVertex2f(width / 2 - 0.15, height);
    glVertex2f(-width / 2 - 0.15, height);
    glVertex2f(-width / 2 - 0.15, 0);
    glEnd();
}

void ColorWidthChange(int currentBodyPartIndex)
{
    if (coloredBodyPartIndex == currentBodyPartIndex)
    {
        glLineWidth(3.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    else
    {
        glLineWidth(1.5f);
        glColor3f(0.0f, 0.0f, 0.0f);
    }
}

void drawRobot() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // DrawLowerBody();
    ColorWidthChange(0);
    glTranslatef(5.0f, 5.0f, 0.0f);
    glRotatef(angles[0], 0.0f, 0.0f, 1.0f);
    drawRectangle(1.0f, 0.8f); // Lower Body

    glPushMatrix();
    // left thigh
    ColorWidthChange(1);
    glTranslatef(0.40f, 0.0f, 0.0f);
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glRotatef(angles[1], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Left Thigh

    // left leg
    ColorWidthChange(2);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[2], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Left Leg

    // left foot
    ColorWidthChange(3);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[3], 0.0f, 0.0f, 1.0f);
    drawFoot(0.5f, 0.4f);  // Left Foot
    glPopMatrix();

    glPushMatrix();
    // right thigh
    ColorWidthChange(4);
    glTranslatef(-0.40f, 0.0f, 0.0f);
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glRotatef(angles[4], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Right Thigh

    // right leg 
    ColorWidthChange(5);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[5], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Right Leg

    // right foot  
    ColorWidthChange(6);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glRotatef(angles[6], 0.0f, 0.0f, 1.0f);
    drawFoot(0.5f, -0.4f);  // Right Foot
    glPopMatrix();

    // upper body
    ColorWidthChange(7);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[7], 0.0f, 0.0f, 1.0f);
    drawRectangle(1.2f, 0.8f); // Upper Body

    glPushMatrix();
    // right arm
    ColorWidthChange(8);
    glTranslatef(0.6f, 0.4f, 0.0f);
    glRotatef(-90, 0.0f, 0.0f, 1.0f);
    glRotatef(angles[8], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Right Arm

    // right forearm
    ColorWidthChange(9);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[9], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Right ForeArm

    // right hand   
    ColorWidthChange(10);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[10], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.5f, 0.5f);  // Right Hand
    glPopMatrix();

    glPushMatrix();
    // left arm    
    ColorWidthChange(11);
    glTranslatef(-0.6f, 0.4f, 0.0f);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(angles[11], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Left Arm

    // left forearm
    ColorWidthChange(12);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[12], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.8f);  // Left ForeArm

    // left hand
    ColorWidthChange(13);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[13], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.5f, 0.5f);  // Left Hand
    glPopMatrix();

    // neck
    ColorWidthChange(14);
    glPushMatrix();
    glTranslatef(0.0f, 0.8f, 0.0f);
    glRotatef(angles[14], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.2f, 0.6f);  // Neck

    // head
    ColorWidthChange(15);
    glTranslatef(0.0f, 0.6f, 0.0f);
    glRotatef(angles[15], 0.0f, 0.0f, 1.0f);
    drawRectangle(0.8f, 0.8f);  // Head
    glPopMatrix();
    //glutSwapBuffers();
}

void reshape(int w, int h)
{
    rasterSize[0] = w;
    rasterSize[1] = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
    //gluOrtho2D(-canvasSize[0] / 2, canvasSize[0] / 2, -canvasSize[1] / 2, canvasSize[1] / 2);
    glViewport(0, 0, rasterSize[0], rasterSize[1]);

    glutPostRedisplay();
}

void keyboardDown(unsigned char key, int x, int y) {
    if (key == 27) // 'esc' key
        exit(0);

    else if (key == 's') {
        if (currentPart == 0) {
            currentPart = 15;
        }
        else {
            /*color[0] = 1.0f;
            color[1] = 0.0f;
            color[2] = 0.0f;*/
            currentPart = (currentPart - 1 + numBodyParts) % numBodyParts;
            coloredBodyPartIndex = currentPart;
        }
        std::cout << "Selected body part: " << currentPart << std::endl;
    }
    else if (key == 'w') {
        if (currentPart > 15) {
            currentPart = 0;
        }
        else {
            /*color[0] = 1.0f;
            color[1] = 0.0f;
            color[2] = 0.0f;*/
            currentPart = (currentPart + 1) % numBodyParts;
            coloredBodyPartIndex = currentPart;
        }
        std::cout << "Selected body part: " << currentPart << std::endl;
    }
    else if (key == 'd') {
        angles[currentPart] -= 10.0f;
        std::cout << "Rotated body part " << currentPart << " by 10 degrees" << std::endl;
    }
    else if (key == 'a') {
        angles[currentPart] += 10.0f;
        std::cout << "Rotated body part " << currentPart << " by -10 degrees" << std::endl;
    }
    glutPostRedisplay(); // Trigger display update
}

void displayCallback() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawRobot();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Hierarchical Robot");

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardDown);
    glutDisplayFunc(displayCallback);
    glutMainLoop();

    return 0;
}
