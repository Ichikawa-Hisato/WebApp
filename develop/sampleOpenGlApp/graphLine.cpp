#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#include "graphLine.h"

auto make_line = [](int x, int y, int z){
    glBegin(GL_LINE_LOOP);
    {
        glColor3d(1.0*x, 1.0*y, 1.0*z);
        glVertex3d(-2.0*x, -2.0*y, -2.0*z);
        glVertex3d(2.0*x, 2.0*y, 2.0*z);
    }
    glEnd();
};

auto x_line = [](){
    make_line(1, 0, 0);
};

auto y_line = [](){
    make_line(0, 1, 0);
};

auto z_line = [](){
    make_line(0, 0, 1);
};

void graphLine::graph_line()
{
    x_line();
    y_line();
    z_line();
}
