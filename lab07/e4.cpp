#include <iostream>
using namespace std;

struct stuinfo
{
    string name;
    int age;
};

template <typename T>
int Compare(T a, T b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

template <>
int Compare(stuinfo a, stuinfo b){
    if(a.name > b.name){
        return 1;
    }else if (a.name < b.name){
        return -1;
    }else{
        return 0;
    }
}

int main()
{
    int int1 = 10, int2 = 20;
    char char1 = 'a', char2 = 'z';
    float float1 = 5.43f, float2 = 4.56f;
    stuinfo a = {"a",10};
    stuinfo b = {"b",10};

    cout << "Compare of the two integers:" << Compare(int1, int2) << endl;
    cout << "Compare of the two characters:" << Compare(char1, char2) << endl;
    cout << "Compare of the two floats:" << Compare(float1, float2) << endl;
    cout << "Compare of the two structs:" << Compare(a,b) << endl;

    return 0;
}
