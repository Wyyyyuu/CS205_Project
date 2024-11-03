#include <iostream>
#include <cmath>
using namespace std;

bool vaps(int *p,int n){
    if(p == NULL){
    return false;
    }else{
    for (int i = 0; i < n; i++)
    {
        p[i] = abs(p[i]);
    }  
    return true;
    }
}
bool vaps(float *p,int n){
    if(p == NULL){
    return false;
    }else{
    for (int i = 0; i < n; i++)
    {
        p[i] = abs(p[i]);
    }  
    return true;
    }
}
bool vaps(double *p,int n){
    if(p == NULL){
    return false;
    }else{
    for (int i = 0; i < n; i++)
    {
        p[i] = abs(p[i]);
    }  
    return true;
    }
}

int main(){
    int a[] = {-1,0,1};
    float b[] = {2.3f,-3.4f};
    double c[] = {2.3,-3.4};

    vaps(a,3);
    vaps(b,2);
    vaps(c,2);

    for(int i =0; i < 3; i++){
        cout << a[i] << endl;
    }
    for(int i =0; i < 2; i++){
        cout << b[i] << endl;
    }
    for(int i =0; i < 2; i++){
        cout << c[i] << endl;
    }

    
    return 0;
}