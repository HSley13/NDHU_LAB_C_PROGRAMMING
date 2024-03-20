#include <iostream>
#include <cmath>

class Triangle
{

public:
    Point p1, p2, p3;

    Triangle(Point pt1, Point pt2, Point pt3) : p1(pt1), p2(pt2), p3(pt3) {}

    double distance(Point start, Point end)
    {
        double d1 = end.getX() - start.getX();
        double d2 = end.getY() - start.getY();

        return sqrt(d1 * d1 + d2 * d2);
    }

    double perimeter()
    {
        double side1 = distance(p1, p2);
        double side2 = distance(p2, p3);
        double side3 = distance(p3, p1);

        return side1 + side2 + side3;
    }
};

int main(void)
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        double x1, y1, x2, y2, x3, y3;

        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point p1;
        p1.setX(x1);
        p1.setY(y1);

        Point p2;
        p2.setX(x2);
        p2.setY(y2);

        Point p3;
        p3.setX(x3);
        p3.setY(y3);

        Triangle triangle(p1, p2, p3);
        std::cout << triangle.perimeter() << std::endl;
    }
}