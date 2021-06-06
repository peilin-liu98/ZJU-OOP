#include <stdexcept>
#include <iostream>
using namespace std;
                                            
template <class T>
class Vector {
    public:
        Vector();                      //* creates an empty vector
        Vector(int size);              //* creates a vector for holding 'size' elements
        Vector(const Vector& r);       //* the copy ctor
        ~Vector();                     //* destructs the vector 
        T& operator[](int index) const;      //* accesses the specified element without bounds checking
        T& at(int index);              //* accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
        int size() const;              //* return the size of the container
        void push_back(const T& x);    //* adds an element to the end 
        void clear();                  //* clears the contents
        bool empty() const;            //* checks whether the container is empty 
    
    private:
        void inflate();                //* expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
        T *m_pElements;                //* pointer to the dynamically allocated storage
        int m_nSize;                   //* the number of elements in the container
        int m_nCapacity;               //* the number of elements that can be held in currently allocated storage
};


template <class T>
Vector<T>::Vector(){
    
    m_pElements = new T[0];
    m_nSize = 0;
    m_nCapacity = 0;
}

template <class T>
Vector<T>::Vector(int size){
    
    m_pElements = new T[size];
    m_nSize = size;
    m_nCapacity = size;
}

template <class T>
Vector<T>::Vector(const Vector& r){

    m_nCapacity = r.m_nCapacity;
    m_nSize = r.m_nSize;
    m_pElements = new T[m_nCapacity];

    for (int i=0; i<m_nSize; i++){
        (*this).at(i) = r[i];
    }

}

template <class T>
Vector<T>::~Vector(){
    
    delete[] m_pElements;
}

template <class T>
T& Vector<T>::operator[](int index) const{

    T& get = m_pElements[index];

    return get;
}

template <class T>
T& Vector<T>::at(int index){

    if (index < 0 || index >= m_nSize)
        throw std::out_of_range("Index Out of the Bounds");
    
    T& get = (*this)[index];

    return get;
}

template <class T>
int Vector<T>::size() const{

    return m_nSize;
}

template <class T>
void Vector<T>::inflate() {

    m_nCapacity = 2 * (m_nCapacity + 1);
    T* new_ptr = new T[m_nCapacity];
    for (int i=0; i<m_nSize; i++)
        new_ptr[i] = (*this)[i];
    
    delete[] m_pElements;
    m_pElements = new_ptr;
}

template <class T>
void Vector<T>::push_back(const T& x){

    if (m_nSize == m_nCapacity) 
        inflate();
    
    (*this)[m_nSize] = x;
    m_nSize ++;
}

template <class T>
void Vector<T>::clear(){

    delete[] m_pElements;
    m_nSize = 0;

    m_pElements = new T[m_nCapacity];
}

template <class T>
bool Vector<T>::empty() const{

    return (m_nSize == 0) ? true : false;
}
