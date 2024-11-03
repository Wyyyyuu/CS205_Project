#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

const char* match(const char*s, char ch){
    for(int i = 0; s[i] !=0; i++){
        if(ch == s[i]){
            return s + i;
        }
    }
    return NULL;
}

int main(){
    char s[50];
    char ch;

    cout << "Please input a string: " << endl;
    cin.getline(s,50);
    cout << "Please input a character: " << endl;
    cin >> ch;
    const char* out = match(s,ch);
    if (out == NULL){
        cout << "Not Found" << endl;
    }else{
        cout << out << endl;
    }
    
    return 0;
}