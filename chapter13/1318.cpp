#include <string>
#include <iostream>
using namespace std;

class Employee;
ostream & print(ostream &, Employee &);


 	

class Employee{
public:
	  Employee():name(),ID(identifyID++){ cout<<" constuct Employee default"<<endl;};
    Employee(string nameIn):name(nameIn),ID(identifyID++){
    	  cout<<" constuct Employee "<<name<<" ID is: "<< ID <<endl;
    };
    friend ostream & print(ostream &, Employee &); 
    
    Employee(const Employee & person ):name(person.name), ID(identifyID++){
    	  cout<<" copy Employee "<<name<<" ID is: "<< ID <<endl;
    };
   
    Employee& operator=(const Employee & person){
    	name= person.name;
    	ID = person.ID;
    	cout<<" Assigment Employee "<<name<<" ID is: "<< ID <<endl;
    	return *this;
    };
    
private:
    string  name;
    int ID;
    static   int identifyID;  
    
};
 int Employee::identifyID = 0;
	
ostream & print(ostream & os, Employee &p){
    os << p.name <<" ID is : "<<p.ID ;
    return os;
}

int main(){
    Employee  a(string("Tina"));
    Employee   b=a;// call copy constructor 
    Employee   c("Mike");
    Employee   d;
    d = a;// call assginment =
    print(cout, a) <<endl;
    print(cout, b) <<endl;
    
    print(cout, c) <<endl;
    print(cout, d) <<endl;
    return 1;
}