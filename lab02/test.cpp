#include <iostream>

int main()
{
    double f1 = 1.200;
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f1 + 1.0/9.0 = " << f1 + 1.0/9.0 << std::endl;

    double f2 = 1.67E2;
    std::cout << "f2 = " << f2 << std::endl;

    double f3 = f2 + 1.0/9.0;
    std::cout << "f3 = " << f3 << std::endl;
    std::cout << "f3 * 1.0e10 + 100 = " << f3 * 1.0e10 + 100 << std::endl;

    double f4 = 2.3e-4;
    std::cout << "f4 = " << f4 << std::endl;
    std::cout << "f4/10 = " << f4/10 << std::endl;

    return 0;
}
