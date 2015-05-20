#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::function<int()> TestFunction;

class Sample
{
 public:
  Sample() { Val = 5; }
  int GetVal() { return Val; }
  int Val;
};

int main()
{
  TestFunction Tf;
  Sample Smp;
  int Result = 0;

  // ここでboost::bindを使用しています。
  Tf = boost::bind(&Sample::GetVal, Smp);
  Result = Tf();

  std::cout << "結果は" << Result << "でした。" << std::endl;
  return 0;
}
