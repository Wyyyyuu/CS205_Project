#include <iostream>
using namespace std;
class Complex
{
private:
    float realNum;
    float imaginaryNum;

public:
    Complex(float realNum = 0.0f, float imaginaryNum = 0.0f)
        : realNum(realNum), imaginaryNum(imaginaryNum) {}
    Complex add(const Complex &other) const
    {
        return Complex(realNum + other.realNum, imaginaryNum + other.imaginaryNum);
    }
    Complex subtract(const Complex &other) const
    {
        return Complex(realNum - other.realNum, imaginaryNum - other.imaginaryNum);
    }
    void display() const
    {
        if (imaginaryNum >= 0)
        {
            cout << realNum << " + " << imaginaryNum << "i" << endl;
        }
        else
        {
            cout << realNum << " - " << -imaginaryNum << "i" << endl;
        }
    }
};

int main()
{
    Complex c1(1.5, 2.0);
    Complex c2(3.5, -1.0);

    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();

    Complex c3 = c1.add(c2);
    Complex c4 = c1.subtract(c2);

    cout << "c1 + c2: ";
    c3.display();
    cout << "c1 - c2: ";
    c4.display();

    return 0;
}