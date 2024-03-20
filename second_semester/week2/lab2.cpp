#include <iostream>
#include <cmath>

// The class Point should be deleted when uplaoding to OJ cause it is not necessary and will only make the runtime longer which is an error for OJ

class Point
{
private:
    int x, y;

public:
    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Segment
{
private:
    Point p1, p2;

public:
    Segment(Point x1, Point x2) : p1(x1), p2(x2) {}

    double length()
    {
        double dx = p2.getX() - p1.getX();
        double dy = p2.getY() - p1.getY();

        return sqrt(dx * dx + dy * dy);
    }

    Point getEnd(int index)
    {
        if (index == 0)
            return p1;

        else
            return p2;
    }
};