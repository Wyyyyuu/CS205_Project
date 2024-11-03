#include <iostream>
using namespace std;
#define SIZE 5
int sum(const int *pArray,int n);

int main()
{
    int const *pa = new int[SIZE]{3,5,8,2,6};
    int total = sum(pa,SIZE);
    delete[] pa;
    cout << "sum = " << total << endl;
    return 0;
}

int sum(const int *pArray, int n)
{
    if (pArray == NULL){
        cerr << "NULL POINTER!" << endl;
        return 0;
    }
    if (n < 0){
        cerr << "n should be integer." << endl;
        return 0;
    }
    
    int s = 0;
    for(int i = 0; i < n; i++)
        s += pArray[i];
    return s;
    
}


