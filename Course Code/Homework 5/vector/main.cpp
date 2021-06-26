#include <iostream>
#include "Vector.h"

using namespace std;

int main(){

    Vector<int> array_0;

    for (int i=0; i<10; i++)
        array_0.push_back(i);

    cout << "Array is Empty? " << array_0.empty() << endl;
    cout << "Size of Array: " << array_0.size() << endl;

    Vector<int> array_1(array_0);
    Vector<int> array_2(10);

    cout << "Elements of Array2: " << endl;
    for (int i=0; i<10; i++)
    {
        array_2[i] = array_1.at(i) * array_1.at(i);
        cout << array_2[i] << " ";
    }

    
    cout << endl <<  "Push back a new element: " << endl;
    array_2.push_back(10*10);
    cout << array_2[10] << endl;

    cout << "clear the elements of array! " << endl;
    array_2.clear();
    array_2.at(0);
    
    return 0;
}