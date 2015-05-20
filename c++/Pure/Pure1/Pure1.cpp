#include "InputStream.h"
#include <iostream>
using namespace std;


int main(){
	InputStream istream;

	cout << "> " << flush;
	istream.Set();
	cout << istream.Get() << endl;
}
