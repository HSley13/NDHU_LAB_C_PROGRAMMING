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

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int n) { numerator = n; }

    void setDenominator(int m)
    {
        if (m == 0)
            throw "divided by zero";
        denominator = m;
    }

    int gcd(int a, int b)
    {
        return (b) ? gcd(b, a % b) : a;
    }

    int lcm(int n, int m)
    {
        return (n / gcd(n, m)) * m;
    }

    Fraction simplify()
    {
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

        return *this;
    }

    Fraction operator+(const Fraction &second)
    {
        int denominator = getDenominator() * second.getDenominator();
        int numerator = (getNumerator() * (denominator / getDenominator())) + (second.getNumerator() * (denominator / second.getDenominator()));

        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction &second)
    {
        Fraction negativeF(-(second.getNumerator()), second.getDenominator());
        return (*this + negativeF);
    }

    Fraction operator*(const Fraction &b)
    {
        return Fraction(getNumerator() * b.getNumerator(), getDenominator() * b.getDenominator());
    }

    Fraction operator/(const Fraction &b)
    {
        return Fraction(getNumerator() * b.getDenominator(), getDenominator() * b.getNumerator());
    }

    Fraction operator!()
    {
        return Fraction(denominator, numerator);
    }

    Fraction &operator=(const Fraction &right)
    {
        if (this == &right)
            return *this; // Return the current object without modification

        // Assign numerator and denominator from right object to current object
        numerator = right.getNumerator();
        denominator = right.getDenominator();

        // Return a reference to the current object
        return *this;
    }

    void display()
    {
        if (denominator != 1)
            cout << "(" << numerator << "/" << denominator << ")" << endl;
        else
            cout << "(" << numerator << ")" << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f)
    {
        if (f.denominator != 1)
            out << "(" << f.numerator << "/" << f.denominator << ")" << endl;
        else
            out << "(" << f.numerator << ")" << endl;
        return out;
    }
};

int main(void)
{
}