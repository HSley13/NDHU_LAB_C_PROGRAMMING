#include <iostream>
#include <vector>
#include <algorithm>

class numbers
{
private:
    std::vector<int> num;

    int n;

public:
    void insert();

    int reverse_integer(int a);

    bool check(int a);

    void procedure();
};

void numbers::insert()
{
    std::cin >> n;
    num.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> num[i];
}

int numbers::reverse_integer(int a)
{
    std::string tmp = std::to_string(a);

    std::reverse(tmp.begin(), tmp.end());

    a = std::stoi(tmp);

    return a;
}

bool numbers::check(int a)
{
    std::string check = std::to_string(a);

    std::string check2 = check;

    std::reverse(check2.begin(), check2.end());

    return check == check2;
}

void numbers::procedure()
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        while (count == 0 || !check(num[i]))
        {
            num[i] += reverse_integer(num[i]);
            count++;
        }

        std::cout << count << " " << num[i] << std::endl;
    }
}

int main(void)
{
    numbers a;

    a.insert();
    a.procedure();
}