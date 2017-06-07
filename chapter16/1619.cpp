#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

template <typename cont>
void print_container(cont & c)
{
	cout <<" Contents of container: " <<endl;
	for(typename cont::size_type i =0; i < c.size(); i++)
		cout << c.at(i) <<"  ";
		
	  cout <<endl;	
	
}

template <typename cont>
void print(cont & c)
{
	cout <<" Contents of container: " <<endl;
	auto bi = c.begin();
	auto ei = c.end();
	for(;bi < ei; bi++)
		cout <<*bi<<"  ";
		
	  cout <<endl;	
	
}
int main(){
	
	   vector<int> vi{2,3,4,5,6};
	   print_container(vi);
	   print(vi);

	   vector<double> dbi{2.3,3.4,4.5,5.6,6.7};
	   print_container(dbi);	
	    print(dbi); 

	   vector<string> si{"My", "love"};
	   print_container(si);	 	
	    print(si);   
	   deque <int>     di{7,8,9};
	   print_container(di);
print(di); 
	
	   
	   
	
}