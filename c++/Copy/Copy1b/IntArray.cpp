#include "IntArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

IntArray::IntArray(int size){
	m_array = new int[size];
	m_size = size;

	cout << "コンストラクタが呼ばれました。" << "要素数は " << m_size << "です。" << endl;
}

IntArray::~IntArray(){
	delete [] m_array;

	cout << "デストラクタが呼ばれました。" << "要素数は " << m_size << "でした。" << endl;
}

int IntArray::Get(int i){
	CheckIndex(i);
	return m_array[i];
}

void IntArray::Set(int i, int value){
	CheckIndex(i);
	m_array[i] = value;
}

int IntArray::Size(){
	return m_size;
}


void IntArray::CheckIndex(int i){
	if(0 <= i && i < m_size){
		//インデックスは正常
	}else{
		cout << "インデックスが不正です！" << endl
			 << "値：" << i << endl;
		exit(EXIT_FAILURE);
	}
}