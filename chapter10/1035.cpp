#include <iterator>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	vector<int> vi{0,1,2,3,4,5,6,7,8,9};
	//crbegin vector 
	auto iti = vi.cend();
	
	for(iti = iti-1; iti >=vi.cbegin(); iti--){
		cout << *iti << endl;
	}
	return 0;
}