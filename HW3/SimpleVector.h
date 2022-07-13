#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

/*----Write Your Answer Here-----*/
template <class T>
class SimpleVector
{
public:
    SimpleVector() //
    {
        a = new T[5];
        size = 0;
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            a[i] = '\0';
        }
    }
    SimpleVector(int n) //
    {
        if (n <= 0)
            n = 5;
        a = new T[n];
        size = 0;
        capacity = n;
        for (int i = 0; i < capacity; i++)
        {
            a[i] = '\0';
        }
    }
    ~SimpleVector() { delete[] a; }         // done
    bool my_empty() { return (size == 0); } // done
    unsigned int my_size() { return size; } // done
    void my_reverse();                      // done
    void my_clear();                        // done
    void my_extend();                       // done (double the size)
    void my_push_back(T value);             // done
    void my_pop_back();                     // done
    void my_insert(T value, int index);     // done
    void my_set(T value, int index);        // done
    void print();
    T &at(int index)
    {
        if (index >= size)
        {
            cout << "out of range\n";
            return a[0];
        }
        return a[index];
    }
    T &operator[](int index);

private:
    unsigned int size, capacity;
    T *a;
};

template <class T>
void SimpleVector<T>::my_reverse()
{
    T *temp = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = a[size - i - 1];
    }
    delete[] a;
    a = temp;
}

template <class T>
void SimpleVector<T>::my_clear()
{
    int i;
    for (i = 0; i < size; i++)
    {
        a[i] = '\0';
    }
    size = 0;
}

template <class T>
void SimpleVector<T>::my_extend()
{
    capacity = capacity * 2;
    T *temp = new T[capacity];
    int i;
    for (i = 0; i < capacity; i++)
    {
        temp[i] = '\0';
    }
    for (i = 0; i < size; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;
    a = temp;
}

template <class T>
void SimpleVector<T>::my_push_back(T value)
{
    if (size + 1 > capacity)
        my_extend();
    a[size++] = value;
}

template <class T>
void SimpleVector<T>::my_pop_back()
{
    a[--size] = '\0';
}

template <class T>
void SimpleVector<T>::my_insert(T value, int index)
{
    int i;
    if (index <= size && index >= 0)
    {
        size += 1;
        if (size + 1 > capacity)
            my_extend();
        for (i = size - 1; i > index; i--)
        {
            a[i] = a[i - 1];
        }
        a[index] = value;
    }
}

template <class T>
void SimpleVector<T>::my_set(T value, int index)
{
    if (index < size && index >= 0)
    {
        a[index] = value;
    }
}

template <class T>
void SimpleVector<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "_";
    }
}

template <class T>
T &SimpleVector<T>::operator[](int index)
{
    if (index < size && index >= 0)
    {
        return a[index];
    }
    else
    {
        return a[size - 1];
    }
}