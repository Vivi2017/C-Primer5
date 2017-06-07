#include <string>
#include <iostream>
#include <vector>

using namespace std;
class destination{
    public:
        destination(string des):name(des){};
        string     name;
};

class connection{
    public:
    
    connection(destination d):des(d){};
    ~connection();
    destination des;
};

connection connect(destination *d){
    cout <<"Connect to "<< d->name << endl;
    return connection(*d);
}

void disconnect(connection *c){
    cout <<"Disonnect to "<< c->des.name << endl;
}

connection::~connection(){
      cout<<"connection destructor"<<endl;
}


typedef  shared_ptr<connection>  spconnection;
typedef  unique_ptr<connection, decltype(disconnect)*>  upconnection;



void test_sp(){
    destination d = destination(string("destination1"));
    connection c = connect(&d);
   // shared_ptr<connection> csp = shared_ptr<connection>(&c,disconnect); 
   spconnection csp = spconnection(&c,[](connection *p){disconnect(p);});   
    
   vector<spconnection> vsp;
    vsp.push_back(csp); 
}

void test_up(){
    destination d = destination(string("destination1"));
    connection c = connect(&d);
    // shared_ptr<connection> csp = shared_ptr<connection>(&c,disconnect); 
    upconnection cup = upconnection(&c, disconnect);
    vector<upconnection> vup; 
    //vup.push_back(cup); //It is wrong , because cup is unique_ptr, can not copy to vup!!!!!
    vup.push_back(move(cup));
}


auto lauto_test( int t)
{
    cout <<"T value is "<<t<<endl;
    bool re = true;
    return re;
}
typedef unique_ptr<int> IntP;

int main(){
    int ix=1024;
    int *pi = &ix;
    int *pi2 =new int(2048);
    
    //IntP p0(ix);// build wrong
    IntP p1(pi);//build ok,but illegal, p1 is smart pointer , pi is not dynamiclly allocted in heap, it can not be freed by
    //a smart pointer
      
    IntP p2(pi2);//ok , and notice if p2 is released , pi2 can not be visited again
   IntP p3(&ix); //wrong,but illegal same with  IntP p1(pi)
   IntP p4(new int(2048));//ok
   IntP p5(p2.get());
   
    // (f) Can be compiled, but will result error. Two unique pointers point to
  // the same memory, so that the memory will be freed twice when these
  // pointers are destoryed.
    return 0;
}


