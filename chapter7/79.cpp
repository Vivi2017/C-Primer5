#include <string>
#include <iostream>

using namespace std;
class person;

std::istream &read(std::istream &is, person &item);
std::ostream &print(std::ostream &os, const person &item);
    
class person {
    
  public:
    person() = default;
    person(string n):name(n){};
    person(string n, string ad):name(n), address(ad){};
    person(istream &is) {read(is, *this);};    
    std::string getName() const {return name;};
    std::string getAddress() const {return address;}
        
    void setName(string nameS)  {name = nameS;}
    void setAddress(string addressS)  { address = addressS;}    
      
  private:
    std::string name;
    std::string address;
};


std::istream &read(std::istream &is, person &item) {
  string name;
  string address;
  is >> name >> address;
  
  item.setName(name);
  item.setAddress(address);
  //print(cout,item);
  return is;
}

std::ostream &print(std::ostream &os, const person &item) {
  os << item.getName() << " address is  " << item.getAddress()<<endl;
  return os;
}

int main() {
  person defaultP;
  person nameP = person(string("nanfangguniang"));
  person namePa = person(string("nanfangguniang"), string("wuyin"));
  person nameIs =  person(cin);
 // if(read(read(cin, he),she)) //The condition test if both data1 and data2 are read correctly.
 // {
 //   cout <<"ok" <<endl;
 // }
  print(cout, defaultP);
  print(cout, nameP);
  print(cout, namePa);
  print(cout, nameIs);
  
  
  return 0;
}