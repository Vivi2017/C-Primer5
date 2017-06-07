#include <string>
#include <iostream>
using namespace std;

void merge_two_const_charArray(const char *chara1, const char *chara2, char *p){
    
    int len = strlen(chara1)+ strlen(chara2)+1;
    p = new char[len]();
    strcat(p, chara1);
    strcat(p, chara2);
    
    cout<< string(p) << endl;
    
}

void merge_two_const_string(string str1, string str2, char *p){
    
    int len = str1.size()+ str2.size()+1;
    p = new char[len]();
    
    strncpy(p, (str1 + str2).c_str(), len+1);
    cout<< string(p) << endl;
}

int main(){
    const char* c1 = "Hello ";
    const char* c2 = " world!";
    
   char *pc;
    pc= NULL;
    merge_two_const_charArray(c1, c2, pc);
    
    if(pc)
        delete [] pc;
    
    char *ps;
     ps = NULL;
    string str1 = string("C++ primer5 ");
    string str2 = string("is so good!");
    merge_two_const_string(str1, str2, ps);
    
        
    if(ps)
        delete [] ps;
    
    // need to release pc
    return 0;
}