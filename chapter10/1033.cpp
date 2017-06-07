#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void saveNumToFiles(std::string inFile, std::string evenF, std::string oddF)
{
	  std::ifstream in(inFile);
	  if (!in.is_open()) {
	    std::cerr << "Can not open file: " << inFile << std::endl;
	    return;
	  }	
	  
		std::istream_iterator<int> iter(in), eof;
		//std::vector<int> intA(iter, eof);
			
		std::ofstream evenO(evenF);
		if (!evenO.is_open()) {
		    std::cerr << "Can not open file: " << evenF << std::endl;
		    return;
	  }	
	  
		std::ofstream oddO(oddF);
		if (!oddO.is_open()) {
	    std::cerr << "Can not open file: " << oddF << std::endl;
	    return;
	  }		
		
		std::ostream_iterator<int> even_iter(evenO, " ");
	  std::ostream_iterator<int> odd_iter(oddO, "\n");	
	  std::for_each(iter, eof, [&](int a){(a%2==1)?even_iter = a:odd_iter = a; });
	  
	 // std::copy_if(intA.begin(), intA.end(), o_iter1, [](int &a){return (a%2==1);}); 
		//std::copy_if(intA.begin(), intA.end(), o_iter2, [](int &a){return (a%2==0);}); 
}

int main() {

	saveNumToFiles("/Users/vivisong/C-Primer5/chapter10/in.num", "/Users/vivisong/C-Primer5/chapter10/even.num", "/Users/vivisong/C-Primer5/chapter10/odd.num");
	return 0;
}