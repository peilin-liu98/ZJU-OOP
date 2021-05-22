#include "Fraction.h"
#include <string>
#include <sstream>
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
    int temp = gcd(num1, num2);
    num1 /= temp;
    num2 /= temp;
};

int decimal_count(double decimal)
{
    int intergal = (int)decimal;
    double res = decimal - intergal;
    int count = 1;

    while(res != 0){
        decimal = res * 10;
        res = decimal - int(decimal);
        count *= 10;
    }
    return count;
};

Fraction::Fraction(string str_f)
{
   stringstream s(str_f);
   double f = 0;
   while(s >> f)
   {
       int n = decimal_count(f);
       numerator = (int)f*n;
       denominator = n;
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