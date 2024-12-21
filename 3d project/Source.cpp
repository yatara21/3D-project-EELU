#include <stdio.h>
#include <GL/glut.h>
#include <vector>

/*
========================================
Task number One 3D Computer Graphics
========================================
*/

//std::vector<std::pair<int, int>> vertices;
//bool my_flag = false;
//float red = 1.0f, green = 1.0f, blue = 1.0f; // white color
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(red, green, blue);
//
//    if (my_flag) {
//        glBegin(GL_POLYGON);
//        for (auto& vertex : vertices) {
//            glVertex2i(vertex.first, vertex.second);
//        }
//        glEnd();
//    }
//    else {
//        glBegin(GL_POINTS);
//        for (auto& vertex : vertices) {
//            glVertex2i(vertex.first, vertex.second);
//        }
//        glEnd();
//    }
//    glFlush();
//}
//
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        vertices.emplace_back(x, 500 - y);
//        glutPostRedisplay();
//    }
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 13) { // 'Enter' key
//        my_flag = true;
//        glutPostRedisplay();
//    }
//    else if (key == 'R' || key == 'r') {
//        red = 1.0f; green = 0.0f; blue = 0.0f;
//    }
//    else if (key == 'G' || key == 'g') {
//        red = 0.0f; green = 1.0f; blue = 0.0f;
//    }
//    else if (key == 'B' || key == 'b') {
//        red = 0.0f; green = 0.0f; blue = 1.0f;
//    }
//    else if (key == 'C' || key == 'c') { // Clear screen
//        vertices.clear();
//        my_flag = false;
//    }
//    else if (key == 27) { //ESC
//        exit(0);
//    }
//    glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("3D project task one");
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    gluOrtho2D(0, 500, 0, 500);
//
//    glutDisplayFunc(display);
//    glutMouseFunc(mouse);
//    glutKeyboardFunc(keyboard);
//
//    glutMainLoop();
//    return 0;
//}
/*
=========================================
Ending of Task number One
=========================================

*/






/*
============================================
Task number Two 3D Computer Graphics
============================================
*/

float posX = 0.0f, posY = 0.0f, posZ = -5.0;
float angle = 0.0f;
float scale = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);      // Translation
    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotation
    glScalef(scale, scale, 1.0f);        // Scaling


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();



    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W': case 'w':
        posY += 0.05f;
        break;                  // Move up
    case 'S': case 's':
        posY -= 0.05f;
        break;                  // Move down
    case 'A': case 'a':
        posX -= 0.05f;
        break;                  // Move left
    case 'D': case 'd':
        posX += 0.05f;
        break;                  // Move right
    case 'R': case 'r':
        angle += 5.0f;
        break;                  // Rotate clockwise
    case 'F': case 'f':
        angle -= 5.0f;
        break;                  // Rotate counterclockwise
    case '+':
        scale += 0.1f;
        break;                  // Scale up
    case '-':
        scale -= 0.1f;
        break;                  // Scale down
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D project task two");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glEnable(GL_DEPTH_TEST);

    //glMatrixMode(GL_MODELVIEW);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}


/*
=======================================
Ending of Task number Two
=======================================
*/