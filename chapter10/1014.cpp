#include <iostream>
// [capture list] (paremeter list) ->return type {function body}
// lamda 表达式可以认为是一个没有名字的内联函数
int main()
{
  
  auto sum = [] (int i,int j) ->int { return (i + j) ;};
  int i,j;
 
  std::cout << "Please input two ints:"<< std::endl;
  	
  std::cin >> i >>j;
  
  std::cout << sum(i,j) << std::endl;
  
  return 0;
}