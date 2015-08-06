#include <iostream>
using namespace std;

int main(){
  int size1 = 3;  // 1つ目の要素数を指定 (縦成分)
  int size2 = 10;  // 2つ目の要素数を指定 (横成分)

  int** array = new int* [size1];  //初めに1つ目の配列を作る。

  for (int i = 0; i < size1; i++) {
    array[i] = new int[size2];  // 1つ目の各要素に対して2つ目の配列を作る。
  }  //これで配列array[size1][size2]が使用可能になる。

  // 確保した2次元配列がうまいこと機能するか確認
  for (int i = 0; i < size1; ++i){
    for (int j = 0; j < size2; ++j){
      array[i][j] = i;
    }
  }

  for (int i = 0; i < size1; ++i){
    for (int j = 0; j < size2; ++j){
      cout << array[i][j] << " ";
    }
    cout << "\n";
  }

  //使い終わったらdeleteする。
  for (int i= 0; i<size1; ++i){
    delete array[i];       //作る時の逆で，各要素の2つ目の配列を削除する。
  }
  delete array;

  return 0;
}