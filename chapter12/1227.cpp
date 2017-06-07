#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include <sstream>

using namespace std;
class QueryResult;
class TextQuery;
void runQueries(ifstream &infile);

class TextQuery {
public:
  typedef std::vector<std::string>::size_type line_no_type;

  explicit TextQuery(std::ifstream &in);

  QueryResult query(const std::string &word) const;

private:
  std::shared_ptr<std::vector<std::string>> text;
  std::map<std::string, std::shared_ptr<std::set<line_no_type>>> lines;
};
  
class QueryResult {
public:
    typedef std::vector<std::string>::size_type line_no_type;
    QueryResult(const string keyIn):key(keyIn),total(0),lnNums(),text(){};
        
    QueryResult(const string keyIn, int totalIn, 
             std::shared_ptr<std::set<line_no_type>> lnNumsIn,
             std::shared_ptr<std::vector<std::string>> textIn):
         key(keyIn),total(totalIn),lnNums(lnNumsIn), text(textIn){};
         
friend ostream & print(ostream &osf, QueryResult qr);

private:
    string key;
    int    total;
    std::shared_ptr<std::set<line_no_type>> lnNums;
    std::shared_ptr<std::vector<std::string>> text;
};  

ostream & print(ostream &osf, QueryResult qr){
    if(qr.total ==0) 
        osf << qr.key <<" is not found!";
    else{
        osf << qr.key <<" occurs " << qr.total<<endl;
        for(auto ln:*(qr.lnNums)){
            osf << "line: \t" <<ln+1 << " line text is :\n "<< qr.text->at(ln) <<endl;
       }
    }
    return osf;
}  


TextQuery::TextQuery(ifstream &infile):
    text(std::make_shared<std::vector<std::string>>()),
    lines()
    
{
    line_no_type ln = 0;
    for(string lineT;getline(infile,lineT);text->push_back(lineT),ln++)
    {
        cout <<"line num: \t"<<ln+1<<":\t" <<lineT << endl;
        istringstream iss(lineT);
        for (std::string word; iss >> word; ) {
            if (lines.find(word) == lines.end())
                lines.insert({word, std::make_shared<std::set<line_no_type>>()});
            lines.at(word)->insert(ln);
       }
    }
}

QueryResult TextQuery::query(const std::string &word) const{
    
    auto it = lines.find(word);
    
    if(it == lines.end())
        return QueryResult(word);
    else{
           int total = 0;
           
           for(auto ln:(*(it->second))){
              istringstream iss((*text).at(ln));
               
              for(string wss;iss>>wss;)
              {
                if (wss == word)
                    ++total;
              }
                
           }
            
            return QueryResult(word,total,it->second,text);
    }
        
}
 
  

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    
    while(true){
        cout <<"Please enter the word to look for , or Q to quit:";
        string s;
        if (!(cin >>s) || s == "Q") break;
            
        print(cout, tq.query(s)) << endl;
    }
    return;
};


int main(){
    
    string filename("/Users/vivisong/C-Primer5/chapter12/rule.txt");
    ifstream infile(filename);
    
    if (!infile.is_open()) {
       std::cerr << "Cannot open file: " << filename << std::endl;
       return -1;
    }
    
    runQueries(infile);
    
    return 0;
}