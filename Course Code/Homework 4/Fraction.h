#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Fraction
{
    public:
    Fraction() : Fraction(0,1) {}
    Fraction (const Fraction &f) : Fraction(f.numerator, f.numerator) {} 
    Fraction (string str_f);
    Fraction(int num, int deno) : numerator(num), denominator(deno) { reduction(numerator, denominator);}

    Fraction operator-() const;
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
    
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);
    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);

    explicit operator double() const;
    string to_str() const;

    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, Fraction& f);

    void reduction(int& num1, int& num2);

    private:
    int numerator;
    int denominator;
};

Fraction Fraction::operator-() const
{
    Fraction inv_f(-numerator, denominator);
    return inv_f;
};

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction f;
    f.denominator = f1.denominator * f2.denominator;
    f.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    f.reduction(f.numerator, f.denominator);

    return f;
};


Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction f(f1+(-f2));
    return f;
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction f;
    f.denominator = f1.denominator * f2.denominator;
    f.numerator = f1.numerator * f2.numerator;
    f.reduction(f.numerator, f.denominator);

    return f;
};


Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    Fraction f;
    while(f2.numerator != 0)
    {
        f.denominator = f2.numerator;
        f.numerator = f2.denominator;
        f = f1 * f;
    };

    return f;
};

bool operator>(const Fraction &f1, const Fraction &f2)
{
    Fraction f(f1-f2);
    bool flag = (f.numerator > 0) ? 1:0;
    
    return flag;
};


bool operator<(const Fraction &f1, const Fraction &f2)
{
    bool flag = f2 > f1;
    return flag;
};

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 > f2);
};

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 < f2);
};

bool operator==(const Fraction &f1, const Fraction &f2)
{
    return (f1 >= f2) && (f1 <= f2);
};

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 == f2);
};

istream& operator>>(istream& in, Fraction& f)
{
    string str_f;
    
};

ostream& operator<<(ostream& out, Fraction& f)
{
    out << f.to_str();
    return out;
}