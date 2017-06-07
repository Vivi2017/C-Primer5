#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;

  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string &s);
  void pop_back();

  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;
 

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type pos, const std::string &msg) const;

};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type pos, const std::string &msg) const {
  if (pos >= data->size())
    throw std::out_of_range(msg);
}

inline void StrBlob::push_back(const std::string &s) {
  data->push_back(s);
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void testStrBlob(StrBlob &sb) {
  try {
    sb.push_back("abc");
    sb.push_back("def");
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.pop_back();
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.pop_back();
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testStrBlob(const StrBlob &sb) {
  try {
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

int main() {
  StrBlob sb1;
  StrBlob sb2{"Hello", "World"};
  StrBlob sb3 = {"Bye", "World"};
  const StrBlob csb1;
  const StrBlob csb2{"This", "Blob"};
  
	StrBlob srb;
	{
	
	 StrBlob sra{"Here","you","are"};
	 srb = sra;
	 cout <<"srb size 110 =" << srb.size() <<endl;
	 sra.push_back("boy");
	 cout <<"sra  size =" << sra.size() <<endl;
	}

  cout <<"srb size 115 =" << srb.size() <<endl;

/*
  testStrBlob(sb1);
  std::cout << std::endl;
  testStrBlob(sb2);
  std::cout << std::endl;
  testStrBlob(sb3);
  std::cout << std::endl;
  testStrBlob(csb1);
  std::cout << std::endl;
  testStrBlob(csb2);
  std::cout << std::endl;
  testStrBlob({"ppp", "qqq"});
  std::cout << std::endl;
  */
  //testStrBlob({"mm", 1});  // Error


  return 0;
}

//123
//No, a const object of this class type should not be able to change the object. Thus we should not define const version of push_back or pop_back. Although the complier does not report errors if we define const versions of push_back and pop_back, it is not logical for a const object.
//124
//Because i is an unsigned type, which means i will always be nonnegative.

//125
/*
//Since we do not make the constructor explicit, the pros are
//we can use = { /* ... */ } to initialize a StrBlob object,
//we can use assignment to assign an initializer list to a StrBlob object,
//we can pass an initializer list to functions who need a StrBlob parameter.
//The cons are
//we may overlook the implicit conversion made by compiler sometime, which may be bug prone.
*/