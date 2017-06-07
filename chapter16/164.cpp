#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>

template <typename T1,  typename T2>
T1 find_item( T1 begin,  T1 end,  T2 v3) {
	for( ;begin!=end; begin++)
    {
	        if ( *begin ==v3)
	        	return begin;
  	}
  	return end;
};

int main(){
	
std::vector<int> vi{1, 2, 3, 4, 5};
	auto it = find_item(vi.begin(), vi.end(), 3);
	if (it !=vi.end())
		std::cout << *it <<std::endl;
	else
		std::cout << "Not found!"<<std::endl;
			
			
		it = find_item(vi.begin(), vi.end(), 7);
	if (it !=vi.end())
		std::cout << *it <<std::endl;
	else
		std::cout << "Not found!"<<std::endl;
}