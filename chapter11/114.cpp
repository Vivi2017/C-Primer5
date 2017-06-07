#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map
#include <string>
#include <fstream>
#include <locale>         // std::locale, std::tolower

using namespace std;
int main_bak()
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

string trimStringP(string sin)
{
	
	const auto last = sin.find_last_not_of("\"'`:*-_;,.?!()[]{}");
	const auto first = sin.find_first_not_of("\"'`:*-_;,.?!()[]{}");
	
  cout <<"The punctuations begins at: " << last << endl;
  
 if ((last == std::string::npos ) && (first != std::string::npos))
			return sin.substr(first,sin.size());
 else if ((last != std::string::npos ) && (first != std::string::npos))
 	    return sin.substr(first,last+1);
 else
 	    return "";
}

int main(){
	
  //std::string filename;
  //std::cin >> filename;
  std::ifstream in("/Users/vivisong/C-Primer5/chapter10/test.txt");
 
  if (!in.is_open()) {
    std::cerr << "Can not open file: /Users/vivisong/C-Primer5/chapter10/test.txt" << std::endl;
    return -1;
  }
  
  std::istream_iterator<std::string> iter(in), eof;

  std::vector<std::string> vs(iter, eof);  // The shorter way
  std::map<string, int > wmap;
  	
  for (auto &s: vs){
       std::cout << s << std::endl;
    	
    	 std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c);});
    	 	
    	 string key = trimStringP(s);
    	 if (key.size() == 0) continue;
    	 	
    	 if ((wmap.find(key) == wmap.end()))
    	 {	
    	 		wmap[key] = 1;	
    	 }else{
    	 		wmap[key]++;
    	 }
   }
   
    
     for (const auto& kv : wmap) {
        std::cout << kv.first << " has num: " << kv.second << std::endl;
    }
    	

  return 0;
}