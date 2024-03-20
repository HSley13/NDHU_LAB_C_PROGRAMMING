#include <iostream>
#include <cmath>

class find_total
{

public:
    double total_price(float KM)
    {
        const float price = 1.2;
        double total;

        if (KM <= 200)
            total = (KM * price);

        else if (KM > 200)
            total = ((((KM - 200) * price) * (75.0 / 100.0)) + (200 * price));

        return total;
    }
};

int main(void)
{
    float distance;
    std::cin >> distance;

    find_total result;

    std::cout << round(result.total_price(distance)) << std::endl;
}
