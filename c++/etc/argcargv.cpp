#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int i;
	string a = "add/";
	printf("引数の総個数 = %d\n", argc);
	for (i = 0; i < argc; i++) {
		string moji = string(argv[i]);
		cout << i <<"番目の引数 = " << a+moji << endl;
	}

	return 0;
}