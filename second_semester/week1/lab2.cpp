#include <iostream>
#include <cmath>

class point
{

public:
    double x;
    double y;

    point(double x, double y) : x(x), y(y) {}

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX()
    {
        return this->x;
    }

    double getY()
    {
        return this->y;
    }
};

class Segment
{
public:
    point start;
    point end;

    double distance()
    {
        double dx = end.getX() - start.getX();
        double dy = end.getY() - start.getY();
        return sqrt(dx * dx + dy * dy);
    }
};

int main(void)
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        double startX, startY, endX, endY;
        std::cin >> endX >> endY >> startX >> startY;

        point start(startX, startY);
        point end(endX, endY);
        Segment segment = {start, end};

        double dist = segment.distance();
        std::cout << dist << std::endl;
    }
}
