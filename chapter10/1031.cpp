#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main() {

  std::istream_iterator<int> iter(std::cin), eof;

  std::vector<int> ints(iter, eof);  // The shorter waycontrol+D
  std::sort(ints.begin(), ints.end());
  	 
  std::ostream_iterator<int> o_iter1(std::cout, " ");
  std::copy(ints.begin(), ints.end(), o_iter1); 	 
  std::cout << std::endl;
  	 		
  std::ostream_iterator<int> o_iter(std::cout, " ");
  std::unique_copy(ints.begin(), ints.end(), o_iter); 
  std::cout << std::endl;
  	
  return 0;
}