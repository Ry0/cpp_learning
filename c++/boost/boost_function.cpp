#include <iostream>
#include <boost/function.hpp>

typedef boost::function<int(int, int)> TestFunction;

int sum(int a, int b) { return a + b; }

int main()
{
  TestFunction Tf;
  int Result = 0;

  Tf = &sum;
  Result = Tf(2, 5);

  std::cout << "結果は" << Result << "でした。" << std::endl;
  return 0;
}