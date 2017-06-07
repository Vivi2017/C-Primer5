#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main() {

  std::istream_iterator<int> iter(std::cin), eof;

  std::vector<int> ints(iter, eof);  // The shorter way  control+D
  std::sort(ints.begin(),  ints.end());
  	 	
  std::ostream_iterator<int> o_iter(std::cout, ",");
  std::copy(ints.begin(), ints.end(), o_iter);
  	
  return 0;
}