// 参考サイト：http://stackoverflow.com/questions/2304203/how-to-use-boost-bind-with-a-member-function

#include <iostream>
#include <stdio.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class myclass
{
 public:
  void fun1() { printf("fun1()\n"); }
  void fun2(int i) { printf("fun2(%d)\n", i); }

  void testit()
  {
    boost::function<void()> f1(boost::bind(&myclass::fun1, this));
    boost::function<void(int)> f2(boost::bind(&myclass::fun2, this, _1));

    f1();
    f2(111111111);
  }
};

int main()
{
  myclass mc;
  mc.testit();
  return 0;
}