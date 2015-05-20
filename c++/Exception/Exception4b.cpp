#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void Error(){
  int* p = NULL;
  try {
    p = new int[10];
    throw "エラー発生！";
    delete[] p;
  } catch(const char* error){
    cerr << "メモリを解放します" << endl;
    delete[] p;
    throw error;
  }
}


int main()
{
  try {
    Error();
  } catch (const char* error) {
    cerr << error << endl;
  }
  return 0;
}