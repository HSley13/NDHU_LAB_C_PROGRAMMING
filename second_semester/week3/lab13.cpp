#include <iostream>
#include <vector>
#include <algorithm>

class matrix
{
private:
    std::vector<std::vector<int>> matrix;

    int n = 0;

public:
    void scan();

    void print();

    void right();

    void left();
};

void matrix::scan()
{
    std::cin >> n;

    matrix.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }
}

void matrix::print()
{
    if (n == 0)
    {
        std::cout << "No element in matrix can be printed.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }

    std::cout << "\n";
}

void matrix::right()
{
    if (n == 0)
    {
        std::cout << "No element in matrix can be rotated.\n";
        return;
    }

    std::vector<std::vector<int>> tmp;

    tmp.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = matrix[n - 1 - j][i];
        }
    }
    matrix = tmp;
}

void matrix::left()
{
    if (n == 0)
    {
        std::cout << "No element in matrix can be rotated.\n";
        return;
    }

    std::vector<std::vector<int>> tmp;

    tmp.resize(n, std::vector<int>(n));

    for (int t = 0; t < 3; t++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                tmp[i][j] = matrix[n - 1 - j][i];
        }

        matrix = tmp;
    }
}

int main(void)
{
    std::string str;

    matrix m;

    while (true)
    {
        std::cin >> str;

        if (str == "stop")
            return 0;

        else if (str == "rotate")
        {
            std::string str2;

            std::cin >> str2;

            if (str2 == "left")
                m.left();

            else if (str2 == "right")
                m.right();

            else
                std::cout << "unknown\n";
        }

        else if (str == "print")
            m.print();

        else if (str == "scan")
            m.scan();

        else
            std::cout << "unknown\n";
    }
}