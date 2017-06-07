#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map
#include <utility>         //

using namespace std;


int main(){
		
		std::vector<pair<string, int>> sipVec;
		string sin;
		int iin;
		
		while(cin >> iin >> sin)
		{
			
			//pair<string, int> sip = {sin, iin};//First pair<Type, Type> p = {a,b}
			
			// pair<string, int> sip(sin,iin); //Second  pair<Type, Type> p(a,b)
			
			//pair<string, int> sip = make_pair(sin, iin); //Third 
			auto sip = make_pair(sin, iin); //Third 
			
			sipVec.push_back(sip);
			
	  }
	
		for_each(sipVec.begin(), sipVec.end(), 
		[](pair<string, int> &p){cout <<p.first <<" = " << p.second <<endl;});
		
		return 0;	

}
/*

A list may be used when we need to insert/delete at the middle frequently, such as a linked list.

A vector may be used when we need random-access, such as a dynamic normal array.

A deque may be used like a queue.

A map may be used like a dictionary.

A set may be used to check whether a value is present.

A map is an associative container which contains an associative array of key-value pairs. Values are found by key. The key doesn't have to be integer.

A vector is an sequential container which contains a normal array of values. Values are found by position. The position is integer.
*/