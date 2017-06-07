#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> words,  // use value instead of reference
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  
  std::stable_sort(words.begin(), words.end(),
  	[](const std::string &a, const  std::string &b) {return a.size()<b.size();});
  
  auto iter = std::find_if(words.begin(), words.end(),
  [sz](const std::string &a) {return a.size()>sz;});
  	
  int countBig = words.end() - iter;
  
  std::cout<<" Count of size > " << sz <<" is " << countBig <<std::endl;
  
  std::for_each(iter, words.end(),
  	[](const std::string &a) {std::cout << a <<" ";});
}

int main() {
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  biggies(words, 3);
  std::cout << std::endl;
  biggies(words, 5);

  return 0;
}