#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

/////////////////////////////////////////////
////        class drawShape               ////
/////////////////////////////////////////////

class drawShape
{
public:
    void draw_box();
    void setStart_point(float Start_point_x, float Start_point_y, float Start_point_z);
private:
    float start_point_x;
    float start_point_y;
    float start_point_z;
};
