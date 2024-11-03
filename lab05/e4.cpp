#include <iostream>
using namespace std;

int main()
{
    int * p = new int[5]{1,2,3,4,5};

    for(int i = 4; i >= 0; i--){
        cout << "p[i] = " << p[i] << endl;
    }

    delete [] p;

    return 0;
}