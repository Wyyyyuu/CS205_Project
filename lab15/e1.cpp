#include <iostream>

using namespace std;

class Driver; // forward declaration of Driver class

class Car
{
private:
    enum
    {
        Off,
        On
    }; // Off- non automatically drive, On-automatically drive
    enum
    {
        Minvel = 0,
        Maxvel = 200
    };        // range of velocity from 0  to 200
    int mode; // mode of car, Off or On
    int velocity;

public:
    friend class Driver; // make Driver a friend class so that it can access the private members of Car

    Car(int m = On, int v = 50) : mode(m), velocity(v) {}

    bool velup(int v)
    {
        if (mode == Off || velocity + v > Maxvel)
            return false;
        velocity += v;
        return true;
    }

    bool veldown(int v)
    {
        if (mode == Off || velocity - v < Minvel)
            return false;
        velocity -= v;
        return true;
    }

    bool ison() const
    {
        return mode == On;
    }

    int getvel() const
    {
        return velocity;
    }

    void showinfo() const
    {
        cout << "The information of car: mode is " << (mode == On ? "On" : "Off") << ", velocity is " << velocity << endl;
    }
};

class Driver
{
public:
    bool velup(Car &car, int v)
    {
        return car.velup(v);
    }

    bool veldown(Car &car, int v)
    {
        return car.veldown(v);
    }

    void setmode(Car &car)
    {
        car.mode = (car.mode == Car::On) ? Car::Off : Car::On;
        cout << "Set the mode of car by driver : The mode of car is " << (car.mode == Car::On ? "On" : "Off") << "." << endl;
    }

    bool ison(Car &car) const
    {
        return car.ison();
    }
};

int main()
{
    Car car;
    Driver driver;

    car.showinfo();
    driver.velup(car, 120);
    cout << "Increase velocity by driver: ";
    car.showinfo();
    driver.setmode(car);
    car.showinfo();
    driver.veldown(car, 100);
    cout << "Decrease velocity by driver: ";
    car.showinfo();
    driver.velup(car, 200);
    cout << "Increase velocity by driver: ";
    car.showinfo();

    return 0;
}