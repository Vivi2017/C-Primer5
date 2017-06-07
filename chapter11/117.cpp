#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map

using namespace std;
void print_child(map<string, std::vector<std::string> > familyMap)
{
	//for_each( familyMap.begin(), familyMap.end(), 
	//	[]( map<string, std::vector<std::string> > iterator &it) { cout <<it->first << "has childs:" <<it->first.size() <<endl; return true;});
 
  for(auto im:familyMap)
  	{
  		 cout <<im.first <<(im.second.size() >1? " have ": " has: ") << im.second.size() << (im.second.size() >1? " children ": " child ")<< endl;
  		 
  		 for_each( im.second.begin(), im.second.end(), 
  		 [&](string childName){ cout <<"    "<< childName + " "+ im.first<< endl;});
  	}
}
void add_family(map<string, std::vector<std::string> > &familyMap, string fn){
		if (familyMap.find(fn) != familyMap.end()){
				
				cout << " Family "<<fn <<" already in map !"<<endl;
			
		}else {
			familyMap.insert({fn, std::vector<std::string>()});
				cout << " Family "<<fn <<" is added !"<<endl;
		}
		
}


void add_child(map<string, std::vector<std::string> > &familyMap, string fn, string cn){
		if (familyMap.find(fn) != familyMap.end()) {
			
				cout << " Family "<<fn <<" add new child ! "<< cn <<endl;
				if(find(familyMap[fn].begin(), familyMap[fn].end(), cn) == familyMap[fn].end())
			    familyMap[fn].push_back(cn);
			  else
			    cout << " Family "<<fn <<" already have "<< cn <<endl;
		    
		}else{
			cout << " No Family "<< fn <<" for child !"<< cn << endl;

		}
}

int main(){
		map<string, std::vector<std::string> > familyMap;
		std::vector<std::string> words;
		
		// for (std::string fn,cn; std::cin >> cn >> fn;){
		//	familyMap[fn].push_back(cn);
		//	}
		add_family(familyMap, "Zhang");
		add_family(familyMap, "Li");
		add_family(familyMap, "Wang");
		add_family(familyMap, "Zhang");  // Error
		
		add_child(familyMap, "Zhang", "San");
		add_child(familyMap, "Zhang", "Bao");
		add_child(familyMap, "Zhang", "Tian");
		add_child(familyMap, "Li", "Si");
		add_child(familyMap, "Wang", "Wu");
		add_child(familyMap, "Wang", "San");
		add_child(familyMap, "Zhao", "Liu");  // Error
		add_child(familyMap, "Wang", "San");	
		
		
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