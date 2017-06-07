#include <string>
#include <iostream>

using namespace std;

class person {
  public:
    // The member function `getName` and `getAddress` should be `const`, because
    // they don't change the object.
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
        

    double avg_price() const;
  	
    std::string name;
    std::string address;
    int age;

};

int main() {
    person pa;
    cin>>pa.name>>pa.address;
    cout<<pa.getName()<<" address is " <<pa.getAddress() <<endl;

  return 0;
}