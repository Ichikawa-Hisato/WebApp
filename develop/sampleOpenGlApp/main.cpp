#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <random>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#include "graphLine.h"
#include "drawShape.h"

void set_callback_functions();
void show(void);
void glut_mouse(int button, int state, int x, int y);
void glut_motion(int x, int y);
void glut_idle();

// �O���[�o���ϐ�
double g_angle_x = 0.0;
double g_angle_y = 0.0;
double g_distance = 20.0;
bool g_isLeftButtonOn = false;
bool g_isRightButtonOn = false;

int main(int argc, char** argv)
{
    std::cout << "[INFO] Start Create Window" << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowSize(450, 350);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("GLUT test");
    glClearColor(1.0, 1.0, 1.0, 1.0);

    set_callback_functions();
    glutMainLoop();

    return 0;
}

void set_callback_functions(){
    glutDisplayFunc(show);
    glutMouseFunc(glut_mouse);      // �}�E�X�̃N���b�N
    glutMotionFunc(glut_motion);    // �}�E�X�̃h���b�O
    glutPassiveMotionFunc(glut_motion);
    glutIdleFunc(glut_idle);
}

void show(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (cos(g_angle_y)>0){
        gluLookAt(g_distance * cos(g_angle_y) * sin(g_angle_x),
                    g_distance * sin(g_angle_y),
                    g_distance * cos(g_angle_y) * cos(g_angle_x),
                    0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    } else {
        gluLookAt(g_distance * cos(g_angle_y) * sin(g_angle_x),
                    g_distance * sin(g_angle_y),
                    g_distance * cos(g_angle_y) * cos(g_angle_x),
                    0.0, 0.0, 0.0, 0.0, -1.0, 0.0);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // �O���t���𐶐�
    graphLine graphLine;
    graphLine.graph_line();

    // �}�`���쐬
    drawShape drawShape;
    drawShape.draw_box();

    glFlush();
    glDisable(GL_DEPTH_TEST);

    glutSwapBuffers();
}

// �}�E�X����
void glut_mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_UP){
            g_isLeftButtonOn = false;
        }else if(state == GLUT_DOWN){
            g_isLeftButtonOn = true;
        }
    }

    if(button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_UP){
            g_isRightButtonOn = false;
        }else if(state == GLUT_DOWN){
            g_isRightButtonOn = true;
        }
    }
}

// �}�E�X�ړ�
void glut_motion(int x, int y){
    static int px = -1, py = -1;
    if(g_isLeftButtonOn == true){
        if(px >= 0 && py >= 0){
            g_angle_x += (double)-(x - px)/20;
            g_angle_y += (double)(y - py)/20;
        }
        px = x;
        py = y;
    }else if(g_isRightButtonOn == true){
        if(px >= 0 && py >= 0){
            g_distance += (double)(y - py)/20;
        }
        px = x;
        py = y;
    }else{
        px = -1;
        py = -1;
    }
    glutPostRedisplay();
}

// ���[�v����
void glut_idle(){
    usleep(10000); // �t���[�����[�g����
    glutPostRedisplay();
}
