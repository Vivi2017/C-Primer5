#include <string>
#include <iostream>
using namespace std;

int main(){
    int len;
    cout <<" Please enter the length of string:"<<endl;
    cin>>len;
    cin.ignore();
    
    char *p = new char[len+1]();
   // char *q =p;
    char c;
    /* 
    while(cin>>c)
    {
        *(q++) = c;
    }
     cout <<" The input string lengh is :"<<strlen(p)<<endl;
    cout<< string(p)<<endl;
    
    */
    
    cin.get(p, len+1);
    cout <<p<<endl;
    delete [] p;
    return 0;
}