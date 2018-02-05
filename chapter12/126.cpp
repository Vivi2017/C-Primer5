#include <vector>
#include <iostream>

using namespace std;

auto  getIntVector()
{
   return  new vector<int>{ } ;
}
auto make_shared_vec()
{
	return make_shared<vector<int>>(vector<int>{} );
}

auto setIntVector( shared_ptr<vector<int >> vec){
	   
	   for ( int x; cout << "Please enter a integer: ",  cin >> x ; vec->push_back( x ) );
	   
	   return vec;

	}
	
	void printf_vec( shared_ptr<vector<int >> vec){
		 cout << "Print all integers in vector : " <<endl;
	   for(int i = 0 ; i  < vec->size(); i ++)
	   {
	   	 cout <<  vec->at(i) <<endl;
	   	}
	   	return;
	}

int main() {
  //  auto  vecInt = setIntVector( getIntVector());
    auto  vecInt = setIntVector(make_shared_vec());
    printf_vec( vecInt );
    //delete vecInt;
    return 0;

}