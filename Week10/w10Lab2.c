#include <stdio.h>

typedef struct 
{
    float x, y;
} Point;

typedef struct 
{
    Point point;
    float slope;
} Line;

int is_point_on_line(float A, float B, float C, float x, float y)
{
    if ( (A * x) + (B * y) + C == 0) return 1;

    else return 0;
}

int main(void)
{
    Line l;
    scanf("%f, %f, %f", &l.point.x, &l.point.y, &l.slope);

    float A = -l.slope;
    float B = 1;
    float C = (l.slope * l.point.x) - l.point.y;

    Point p;
    scanf("%f, %f", &p.x, &p.y);

    if (is_point_on_line(A, B, C, p.x, p.y)) printf ("YES");

    else printf ("NO");

}