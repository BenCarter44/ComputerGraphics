#ifndef POLYGON_H
#define POLYGON_H

#include "DisplayObject.h"
#include <algorithm>
#include <cmath>
#include <iostream>

struct Point {
        double x;
        double y;
    };

struct Face {
    Point points[4];
    uint8_t r;
    uint8_t g;
    uint8_t b;
    int zindex;

    Face(Point aP, Point bP, Point cP, Point dP)
    {
        points[0] = aP;
        points[1] = bP;
        points[2] = cP;
        points[3] = dP;
        r = 255;
        g = 255;
        b = 255;
        zindex = 0; // render order.
    }
    void setColor(uint8_t rIn, uint8_t gIn, uint8_t bIn)
    {
        r = rIn;
        g = gIn;
        b = bIn;
    }
};

class Polygon
{
private:
    /**
     * @brief 
     * 
     * @param reference 
     * @param p1 
     * @param p2 
     * @return true 
     * @return false 
     */
    static bool closerToReference(Point reference, Point p1, Point p2);
    static bool comparePoints(Point reference, Point p1, Point p2);
    void sortPointsCounterclockwise(Point* arr, int len);
    void drawShape(Face* arr);
    void getFaces();
public:
    static double polarAngle(Point reference, Point p);
    Polygon(Point* pointsList, int pointsLength);
    void draw();
    ~Polygon();
    Face** getColorFaces();
    int getNumberFaces();
    static double getArea(Face* arr);

private:
    /**
     * @brief Number of points passed in.
     * 
     */
    int pointsLength;

    /**
     * @brief Point array.
     * 
     */
    Point* pointsList;
    
    /**
     * @brief Array of faces. The array is sorted by face area. For coloring.
     * 
     */
    Face** faceList;

    /**
     * @brief The array of faces. Sorted by rendering.
     * 
     */
    Face** faceListOriginal;
};

#endif