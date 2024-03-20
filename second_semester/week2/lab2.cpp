#include <iostream>
#include <cmath>

class Segment
{
private:
    Point start, end;

public:
    Segment(Point start, Point end) : start(start), end(end) {}

    double length()
    {
        return sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
    }

    Point getEnd(int index);
};

Point Segment::getEnd(int index)
{
    if (!index)
        return start;

    else
        return end;
}