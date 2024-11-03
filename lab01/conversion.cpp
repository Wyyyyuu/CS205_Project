#include <iostream>
using namespace std;
int main()
{
    int num_int1 = 0x7ABCDEF0;
    float num_int_float = num_int1;
    int num_int2 = (int)(num_int_float);

    cout << num_int1 << " " << num_int_float << " "<< num_int2;
}