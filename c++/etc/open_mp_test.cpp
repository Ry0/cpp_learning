#include <iostream>
#include <omp.h>
#define N 10
using namespace std;

int main(){
#ifdef _OPENMP
#pragma omp parallel for
#endif
  for (int i = 0; i < N; i++) {
    //ここの処理を書く
    cout << "1:" <<i << endl;
  }
#ifdef _OPENMP
#pragma omp parallel for
#endif
  for (int i = 0; i < N; i++) {
    //ここの処理を書く
    cout << "2:" << i << endl;
  }
#ifdef _OPENMP
#pragma omp parallel for
#endif
  for (int i = 0; i < N; i++) {
    //ここの処理を書く
    cout << "3:" << i << endl;
    }
  return 0;
}