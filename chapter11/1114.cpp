#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map

using namespace std;
void print_child(map<string, vector<pair<string, string>>> familyMap)
{
	//for_each( familyMap.begin(), familyMap.end(), 
	//	[]( map<string, std::vector<std::string> > iterator &it) { cout <<it->first << "has childs:" <<it->first.size() <<endl; return true;});
 
  for(auto im:familyMap)
  	{
  		 cout <<im.first <<(im.second.size() >1? " have ": " has: ") << im.second.size() << (im.second.size() >1? " children ": " child ")<< endl;
  		 
  		 for_each( im.second.begin(), im.second.end(), 
  		 [&](pair<string, string> childName){ cout <<"    "<< childName.first + " "+ im.first<< " was born on " << childName.second <<endl;});
  	}
}
void add_family(map<string, vector<pair<string, string>>>&familyMap, string fn){
		if (familyMap.find(fn) != familyMap.end()){
				
				cout << " Family "<<fn <<" already in map !"<<endl;
			
		}else {
			familyMap.insert({fn, vector<pair<string, string>>()});
				cout << " Family "<<fn <<" is added !"<<endl;
		}
		
}


void add_child(map<string, vector<pair<string, string>>> &familyMap, string fn, string cn, string birth){
		if (familyMap.find(fn) != familyMap.end()) {
			
				cout << " Family "<<fn <<" add new child ! "<< cn << " and birday is " << birth << endl;
				if(find(familyMap[fn].begin(), familyMap[fn].end(), make_pair(cn,birth)) == familyMap[fn].end())
			    familyMap[fn].push_back(make_pair(cn,birth));
			  else
			    cout << " Family "<<fn <<" already have "<< cn <<endl;
		    
		}else{
			cout << " No Family "<< fn <<" for child !"<< cn << endl;

		}
}

int main(){
		map<string, vector<pair<string, string>>> familyMap;
		
		// for (std::string fn,cn; std::cin >> cn >> fn;){
		//	familyMap[fn].push_back(cn);
		//	}
		add_family(familyMap, "Zhang");
		add_family(familyMap, "Li");
		add_family(familyMap, "Wang");
		add_family(familyMap, "Zhang");  // Error
		
		add_child(familyMap, "Zhang", "San", "1990-3-1");
		add_child(familyMap, "Zhang", "Bao","1990-3-2");
		add_child(familyMap, "Zhang", "Tian","1990-3-3");
		add_child(familyMap, "Li", "Si","1990-3-4");
		add_child(familyMap, "Wang", "Wu","1990-3-5");
		add_child(familyMap, "Wang", "San","1990-3-6");
		add_child(familyMap, "Zhao", "Liu","1990-3-7");  // Error
		add_child(familyMap, "Wang", "San","1990-3-8");	
		
		
		cout << "Print family tree: "<<endl;
		
		print_child(familyMap);
		
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