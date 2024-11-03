#include <iostream>
#include "fib.hpp"

using namespace std;
int main() {
    int n;
    cout << "Please input a positive integer:";
    cin >> n;
    cout << "Fibonacci series up to " << n << " terms:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << fibonacci(i) << " ";
        if(i % 10 == 0){
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}