#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	vector<char> alphaVector;
	for( int i=0; i < 20; i++ ){
		alphaVector.push_back( i + 65 );
	}

	int size = alphaVector.size();
	vector<char>::iterator startIterator;
	vector<char>::iterator tempIterator;

	for( int i=0; i < size; i++ ) {
		startIterator = alphaVector.begin();
		alphaVector.erase( startIterator );

		// ベクタを表示する
		for( tempIterator = alphaVector.begin(); tempIterator != alphaVector.end(); tempIterator++ )
			cout << *tempIterator;
		cout << endl;
	}
	return 0;
}