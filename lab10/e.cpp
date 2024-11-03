#include <iostream>
#include "e.hpp"

using namespace std;

int main()
{
    Complex complex1(1.5f, 1.5f);
    Complex complex2(2.5f, 0.1f);
    cout << "complex1 and complex2 are: " << endl;
    cout << complex1 << complex2;
    complex1.setRealPart(3.5f);
    cout << "reset complex1: " << endl;
    cout << complex1;
    cout << "complex1 + complex2: " << endl;
    cout << complex1 + complex2;
    cout << "complex1 - complex2: " << endl;
    cout << complex1 - complex2;
    cout << "assignment complex1 to complex2" << endl;
    complex2 = complex1;
    cout << complex2;
    cout << "complex1 * complex2: " << endl;
    cout << complex1 * complex2;

    Complex complex3(2.5f, 1.5f);
    Complex complex4(2.5f, 1.5f);
    Complex complex5(1.5f, 0.5f);
    std::cout << "c3 == c4: " << (complex3 == complex4) << std::endl;
    std::cout << "c3 != c4: " << (complex3 != complex4) << std::endl;
    std::cout << "c3 == c5: " << (complex3 == complex5) << std::endl;
    std::cout << "c3 != c5: " << (complex3 != complex5) << std::endl;

    Complex complex6;
    std::cout << "Enter a complex number in the format (realPart + imaginaryPart * i): ";
    std::cin >> complex6;
    std::cout << "You entered: " << complex6 << std::endl;
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << c.getRealPart() << " + " << c.getImaginaryPart() << " * i;" << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Complex &c)
{
    float realPart, imaginaryPart;
    is >> realPart >> imaginaryPart;
    c.setRealPart(realPart);
    c.setImaginaryPart(imaginaryPart);
    return is;
}
Complex operator+(const Complex &lhs, const Complex &rhs)
{
    float realPart = lhs.getRealPart() + rhs.getRealPart();
    float imaginaryPart = lhs.getImaginaryPart() + rhs.getImaginaryPart();
    return Complex(realPart, imaginaryPart);
}
Complex operator-(const Complex &lhs, const Complex &rhs)
{
    float realPart = lhs.getRealPart() - rhs.getRealPart();
    float imaginaryPart = lhs.getImaginaryPart() - rhs.getImaginaryPart();
    return Complex(realPart, imaginaryPart);
}
Complex &Complex::operator=(const Complex &rhs)
{
    std::cout << "Calling the assignment operator overloading function" << std::endl;
    this->setRealPart(rhs.getRealPart());
    this->setImaginaryPart(rhs.getImaginaryPart());
    return *this;
}
Complex operator*(const Complex &lhs, const Complex &rhs)
{
    float realPart = lhs.getRealPart() * rhs.getRealPart();
    float imaginaryPart = lhs.getImaginaryPart() * rhs.getImaginaryPart();
    return Complex(realPart, imaginaryPart);
}
bool operator==(const Complex &lhs, const Complex &rhs)
{
    return (lhs.getRealPart() == rhs.getRealPart()) && (lhs.getImaginaryPart() == rhs.getImaginaryPart());
}

bool operator!=(const Complex &lhs, const Complex &rhs)
{
    return !(lhs == rhs);
}
