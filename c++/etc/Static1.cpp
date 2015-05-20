#include <iostream>
#include <algorithm>
using namespace std;

/*-----------------------------------アドレスが常に一定かのチェック-----------------------------------*/
void CheckAddress_Sub();
void CheckAddress_Sub2();

void CheckAddress(){
	cout << "アドレスが常に一定かのチェック" << endl;

	CheckAddress_Sub();
	CheckAddress_Sub2();
	CheckAddress_Sub();
}

//静的変数 a と自動変数 b のアドレスを出力
void CheckAddress_Sub(){
	static int a;
	int b;

	cout << "&a =" << (size_t)&a << endl
		 << "&b =" << (size_t)&b << endl;
}

//この関数の中から CheckAddress_Sub を呼んだ時に
//変数aとbのアドレスがどうなるかチェック
void CheckAddress_Sub2(){
	cout << "in Sub2" << endl;
	CheckAddress_Sub();
}

/*--------------------------------初期化が一回しかされないかチェック-----------------------------------*/
void CheckInitOnce_Sub();

void CheckInitOnce(){
	cout << endl << "初回化が1回しかされないかのチェック" << endl;

	CheckInitOnce_Sub();
	CheckInitOnce_Sub();
}

/*--------------------++aと++bの影響が2度目以降の呼び出しに影響するかチェック--------------------------*/
void CheckInitOnce_Sub(){
	static int a = 3;
	int b = 3;

	cout << "a = " << a << endl
		 << "b = " << b << endl;
	++a;
	++b;
}

/*-------------------------------0で初期化されるかのチェック-------------------------------------------*/
void CheckZeroInit_Sub();
void CheckZeroInit_Sub2();

void CheckZeroInit(){
	cout << endl << "0で初期化されるかのチェック" <<endl;

	CheckZeroInit_Sub();
	CheckZeroInit_Sub2();
}

//静的変数が何で初期化されているかをチェック
void CheckZeroInit_Sub(){
	static int a, b, c, d;

	cout << a << ',' << b << ',' << c << ',' << d << endl;
}

//自動変数が何で初期化されているかをチェック
void CheckZeroInit_Sub2(){
	int a, b, c, d;

	cout << a << ',' << b << ',' << c << ',' << d << endl;
}

/*-------------------------------値が保証されるかのチェック--------------------------------------------*/
void CheckInvariant_Sub(int*& pa, int*& pb);
void CheckInvariant_Sub2();

void CheckInvariant(){
	cout << endl << "値が保証されるかのチェック" << endl;

	int *pa, *pb;
	CheckInvariant_Sub(pa, pb);
	CheckInvariant_Sub2();

	cout << "*pa = " << *pa << endl
		 << "*pb = " << *pb << endl;
}

void CheckInvariant_Sub(int*& pa, int*& pb){
	static int a = 9;
	int b = 9;
	pa = &a;
	pb = &b;
}

void CheckInvariant_Sub2(){
	int dummy[100];
	fill_n(dummy, 100, 0);
}

int main(){
	CheckAddress();
	CheckInitOnce();
	CheckZeroInit();
	CheckInvariant();

	return 0;
}