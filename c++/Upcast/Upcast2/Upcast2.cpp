#include "InputStream.h"
#include "ArrayStream.h"
#include <iostream>
using namespace std;

void Show(const Stream& stream){
	cout << stream.Get() << endl;
}

int main(){
	InputStream istream;

	cout << "> " << flush;
	istream.Set();
	Show(istream);

	static const double ARRAY[] = {4, -1};
	ArrayStream astream(ARRAY);
	astream.Set();
	Show(astream);
}
