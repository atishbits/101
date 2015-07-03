#include <iostream>
#include<string>
 
using namespace std;
 
class Pet {
public:
    virtual string getDescription() const {
        return "This is Pet class";
    }
};
 
class Dog : public Pet {
public:
    virtual string getDescription() const {
        return "This is Dog class";
    }
};
 
void describe(const Pet& p) { // Slices the derived class object if & not used
    cout<<p.getDescription()<<endl;
}
 
int main() {
    Dog d;
	Pet& p = d;
    describe(p);
    return 0;
}

