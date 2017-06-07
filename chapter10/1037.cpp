#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list
#include <algorithm>

using namespace std;
void rcopy(vector <int>veci,list<int> &listO, int from , int to)
{
	
	   auto rfrom = veci.crbegin()+ (veci.size() - to) - 1;
	   auto rto = veci.crbegin()+ (veci.size() - from);
	   
	   copy(rfrom,rto,back_inserter(listO));

}
list<int> rcopy2(vector <int>veci, int from , int to) //how to initial a list from a vector
{
	
  list<int> listO(veci.rbegin() + (veci.size() - to -1 ), veci.rend()- from);
  for (const auto &i : listO)
    std::cout << i << " ";
    	cout <<endl;
    	
    	return listO;

}

int main(){
	
		std::vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		for_each(vi.begin(), vi.end(), [](int &a){cout << a << " ";});
		cout <<endl;
		std::list<int> li{};
		
		rcopy(vi, li, 3, 7);
		
		for_each(li.begin(), li.end(), [](int &a){cout << a << endl;});

		li = rcopy2(vi, 3, 7); 
		
    return 0;
}