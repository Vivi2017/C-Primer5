#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

pair<map<string, vector<int>>::iterator, bool> insert_new(map<string, vector<int>> &records, string player, vector<int> record)
{
	
	return records.insert(make_pair(player, record));
}

int main() {
	map<string, vector<int>> words_count;
	string player("Cici");
	vector<int> record{1,2,3,4};
	
	pair<map<string, vector<int>>::iterator, bool> ret = insert_new(words_count, player,record);
	 
	 cout << ret.first->first << " has records as :"<< endl;
	 
	 for(auto &i : (ret.first->second))
	 	{
	 		 cout<< i << endl;
	 	}
 
		 
}