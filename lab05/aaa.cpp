#include <iostream>
using namespace std;

int main()
{
    int numbers[4] = {0, 1, 2, 3};
    int * p = (int *)(&numbers+1);
    cout << numbers << endl;
    cout << p << endl;
    p++;
    *p = 20;
    *(p-1) = 10;
    p[1] = 30;

}