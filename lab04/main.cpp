#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int cards[4]{};
    int hands[4];

    double price[] = {2.8,3.7,5,9};
    char direction[4] {'L',82,'U',68};

    char title[] = "ChartGPT is an awesome tool.";

    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[1]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;
    
    //Print the value and address of each element in cards and hands respectively.
    for(int i = 0; i < 4; i++)
    {
        cout << "cards" << i << ": " << cards[i] << endl;
        cout << "cards' address" << i << ": " << &cards[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "hands" << i << ": " << hands[i] << endl;
        cout << "hands' address" << i << ": " << &hands[i] << endl;
    }

return 0;
}
