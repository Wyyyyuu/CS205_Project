#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    double *p_reg = new double(5);
    shared_ptr<double> pd (p_reg);
    // pd = p_reg;
     // shared_ptr 类型的变量要通过 make_shared 赋值
    cout << "*pd = " << *pd << endl;
    // shared_ptr<double> pshared = p_reg; // shared类型不能直接从double类型指针转
    shared_ptr<double> pshared = pd;
    cout << "*pshred = " << *pshared << endl;

    string str("Hello World!");
    // shared_ptr<string> pstr(&str); // shared_ptr 没有办法知道指向栈变量的内存是否已被释放，因此使用指向栈变量的指针可能导致程序错误
    shared_ptr<string> pstr = make_shared<string>(str);
    cout << "*pstr = " << *pstr << endl;

    return 0;
}