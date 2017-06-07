#include <string>
#include <iostream>

using namespace std;

void process(shared_ptr<int> ptr){
    
    cout<<"Value is "<< *ptr <<endl;
}// after process, ptr is not exist, the memory has been release!

int main() {
    
    shared_ptr<int> p (new int(22));
    
    process(p);
    //process(shared_ptr<int>(p.get())); //p.get does not increase the ref of p
    cout<<"P Value is "<< *p <<endl;
    
    auto q = new int();
    auto sp = make_shared<int>();
    
      // (a) OK. Initialize a shared pointer `ptr` inside function `process` as a
  // copy of `sp`, increase the reference count. After the function is
  // executed, destory `ptr` and decrease the reference count.
    process(sp);
    
    // (b) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
    //process(new int());// shared
    // (c) Error. Cannot implicitly convert a ordinary pointer to a smart pointer.
    //process(q);
    
    
      // (d) Error. Initialize a shared pointer `ptr` inside function `process`
  // using ordinary pointer `p`, increase the reference count to 1. After the
  // function is executed, destory `ptr` and decrease the reference count to 0,
  // thus freed the memory pointed by `ptr`. However, the original ordianry
  // pointer `p` still points to that memory.
    process(shared_ptr<int>(q));
    
    
    return 0;
}