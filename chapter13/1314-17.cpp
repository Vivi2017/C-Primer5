#include <string>
#include <iostream>
using namespace std;

class NumberID;
ostream & print(ostream &, NumberID &);
ostream & print_copy(ostream &, NumberID );
class NumberID{
public:
      NumberID( ):id(0){};
      	
      NumberID(NumberID &rhs ):id(rhs.id+2){};

friend ostream & print(ostream &, NumberID &);

friend ostream & print_copy(ostream &, NumberID );

private:
     int id;
};

ostream& print(ostream & os, NumberID &one){
    os <<"ID is " <<one.id <<endl;
    return os;
}


ostream& print_copy(ostream & os, NumberID one){
    os <<"ID is " <<one.id <<endl;
    return os;
}
/*
HasPtr::HasPtr(const HasPtr &rhs){
    cout<<"copy construnctor called"<<endl;
    i = rhs.i;
    ps = new string(*(rhs.ps));
  
}

HasPtr& HasPtr::operator=(HasPtr &rhs){
     cout<<"euqual operetor called"<<endl;
     i  = rhs.i;
     delete ps;
     ps = new string(*(rhs.ps));
     return *this;      
}
*/
int main(){
    
   NumberID a, b=a, c=b;
    print(cout, a);
    print(cout, b);
    print(cout, c);
    
    print_copy(cout, a);
    print_copy(cout, b);
    print_copy(cout, c);
    return 0;
}