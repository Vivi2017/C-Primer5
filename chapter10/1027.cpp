#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <set>

void removeSpace()
{
    std::string s1 = "The      string    with many       spaces!";
    std::cout << "before: " << s1 << '\n';
 
    std::string s2;
    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                     [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });
 
    std::cout << "after:  " << s2 << '\n';	
}

void inserterT()
{
	std::multiset<int> s {1, 2, 3};
 
    // std::inserter is commonly used with sets
    std::fill_n(std::inserter(s, s.end()), 5, 2);
 
    for (int n : s)
        std::cout << n << ' ';
    std::cout << '\n';
 
    std::vector<int> d {100, 200, 300};
    std::vector<int> l {1, 2, 3, 4, 5};
 
    // when inserting in a sequence container, insertion point advances
    // because each std::insert_iterator::operator= updates the target iterator
    std::copy(d.begin(), d.end(), std::inserter(l, std::next(l.begin())));
 
    for (int n : l)
        std::cout << n << ' ';
    std::cout << '\n';
	
}
	
int main()
{

		std::vector<int> arrayL{1,2,3,4,5,6,7, 8, 9};
		std::cout <<" Array: "<< std::endl;
		std::for_each(arrayL.begin(), arrayL.end(),
  					[](const int &a) {std::cout << a <<" ";});
 	
		std::sort(arrayL.begin(), arrayL.end());
			
		std::cout <<" \n Array after sort: "<< std::endl;
		std::for_each(arrayL.begin(), arrayL.end(),
  								[](const int &a) {std::cout << a <<" ";});	
  									
  	std::list<int> listN{11};
  	std::unique_copy(arrayL.begin(), arrayL.end(), std::inserter(listN, std::next(listN.begin())));
  	std::cout <<"  \n inserter copy: "<< std::endl;						
  			std::for_each(listN.begin(), listN.end(),
  								[](const int &a) {std::cout << a <<" ";});	
  									
   	std::list<int> listN2{0};
  	std::unique_copy(arrayL.begin(), arrayL.end(), std::back_inserter(listN2));   	
    	std::cout <<"  \n back_inserter copy: "<< std::endl;						
  			std::for_each(listN2.begin(), listN2.end(),
  								[](const int &a) {std::cout << a <<" ";});	 
  									
   	std::list<int> listN3{0};
  	std::unique_copy(arrayL.begin(), arrayL.end(), std::front_inserter(listN3));   	
    std::cout <<"  \n front_inserter copy: "<< std::endl;						
    std::for_each(listN3.begin(), listN3.end(),
  								[](const int &a) {std::cout << a <<" ";});	 
  									
  								//	inserterT();  									
}