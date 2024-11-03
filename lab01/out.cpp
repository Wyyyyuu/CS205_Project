#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << a << endl << b << endl << c << endl;
    
    return 0;
}