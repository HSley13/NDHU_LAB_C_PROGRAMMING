#include <iostream>
using namespace std;

class Fraction
{

private:
    int numerator, denominator;

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int m) : numerator(n)
    {
        if (m == 0)
            throw "divided by zero";
        denominator = m;
        simplify();
    }

    Fraction operator=(const Fraction &b)
    {
        setNumerator(b.getNumerator());
        setDenominator(b.getDenominator());
        simplify();

        return *this;
    }

    Fraction operator+(const Fraction &b)
    {
        int d = getDenominator() * b.getDenominator();

        return Fraction((d / getDenominator()) * getNumerator() +
                            (d / b.getDenominator()) * b.getNumerator(),
                        d);
    }

    Fraction operator-(const Fraction &second)
    {
        return (*this + Fraction(-(second.getNumerator()), second.getDenominator()));
    }

    Fraction operator*(const Fraction &b)
    {
        return Fraction(getNumerator() * b.getNumerator(), getDenominator() * b.getDenominator());
    }

    Fraction operator/(const Fraction &b)
    {
        return Fraction(getNumerator() * b.getDenominator(), getDenominator() * b.getNumerator());
    }

    bool operator==(Fraction &b)
    {
        return (getNumerator() == b.getNumerator() && getDenominator() == b.getDenominator());
    }

    int gcd(int a, int b)
    {
        return (b) ? gcd(b, a % b) : a;
    }

    int lcm(int n, int m)
    {
        return (n / gcd(n, m)) * m;
    }

    void simplify()
    {
        // Find the greatest common divisor between the numerator and the denominator
        int n = getNumerator();
        int d = getDenominator();
        int g = gcd(n, d);
        if (g)
        {
            setNumerator(n / g);
            setDenominator(d / g);
        }
        else
            setDenominator(1);
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n)
    {
        numerator = n;
    }

    void setDenominator(int m)
    {
        if (m == 0)
            throw "divided by zero";
        denominator = m;
    }

    void display()
    {
        if (denominator != 1)
            cout << "(" << numerator << "/" << denominator << ")" << endl;
        else
            cout << numerator << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f)
    {
        if (f.denominator != 1)
            out << "(" << f.numerator << "/" << f.denominator << ")" << endl;
        else
            out << f.numerator << endl;
        return out;
    }
};

int main(void)
{
}