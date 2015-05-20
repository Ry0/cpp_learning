#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  vector<char> alphaVector;
  for (int i = 0; i < 20; i++) {
    alphaVector.push_back(i + 65);
  }

  // int size = alphaVector.size();
  vector<char>::iterator startIterator;
  vector<char>::iterator endIterator;
  vector<char>::iterator tempIterator;

  cout << "削除前" << endl;
  for (tempIterator = alphaVector.begin(); tempIterator != alphaVector.end(); tempIterator++) {
    cout << *tempIterator;
  }
  cout << endl;

  startIterator = alphaVector.begin();
  alphaVector.erase(alphaVector.begin() + 4+1, alphaVector.begin() + 9);

  // ベクタを表示する
  cout << "\n削除後" << endl;
  for (tempIterator = alphaVector.begin(); tempIterator != alphaVector.end(); tempIterator++) {
    cout << *tempIterator;
  }
  cout << endl;
  // for( tempIterator = alphaVector.begin(); tempIterator != alphaVector.end(); tempIterator++ ){
  // 	cout << *tempIterator;
  // }
  alphaVector.push_back(70);

  cout << "\n更にプッシュバック" << endl;
  for (tempIterator = alphaVector.begin(); tempIterator != alphaVector.end(); tempIterator++) {
    cout << *tempIterator;
  }
  cout << endl;

  return 0;
}