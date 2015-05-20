#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Add(std::stringstream& sstr, int x, int y){
  sstr.str("");
  sstr << x << " + " << y << " = " << (x + y) << flush;
}

int main(){
  stringstream sstr;

  Add(sstr, 2, 4);
  cout << sstr.str() << endl;
  Add(sstr, 4, 8);
  cout << sstr.str() << endl;
}