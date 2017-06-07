#include <string>
#include <iostream>
using namespace std;

class HasPtr;
ostream & print(ostream &, HasPtr &);

class HasPtr{
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0){};
    HasPtr(const HasPtr &rhs);
    HasPtr& operator =(HasPtr &rhs);
friend ostream & print(ostream &, HasPtr &);
private:
    string *ps;
    int i;
};

ostream& print(ostream & os, HasPtr &one){
    os <<"Address is " <<one.ps <<" value is: "<< *(one.ps)<<endl;
    return os;
}
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
int main(){
    
    HasPtr oldOne("I am here!");
    print(cout, oldOne)<<endl;
    HasPtr copyOne(oldOne);

    print(cout, copyOne);
    
    HasPtr equalOne("I am there!");
    
    equalOne=oldOne;

    print(cout, equalOne);
    return 0;
}