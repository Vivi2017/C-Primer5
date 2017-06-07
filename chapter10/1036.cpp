
#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list

using namespace std;

int main_bak(){
	
	  list<int> vi{0,1,0,0,7,1,8,5};
	  //crbegin vector 

	  auto iti = find(vi.crbegin(), vi.crend(), 0);

	 if (*iti == 0)
	      cout <<"The last value "<< *iti << " is at position: " <<distance(iti, vi.crend()) -1 << endl;
	  else
        cout <<"not found "<< 0 <<endl;		

	  return 0;
}
int main(){
  std::vector<int> vi{0, 1, 2, 3, 4, 5, 0};
  auto rit = find(vi.crbegin(), vi.crend(), 0);
  std::cout << "The last " << *rit << " in vector is at position "
      << (rit.base() - vi.cbegin() - 1 )<< std::endl;
      //<< vi.crend() - rit - 1 << std::endl;
  // rit.base() is the iterator one past element 0, just like end iterator
main_bak();
  return 0;
}