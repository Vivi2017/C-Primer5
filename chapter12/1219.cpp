#include <string>
#include <iostream>
class StrBolbPtr;
class StrBob{
    friend class StrBolbPtr;
    StrBolbPtr  begin() { return StrBlobPtr(*this);}
    StrBolbPtr  end() { auto ret =  StrBlobPtr(*this, data->size());}
    string data;
}

class StrBolbPtr{
public:
    StrBlobPtr():curr(0){ }
    StrBolPtr(StrBob &a, size_t sz = 0):
        wptr(a.data), cuur(sz){}
    std::string&  deref() const;
    StrBolbPtr&   incr();
private:
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
}


std::shared_ptr<std::vector<std::string>> 
        StrBolbPtr::check(std::size_t i, const std::string &msg) const{
   auto ret = wptr.lock();
   if(!ret)   
       throw runtime_error("unbound StrBlobPtr"); 
   if(i >= ret->size())
       throw out_of_range(msg);
   return ret;  //return shared_ptr;
}

string& StrBlcbPtr::deref() const{
    
    auto p =  check(curr, "dereference past end");
    return (*p)[curr]
}

StrBlobPtr& StrBlobPtr::incr(){
    
    check(curr, "increment past end of StrBolbPtr");
    ++curr;
    return *this;
}
int main()
{
    
    return 0;    
    
    
}


