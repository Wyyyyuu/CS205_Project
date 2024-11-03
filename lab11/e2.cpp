#include <memory>
#include <vector>
#include <iostream>
#include "e2.hpp"
using namespace std;

int main()
{
    // Create matrices a and b
    Matrix a(3, 4);
    Matrix b(3, 4);

    // Initialize a and b with some values
    cout << "Matrix a: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            a(i, j) = i * 4 + j + 0.1f;
            cout << a(i, j) << "  ";
        }
        cout << endl;
    }
    cout << "Matrix b: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            b(i, j) = (i + 1) * 4 + j + 0.1f;
            cout << b(i, j) << "  ";
        }
        cout << endl;
    }
    cout << "Matrix c: " << endl;
    // Test the copy constructor
    Matrix c(a);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << c(i, j) << "  ";
        }
        cout << endl;
    }
    cout << "Matrix d: " << endl;
    // Test the copy assignment operator
    Matrix d = a;
    d = b;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << d(i, j) << "  ";
        }
        cout << endl;
    }
    cout << "Matrix e: " << endl;
    // Test the addition operator
    Matrix e = a + b;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << e(i, j) << "  ";
        }
        cout << endl;
    }

    return 0;
}
