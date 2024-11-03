#include <iostream>
enum Day {Sunday,Monday,Tuesday,Wednesday,Thursday,Firday,Saturday};
enum Weather {Sunny,Rainy,Foggy};

struct Dayinfo
{
    enum Day day;
    enum Weather weather;

};

bool canTravel(Dayinfo d){
    if(d.day == Sunday || d.day == Saturday){
        if (d.weather == Sunny)
        {
            return true;
        }             
    }
    return false;
}

using namespace std;
int main(){
    Dayinfo d;
    // d.day = Sunday;
    // d.weather = Sunny;
    d.day = Monday;
    d.weather = Sunny;

    cout << canTravel(d) << endl;
    return 0;
}