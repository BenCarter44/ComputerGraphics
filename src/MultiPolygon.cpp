#include "MultiPolygon.h"


void MultiPolygon::drawShape(Face* arr)
{
    //cout << "DRAW " << endl;
    glColor3f(arr->r / 255.0f, arr->g / 255.0f, arr->b / 255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(arr->points[0].x, arr->points[0].y);
    glVertex2f(arr->points[1].x, arr->points[1].y);
    glVertex2f(arr->points[2].x, arr->points[2].y);
    glVertex2f(arr->points[3].x, arr->points[3].y);
    glEnd();
}

void MultiPolygon::draw()
{
    
    glColor3f(top->r / 255.0f, top->g / 255.0f, top->b / 255.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < numVert; i++)
    {
        glVertex2f(top->points[i].x, top->points[i].y);
    }
    glEnd();
    
    for(int i = 0; i < numVert; i++)
    {
        drawShape(allSides[i]);
    }
    
    glColor3f(bottom->r / 255.0f, bottom->g / 255.0f, bottom->b / 255.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < numVert; i++)
    {
        glVertex2f(bottom->points[i].x, bottom->points[i].y);
    }
    glEnd();
    
    glFlush(); 
}
MultiPolygon::MultiPolygon(AnchorFace* top, AnchorFace* bottom)
{


    this->top = top;
    this->bottom = bottom;
    numVert = top->numberPoints;
    getFaces();
}   

MultiPolygon::~MultiPolygon()
{
    delete[] allSides;
}

Face** MultiPolygon::getColorFaces()
{
    return this->allSides;
}

int MultiPolygon::getColorFacesNum()
{
    return numVert;
}

void MultiPolygon::getFaces()
{
    allSides = new Face*[numVert];
    
    for(int i = 0; i < numVert; i++)
    {
        Face* f = new Face(top->points[i],top->points[(i+1) % numVert],bottom->points[(i+1) % numVert],bottom->points[i]);
        allSides[i] = f;
    }
}