#include <iostream>

class Anagram : public std::string
{
private:
    std::string a = "";

public:
    Anagram(std::string _a);

    bool operator==(const Anagram &str) const;
};

Anagram::Anagram(std::string _a)
{
    for (int i = 0; i < _a.length(); i++)
    {
        if (std::isalpha(_a[i]))
            a += std::tolower(_a[i]);
    }
}

bool Anagram::operator==(const Anagram &str) const
{
    int tmp[26] = {0};

    if (a.length() != str.a.length())
        return false;

    for (int i = 0; i < a.length(); i++)
        tmp[a[i] - 'a']++;

    for (int i = 0; i < a.length(); i++)
        tmp[str.a[i] - 'a']--;

    bool flag = 1;

    for (int i = 0; i < 26; i++)
    {
        if (tmp[i] != 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
};

int main(void)
{
    std::string buf;

    std::getline(std::cin, buf);
    Anagram a1(buf);

    std::getline(std::cin, buf);
    Anagram a2(buf);

    std::cout << (a1 == a2) << std::endl;
    std::cout << (a2 == a1) << std::endl;
}