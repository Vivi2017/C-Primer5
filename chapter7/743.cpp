#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct NoDefault {
    NoDefault(int i):value(i){};
    int value;
};

class C{
    public:
    C():nod(0){};
    
      NoDefault nod;
};
    
    
int main()
{
   // vector<NoDefault> vec(10);// NoDefault has no default constructor, this is wrong
    vector<NoDefault> vec(10,0);
    vector<C> vecc(10);
}


(a) A class must provide at least one constructor.

True. If the programmer doesn't provide any constructor, the compiler will synthesise one default constructor.

(b) A default constructor is a constructor with an empty parameter list.

Untrue. A constructor of which all parameters have default values also defines a default constructor.

(c) If there are no meaningful default values for a class, the class should not provide a default constructor.

True.

(d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

Untrue. Only if a class does not define any constructors, will the compiler generate synthesised default constructor.