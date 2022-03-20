#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<vector>
#include<math.h>
using namespace std;

#define Sin(angle) sin(angle * 3.1416/180)
#define Cos(angle) cos(angle * 3.1416/180)



int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int transX, transY;
double scaleX, scaleY;
double angle;
double reflX,reflY;


double round(double d)
{
return floor(d + 0.5);
}



void drawPolygon()
{
glBegin(GL_POLYGON);
glColor3f(1.0, 0.0, 0.0);
for (int i = 0; i < edges; i++)
{
glVertex2i(pntX[i], pntY[i]);
}
glEnd();
}




void drawPolygonTrans(int tx, int ty)
{
glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
for (int i = 0; i < edges; i++)
{
glVertex2i(pntX[i] + tx, pntY[i] + ty);
}
glEnd();
}



void drawPolygonScal(int sx, int sy)
{
glBegin(GL_POLYGON);
glColor3f(0.0, 0.0,1.0);
for (int i = 0; i < edges; i++)
{
glVertex2i(pntX[i] * sx, pntY[i] * sy);
}
glEnd();
}




void drawPolygonAntiClockRotation(double angle)
{
glBegin(GL_POLYGON);
glColor3f(0.0, 0.0,1.0);
for (int i = 0; i < edges; i++)
{
 glVertex2i(pntX[i] * Cos(angle) - pntY[i] * Sin(angle), pntX[i] *
Sin(angle) + pntY[i] * Cos(angle));
}
glEnd();
}


void drawPolygonClockWiseRotation(int angle)
{
glBegin(GL_POLYGON);
glColor3f(0.0, 0.0,1.0);
for (int i = 0; i < edges; i++)
{
 glVertex2i(pntX[i] * Cos(angle) + pntY[i] * Sin(angle), - pntX[i] *
Sin(angle) + pntY[i] * Cos(angle));
}
glEnd();
}

void drawPolygonReflection(int sx, int sy)
{
glBegin(GL_POLYGON);
glColor3f(0.0, 0.0,1.0);
for (int i = 0; i < edges; i++)
{
glVertex2i(pntX[i]= -sx, pntY[i]= -sy);
}
glEnd();
}



void myInit(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

}


void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);

if (choice == 1)
{
drawPolygon();
drawPolygonTrans(transX, transY);
}

else if (choice == 2)
{
    drawPolygon();
    drawPolygonScal(scaleX,scaleY);
}

else if (choice == 3)
{
    int c;

    if(c == 1)
    {
        drawPolygon();
        drawPolygonAntiClockRotation(angle);
    }
    else
    {
      drawPolygon();
      drawPolygonClockWiseRotation(angle);
    }
}


else if (choice ==4)
{
    drawPolygon();
    drawPolygonReflection(reflX,reflY);
}

glFlush();
}

int main(int argc, char** argv)
{
cout << "Enter your choice:\n\n" << endl;

cout << "1. Translation" << endl;
cout << "2. Scaling" << endl;
cout << "3. Rotation" << endl;
cout << "4. Reflection" << endl;
cout << "5. Shearing" << endl;
cout << "6. Exit" << endl;

cin >> choice;

if (choice == 6) {
return 0;
}

cout << "\n\nFor Polygon:\n" << endl;

cout << "Enter no of edges: "; cin >> edges;

for (int i = 0; i < edges; i++)
{
cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >>
pntX1 >> pntY1;
pntX.push_back(pntX1);
pntY.push_back(pntY1);
}

if (choice == 1)
{
cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
}

else if (choice == 2)
{
cout << "Enter the Scaleing  factor for X and Y: "; cin >> scaleX >> scaleY;
}

else if (choice == 3)
{
     int c;
    cout<<"Choose Rotation type:"<<endl;
    cout<<"1.Anti-Clock Wise."<<endl;
    cout<<"2. Clock Wise."<<endl;
    cin>>c;
    cout << "Enter the rotation  angle: "; cin >> angle;
}

else if (choice == 4)
{
cout << "Enter the reflection  factor for X and Y: "; cin >> reflX >> reflY;
}

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(100, 150);
glutCreateWindow("Basic Transformations");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
    return 0;
}
