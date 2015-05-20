#include <iostream>
using namespace std;

class Integer{
public:
	int m_value;
	Integer();
	void Show();
};

Integer::Integer(){
	m_value = 0;
}

void Integer::Show(){
	cout << "初期化しました" << endl; // branchのテスト4回
	cout << m_value << endl;
}

int main(){
	Integer a,b,c;
	// Show()のテスト
	a.Show();
	b.Show();
	c.Show();
}