#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class instructions
{
private:
    std::string cmd, p1, p2, p3;

public:
    instructions(std::string _cmd, std::string _p1, std::string _p2, std::string _p3);

    void regTranslate(std::string a);

    void opTranslate(std::string a);

    void shamt() { std::cout << "00000"; }

    void functTranslate(std::string a);

    void dec2bin(int a);
};

instructions::instructions(std::string _cmd, std::string _p1, std::string _p2, std::string _p3) : cmd(_cmd), p1(_p1), p2(_p2), p3(_p3)
{
    if (cmd == "addi")
    {
        opTranslate(cmd);
        regTranslate(p2);
        regTranslate(p1);
        regTranslate(p3);
    }
    else
    {
        opTranslate(cmd);
        regTranslate(p2);
        regTranslate(p3);
        regTranslate(p1);
        shamt();
        functTranslate(cmd);
    }
}

void instructions::regTranslate(std::string a)
{
    std::string tmp = a.substr(0, 3);

    if (tmp == "$t0")
        std::cout << "01000";

    else if (tmp == "$t1")
        std::cout << "01001";

    else if (tmp == "$t2")
        std::cout << "01010";

    else if (tmp == "$t3")
        std::cout << "01011";

    else if (tmp == "$t4")
        std::cout << "01100";

    else if (tmp == "$t5")
        std::cout << "01101";

    else if (tmp == "$t6")
        std::cout << "01110";

    else if (tmp == "$t7")
        std::cout << "01111";

    else
        dec2bin(std::stoi(a));
}

void instructions::opTranslate(std::string a)
{
    if (a == "add")
        std::cout << "000000";

    else if (a == "sub")
        std::cout << "000000";

    else if (a == "or")
        std::cout << "000000";

    else if (a == "and")
        std::cout << "000000";

    else if (a == "addi")
        std::cout << "001000";
}

void instructions::functTranslate(std::string a)
{
    if (a == "add")
        std::cout << "100000";

    else if (a == "sub")
        std::cout << "100010";

    else if (a == "or")
        std::cout << "100101";

    else if (a == "and")
        std::cout << "100100";
}

void instructions::dec2bin(int a)
{
    long long digit = 0, ans = 0;

    while (a)
    {
        ans += (a % 2) * (std::pow(10, digit));
        a /= 2;
        digit++;
    }

    if (!digit)
        digit = 1;

    for (int i = 0; i < (16 - digit); i++)
        std::cout << "0";

    std::cout << ans;
}

int main(void)
{
    std::string cmd, p1, p2, p3;

    while (std::cin >> cmd >> p1 >> p2 >> p3)
    {
        instructions a(cmd, p1, p2, p3);
        std::cout << std::endl;
    }
}
