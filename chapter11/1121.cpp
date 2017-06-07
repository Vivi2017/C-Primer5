#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
	map<string, int> words_count;
	
	string s;
	while(cin>>s){
		
		++words_count.insert(make_pair(s,0)).first->second;

	}
		
		for_each(words_count.begin(), words_count.end(), 
     [](map<string, int>::value_type p){cout << p.first << " show " <<p.second << " times !" <<endl;});
}