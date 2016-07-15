#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> // copy

int main()
{
  std::vector<int> src;
  std::vector<int> dest;
  for (int i=1; i<=5; i++)
  { src.push_back(i); dest.push_back(i*10); }


  // srcの要素をdestに追加しながらコピー
  dest.reserve(src.size());
  std::copy(src.begin(), src.end(), std::back_inserter(dest));

  for ( std::vector<int>::iterator it = dest.begin(); it!= dest.end(); ++it )
    std::cout << *it << std::endl;
}