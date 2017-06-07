#include <iterator>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	vector<int> vi{0,1,2,3,4,5,6,7,8,9};
	//crbegin vector 
	
	for(auto iti = vi.crbegin();iti <vi.crend();iti++){
		cout << *iti << endl;
	}
	return 0;
}