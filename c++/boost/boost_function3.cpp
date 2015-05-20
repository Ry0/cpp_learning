#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::function<int(int, int)> TestFunction;

int Sum(int a, int b) { return a + b; }

int main()
{
  TestFunction Tf;
  int Result = 0;

  // ここでboost::bindを使用しています。
  // 引数に_1, _2が使われています。
  Tf = boost::bind(&Sum, _1, _2);
  Result = Tf(2, 5);

  std::cout << "結果は" << Result << "でした。" << std::endl;
  return 0;
}