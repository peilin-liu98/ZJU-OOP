#include "Fraction.h"
#include <string>
#include <sstream>
#include<math.h>
using namespace std;

int gcd(int num1, int num2) {
  while (num2 != 0)  {
    int temp = num2;
    num2 = num1 % num2;
    num1 = temp;
  }
  return num1;
};

void Fraction::reduction(int& num1, int& num2)
{
    int temp = abs(gcd(num1, num2));
    num1 /= temp;
    num2 /= temp;
};

int decimal_count(string decimal)
{
    string sub = decimal.substr(decimal.find("."));
    return sub.length() - 1;
};

Fraction::Fraction(string str_f)
{
   stringstream s(str_f);
   double f = 0;
   while(s >> f)
   {
       int n = decimal_count(str_f);
       denominator = pow(10,n);
       numerator = (int)(f * denominator);
       reduction(numerator, denominator);
   };
};

Fraction::operator double() const
{
    return numerator/(double)denominator;
};

string Fraction::to_str() const
{    
    string str_f;
    str_f = to_string(numerator);

    if (denominator != 1)
        str_f += "/" + to_string(denominator);
    
    return str_f;
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
    if (f2.numerator != 0)
    {
        f.denominator = f2.numerator;
        f.numerator = f2.denominator;
        f = f1 * f;
    }
    else cout << "Cannot be divided by 0." << endl;

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
    in >> str_f;
    
    str_f.replace(str_f.find("/"), 1, " ");
    
    stringstream s(str_f);
    s >> f.numerator >> f.denominator;
    
    f.reduction(f.numerator, f.denominator);

    return in;
    
};

ostream& operator<<(ostream& out, Fraction& f)
{
    out << f.to_str();
    return out;
}