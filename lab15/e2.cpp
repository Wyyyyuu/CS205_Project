#include <iostream>
#include <typeinfo>
#include <cstring>
#include <string>
using namespace std;

class Base
{
protected:
    int bvalue;
public:
    Base(int i ) : bvalue(i) {}

    virtual bool equal(const Base& b) const;
    
    friend bool operator == (const Base&, const Base&);
};

class Derived : public Base
{
private:
    int dvalue;
public:
    Derived(int a, int b):Base(a), dvalue(b){}
    
    virtual bool equal(const Base& b) const override;
};

bool operator ==(const Base& b1, const Base& b2)
{
    if(typeid(b1) != typeid(b2))
    {
        throw "The two objects have different types, they cannot be compared.";
    }
    return b1.equal(b2);
}

bool Base::equal(const Base& b) const
{
    return bvalue == b.bvalue;
}

bool Derived::equal(const Base& b) const
{
    if(typeid(*this) != typeid(b))
    {
        return false;
    }
    const Derived& d = dynamic_cast<const Derived&>(b);
    return bvalue == d.bvalue && dvalue == d.dvalue;
}

void process(const Base& b1, const Base& b2)
{
    try
    {
        const type_info& type1 = typeid(b1);
        const type_info& type2 = typeid(b2);
        if(b1 == b2)
            {   
                string type1Name = type1.name();
                cout << "The two " << type1Name.substr(1) << " objects are equal." << endl;
            }
        else
            {   
                string type1Name = type1.name();
                cout << "The two " << (type1Name).substr(1) << " objects are not equal. because they have different values" << endl;
            }
       
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
    }
}

int main()
{
  Base b1(2);
  Base b2(2);
  
  Derived d1(1,2);
  Derived d2(2,2);
  process(b1,b2);
  process(d1,d2); 
  process(b1,d1);
  return 0;
}
