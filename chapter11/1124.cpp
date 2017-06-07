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
	map<int,int> mt;
	 cout <<" my size = "<<mt.size() <<endl;
	mt[0] = 1;
	 cout <<" map [0 ]= " << mt[0] << " mt size = " <<mt.size() << endl;
	 
	 
	 
  vector<int>	vt;
  cout <<" vt size = " <<vt.size() <<endl;
  vt[0] = 1;// will cause segmentation fault   The code will cause error. Because the subscript operator accesses element that not existed, the behaviour is undefined.
  //Unlike std::map::operator[], this operator never inserts a new element into the container.
 
  cout <<" vector[ 0 ]= " << vt[0] << " vt size = " <<vt.size() <<endl;
  //A type which can be used as a key_type can be used to subscript a map. The subscript operator return mapped_type. For example:
}