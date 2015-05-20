#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> ary;

  for (int i = 0; i < 10; i++) {
    vector<int> ar;
    ary.push_back(ar);
    for (int j = 0; j < 10; j++) {
      ary[i].push_back(j);
    }
  }
  //プリントアウト
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << "ary[" << i << "][" << j << "] = " << ary[i][j] << endl;
    }
  }

  return 0;
}
