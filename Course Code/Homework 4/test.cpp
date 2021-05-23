#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Fraction f1, f2;
    cout << "Input Two Fractions in the form of a/b: " << endl;
    cin >> f1 >> f2;
    
    Fraction f; 
    
    f = f1 + f2;
    cout << "Sum: " << f << " or " << double(f) << endl;

    f = f1 - f2;
    cout << "Difference: " << f << " or " << double(f) << endl;

    f = f1 * f2;
    cout << "Product: " << f << " or " << double(f) << endl;

    f = f1 / f2;
    cout << "Quotient: " << f << " or " << double(f) << endl;

    bool flag = f1 > f2;
    if (flag)
        cout << f1 << " is larger than " << f2 << endl;
    else
        cout << f1 << " is not larger than " << f2 << endl;


    string num;
    cout << "Conversion from a decimal string: " << endl;
    cin >> num;
    Fraction f3(num);
    cout << f3 << endl;

    return 0;

}
