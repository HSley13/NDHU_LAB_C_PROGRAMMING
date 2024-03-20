#include <iostream>
#include <string>

class four
{

private:
    int n;

public:
    four(int number)
    {
        n = number;
    }

    std::string found_or_not();
};

std::string four::found_or_not()
{
    int i = this->n;

    while (i)
    {
        if (i % 10 == 4)
            return "Yes";

        i /= 10;
    }

    return "No";
}

int main(void)
{
    int plate;

    std::cin >> plate;

    if (plate > 0)
    {
        four p(plate);
        std::cout << p.found_or_not() << std::endl;
    }
}