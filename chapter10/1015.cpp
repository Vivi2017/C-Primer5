#include <iostream>
// [capture list] (paremeter list) ->return type {function body}
// lamda 表达式可以认为是一个没有名字的内联函数
int main()
{
  
  
  int i,j;
 
  std::cout << "Please input two ints:"<< std::endl;
  // auto sumTwo = [i] (int j) ->int { std::cout<< std::endl << " Input "<< i <<" and "<<j << std::endl; return (i + j) ; };//	
  // if we put sum here  i is zero
  std::cin >>i >>j;
    // The lamda must be defined after we read x, otherwise it will capture the
  // undefined value of x.	
  auto sum = [i] (int j) ->int { std::cout<< std::endl << " Input "<< i <<" and "<<j << std::endl; return (i + j) ; };

  std::cout << "sum "<<i <<" and "<<j<<" is " << sum(j) << std::endl;
  
  return 0;
}