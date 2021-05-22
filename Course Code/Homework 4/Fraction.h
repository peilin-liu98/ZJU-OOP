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

    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
    
    friend Fraction operator<(const Fraction &f1, const Fraction &f2);
    friend Fraction operator<=(const Fraction &f1, const Fraction &f2);
    friend Fraction operator==(const Fraction &f1, const Fraction &f2);
    friend Fraction operator!=(const Fraction &f1, const Fraction &f2);
    friend Fraction operator>=(const Fraction &f1, const Fraction &f2);
    friend Fraction operator>(const Fraction &f1, const Fraction &f2);

    operator double() const;
    string str() const;

    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, Fraction& f);

    void reduction(int& num1, int& num2);

    private:
    int numerator;
    int denominator;
};

