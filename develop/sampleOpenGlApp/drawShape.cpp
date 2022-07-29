#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#include "drawShape.h"

auto square = [](float size, float position){
    glBegin(GL_POLYGON); //ìhÇËÇ¬Ç‘Çµê}å`ÇÃçÏê¨
    {
        glColor3d(1.0, 0.0, 0.0);
        glVertex3d(-0.5*size,-0.5*size, position);
        glVertex3d(-0.5*size, 0.5*size, position);
        glVertex3d( 0.5*size, 0.5*size, position);
        glVertex3d( 0.5*size,-0.5*size, position);
    }
    glEnd();
};

auto box = [](){
    for (int i=0; i<4; i++){
        glRotated(90.0*i, 0.0, 1.0, 0.0);
        square(1.0, 0.5);
    }

    for (int i=1; i<3; i++){
        glRotated(90.0*i, 1.0, 0.0, 0.0);
        square(1.0, 0.5);
    }
};

void drawShape::draw_box()
{
    box();
}

void drawShape::setStart_point(float Start_point_x, float Start_point_y, float Start_point_z)
{
    start_point_x = Start_point_x;
    start_point_y = Start_point_y;
    start_point_z = Start_point_z;
}
