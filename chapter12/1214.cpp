#include <string>
#include <iostream>

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

void test_sp(){
    destination d = destination(string("destination1"));
    connection c = connect(&d);
   // shared_ptr<connection> csp = shared_ptr<connection>(&c,disconnect); 
    shared_ptr<connection> csp = shared_ptr<connection>(&c,[](connection *p){disconnect(p);});   
}

auto lamda_test( int t)
{
    cout <<"T value is "<<t<<endl;
    bool re = true;
    return re;
}
int main(){
    test_sp();
    return 0;
}


