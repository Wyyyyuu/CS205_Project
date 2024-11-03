#include <iostream>
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 10;
    int y = 20;
    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;
    return 0;
}