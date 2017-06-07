#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map

using namespace std;
int main()
{
	 
	 map<string, int > wmap;
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  	
  if (words.size() > 0)
  {
  		for_each(words.begin(), words.end(), 
  		         [&](string a){(wmap.find(a) == wmap.end())? wmap[a]=1:wmap[a]++;});
  }
   
   for (const auto& kv : wmap) {
    std::cout << kv.first << " has num: " << kv.second << std::endl;
}
   
   for_each(wmap.begin(), wmap.end(), 
            [](std::pair<string, int>  mapPair) { cout <<"The Num of word "<< mapPair.first <<" " << mapPair.second<<endl;});
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