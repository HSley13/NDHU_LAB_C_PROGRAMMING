#include <iostream>

class segments
{
public:
    void overlay_or_not(int a1, int b1, int a2, int b2)
    {
        if (a1 > b1)
        {
            int temp = a1;
            a1 = b1;
            b1 = temp;
        }

        if (a2 > b2)
        {
            int temp = a2;
            a2 = b2;
            b2 = temp;
        }

        if (a2 >= b1 || b2 <= a1)
            std::cout << "no overlay";

        else
            std::cout << "overlay";
    }
};

int main(void)
{
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;

    segments result;

    result.overlay_or_not(a1, b1, a2, b2);
}
