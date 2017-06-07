#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
	map<string, int> words_count;
	set<string> words;
  std::string filename;
  std::cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Can not open file: " << filename << std::endl;
    return -1;
  }
  std::istream_iterator<std::string> iter(in), eof;

  std::vector<std::string> vs(iter, eof);  // The shorter way
  for (const auto &s: vs){
  	     words.insert(s);
  	  	 auto ret = words_count.insert(map<string, int>::value_type(s, 1 ));
  	  	 if(!ret.second)
  	  	 	   ret.first->second++;
  	  	
    	std::cout << s << std::endl;
    	
    	
    }
   for_each(words.begin(), words.end(), [](const string &word){cout << word << " " ;});
   cout <<endl;
     for_each(words_count.begin(), words_count.end(), 
     [](pair <string, int> p){cout << p.first << " show " <<p.second << " times !" <<endl;});
   
  return 0;
}