#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map

using namespace std;
int main()
{
	 
		 map<int, int > imap;
	   int a, b;
	   
	   while(cin>>a>>b){
		   	
		   auto ir = imap.find(a);
		   if(ir != imap.end()){
		   		ir->second = b;
		   }
		   else{
		   	
		   //	imap.insert({a,b});
		   	imap[a] = b;
		   }
		}
	 
	   for (const auto& kv :imap ) {
	    std::cout << kv.first << " has num: " << kv.second << std::endl;
		}
	   
	  // for_each(imap.begin(), imap.end(), 
	   //         [](std::pair<string, int>  mapPair) { cout <<"The Num of word "<< mapPair.first <<" " << mapPair.second<<endl;});
		return 0;	
	
}
	