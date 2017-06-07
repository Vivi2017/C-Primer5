#include <iostream>
#include <string>
using namespace std;
template <typename T>
int compare(const T &v1, const T &v2)
{
	
	    if (v1 < v2)  return -1;
	    if (v2 < v1)  return 1;
	    return 0;
}
//class Sales_data;
int main()
{
	  cout <<"a ? b = "<< compare("a", "b")<<endl;
	   cout <<"3 ? 4 = "<< compare(3, 4)<<endl;
	   cout <<"7.8 ? 5.1 = "<< compare(7.8, 5.1)<<endl;
	   
  cout <<"abc ? abc = "<< compare("abc", "abc")<<endl;
}