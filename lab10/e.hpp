#include <iostream>

class Complex
{
private:
    float realPart;
    float imaginaryPart;

public:
    Complex(float realPart = 0, float imaginaryPart = 0)
    {
        this->realPart = realPart;
        this->imaginaryPart = imaginaryPart;
    }

    // getter and setter
    float getRealPart() const { return realPart; }
    float getImaginaryPart() const { return imaginaryPart; }
    void setRealPart(float realPart) { this->realPart = realPart; }
    void setImaginaryPart(float imaginaryPart) { this->imaginaryPart = imaginaryPart; }
    // input and output
    friend std::istream &operator>>(std::istream &is, Complex &c);
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    // assignment
    Complex &operator=(const Complex &rhs);
};

Complex operator+(const Complex &lhs, const Complex &rhs);
Complex operator-(const Complex &lhs, const Complex &rhs);
Complex operator*(const Complex &lhs, const Complex &rhs);
bool operator==(const Complex &lhs, const Complex &rhs);
bool operator!=(const Complex &lhs, const Complex &rhs);