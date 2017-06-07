#include <string>
#include <iostream>

class person {
    std::string name() const {return name;}
    std::string address() const {return address;}
    double avg_price() const;
  	
    std::string name;
    std::string address;
    int age;

};

int main() {

  return 0;
}