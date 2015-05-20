#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class IntArray{
public:
	IntArray(int size);
	~IntArray();

public:
	int Get(int i);
	void Set(int i, int value);

private:
	void CheckIndex(int i);

private:
	int* m_array;
	int m_size;
};

IntArray::IntArray(int size){
	m_array = new int[size];
	m_size = size;

	cout << "コンストラクタが呼ばれました。" << "要素数は " << m_size << "です。" << endl;
}

IntArray::~IntArray(){
	delete [] m_array;

	cout << "デストラクタが呼ばれました。" << "要素数は " << m_size << "でした。" << endl;
}