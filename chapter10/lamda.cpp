#include <iostream>
// [capture list] (paremeter list) ->return type {function body}
// lamda 表达式可以认为是一个没有名字的内联函数
int main()
{
  int i;
  auto isZero = [&i] () mutable ->bool { return (i > 0 ? i--, true:false) ;};
  std::cin >> i;
  while (isZero())
  {
     std::cout << i << std::endl;
  }
  return 0;
}