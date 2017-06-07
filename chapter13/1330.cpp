#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Valuelike version
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
  friend ostream &print(ostream &, HasPtr &);
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {cout <<ps << " contrustor  string ="<<s <<endl;}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) { cout <<ps << " copy  contrustor string ="<<*ps <<endl;}
  ~HasPtr();

  HasPtr &operator=( HasPtr rhs);
  bool operator<(const HasPtr &) const;
  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }

private:
  std::string *ps;
  int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "Swap between <" << *lhs.ps << "> and <"
            << *rhs.ps << ">" << std::endl;
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

 ostream &print(ostream &os, HasPtr & hp)
 {
 	   os<<*hp.ps;
 	   return os;
 	}
HasPtr::~HasPtr() {
	cout <<ps <<" string = " << *ps << " disconstrustor"<<endl;
  delete ps; 
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
  // This copy-assignment operator is correct even if the object is assigned to
  // itself. See ex13.11 for the wrong version.
  /* not use swap
  auto newps = new std::string(*rhs.ps);
 delete ps;
  ps = newps;
  i = rhs.i;
  return *this;
  */
  swap(*this, rhs);
  return *this;
}

bool HasPtr::operator<( const HasPtr &rhs) const{
	    cout << *ps  <<" < " <<*(rhs.ps) <<" ?" <<endl;
       return *(ps) <*(rhs.ps) ;
}

int main() {
  HasPtr hp1 = string("World");//constructor
  HasPtr hp2 = hp1;//copy constructor
  HasPtr hp3; //constructor
  cout << "after here"<<endl;
  hp3 = hp1; //assignment 
  
  hp1.set("Hello");

  std::cout << hp1.get() << std::endl;
  std::cout << hp2.get() << std::endl;
  std::cout << hp3.get() << std::endl;

//  hp1 = hp1;
  //std::cout << "After `hp1 = hp1`: " << hp1.get() << std::endl;

//  swap(hp1, hp2);
//  std::cout << hp1.get() << std::endl;
////  std::cout << hp2.get() << std::endl;

//  swap(hp1, hp1);
//  std::cout << hp1.get() << std::endl;
/*
  vector<HasPtr> vhp;
  HasPtr temp1("b");
  HasPtr temp2("a");
  HasPtr temp3("c");
  
  vhp.push_back( temp1);
  vhp.push_back( temp2);
  vhp.push_back( temp3);
      for (auto a : vhp) {
        print(cout, a) <<endl;
    } 
  sort(vhp.begin(), vhp.end());
      for (auto a : vhp) {
        print(cout, a) <<endl;
    }
    
     */
  return 0;
}