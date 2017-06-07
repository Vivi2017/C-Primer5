#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map

using namespace std;
//void add_child(map<string, std::vector<std::string> > &familyMap, string familyName, string childName)
//{
//}
int main()
{
	 
	 map<string, std::vector<std::string> > familyMap;
   std::vector<std::string> words;
   for (std::string fn,cn; std::cin >> fn >>cn;
   	[&](){familyMap[fn].push_back[cn]} ) {};
  	
  
	return 0;	
	
}
/*

A list may be used when we need to insert/delete at the middle frequently, such as a linked list.

A vector may be used when we need random-access, such as a dynamic normal array.

A deque may be used like a queue.

A map may be used like a dictionary.

A set may be used to check whether a value is present.

A map is an associative container which contains an associative array of key-value pairs. Values are found by key. The key doesn't have to be integer.

A vector is an sequential container which contains a normal array of values. Values are found by position. The position is integer.
*/