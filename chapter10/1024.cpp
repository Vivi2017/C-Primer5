#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


//bind 
// auto newCallable = bind(callable, arg_list);
//占位符？

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}


bool shorter(const std::string &s, std::string::size_type sz) {
  return s.size() < sz;
}

bool biggerInt(const int &a,const int &b){
  return a > b;
}

void biggies(std::vector<std::string> words,  // use value instead of reference
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  
  auto iter = std::partition(words.begin(), words.end(),
  	       bind(shorter,std::placeholders::_1,sz));
  	//[](const std::string &a, const  std::string &b) {return a.size()<b.size();}
  		
  
  auto count = std::count_if(words.begin(), words.end(),
  	bind(shorter,std::placeholders::_1,sz));
  //[sz](const std::string &a) {return a.size()>sz;});
  	
  int countBig = words.end() - iter;
  
 // std::cout<<" Count of size > " << sz <<" is " << countBig <<std::endl;
    std::cout << count << " " << make_plural(count, "word") << " of length "
            << sz << " or shorter." << std::endl;
            	
  std::for_each(words.begin(), words.end(),
  	[](const std::string &a) {std::cout << a <<" ";});
}

void checkSize(std::vector<int> array, std::string si)
{
     std::stable_sort(array.begin(), array.end(),
//bind(biggerInt, std::placeholders::_1, std::placeholders::_2));
  	     [](const int &a, const  int &b) {std::cout <<"Stable_sort"<< a <<" " << b << std::endl; return a < b;});
  	     	
    auto iter = std::find_if(array.begin(), array.end(),
            bind(shorter,si,std::placeholders::_1));
            	     
    std::cout <<"The first number bigger then "<< si <<" size( "<< si.size() << " ) is " << *iter << std::endl;        	
    std::for_each(array.begin(), array.end(),
  	     [](const int &a) {std::cout << a <<" ";});     
  		     		
    std::cout <<"Finished"<< std::endl;
}

int main() {
	
	 std::string s;
	 std::cout <<"Enter string: "<< std::endl;
	 std::cin >> s;
	 
   std::vector<int> arrayL;
   std::cout <<"Enter Length Array: "<< std::endl;
   for (int i; std::cin >> i; arrayL.push_back(i)) {}

   checkSize(arrayL, s);

  return 0;
} 
