#include <vector>
#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <map>         // std::map
#include <string>
#include <fstream>
#include <locale>         // std::locale, std::tolower
#include <sstream>

using namespace std;

string trimStringP(string sin)
{
	
	const auto last = sin.find_last_not_of("\"'`:*-_;,.?!()[]{}");
	const auto first = sin.find_first_not_of("\"'`:*-_;,.?!()[]{}");
	
  cout <<"The punctuations begins at: " << last << endl;
  
 if ((last == std::string::npos ) && (first != std::string::npos))
			return sin.substr(first,sin.size());
 else if ((last != std::string::npos ) && (first != std::string::npos))
 	    return sin.substr(first,last+1);
 else
 	    return "";
}


void build_map( std::map<string, string> &rule_map, ifstream &rule_file)
{
	string  key;
	string  value;
	while(rule_file>>key && getline(rule_file,value))
	{
			if (value.size() > 1){
					int pos  = value.find_first_not_of(" ");
					//rule_map[key] = value.substr(pos);
					if (pos < value.size()){
						rule_map.insert({key,value.substr(pos)});
						cout << "  " << key << "\t：" << rule_map[key] << endl;
				 	}
				 	else{
						cout << "No value for key " << key << endl;
				 }
			}
			else{
				cout << "No value for key " << key << endl;
			}
	}
		
}

void transformByRules(ifstream &rule_file, ifstream &fin, ofstream &fout)
{
     std::map<string, string> ruleM;
     build_map(ruleM, rule_file);
     
     string  text;
     bool firstword = true;
     std::ostream_iterator<string> o_iter(fout, "");
     while(getline(fin,text)){
     	   firstword = true;
         cout << text <<endl;
         istringstream sstream(text);
         string word;
         
         while(sstream>>word){
         	  //1. use find
         		if (ruleM.find(word) != ruleM.end()){
         			  word = ruleM[word];
         	  }
         	 // 2. use map[key], word not in ruleM will dispear
         	 // word = ruleM[word];
         	  if (firstword == false){
         	     *o_iter = " " + word;
         	   }
         	   else
         	   {
         	   	 firstword =  false;
         	   	 *o_iter = word;
         	   }
         }
         *o_iter = "\n";

    }
 

}
int main(){
		ifstream    rule_file("/Users/vivisong/C-Primer5/chapter11/rule.txt");
		ifstream    fin("/Users/vivisong/C-Primer5/chapter11/in.txt");
		ofstream    fout("/Users/vivisong/C-Primer5/chapter11/out.txt");

    transformByRules(rule_file, fin, fout);
  
    return 0;
}