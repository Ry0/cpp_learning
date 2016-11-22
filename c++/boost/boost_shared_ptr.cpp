#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Object {
  string str;

  Object(const string &InitStr) {
    str = InitStr;
    cout << "call " << str << "::Object():" << endl;
  }

  /** デストラクタ
      デストラクタが呼ばれた事を表すメッセージを表示
   */
  ~Object() { cout << "call " << str << "::~Object():" << endl; }
};

int main(int argc, char *argv[]) {
  if (1) { //ブロック1
    boost::shared_ptr<Object> Array[] = {
        boost::shared_ptr<Object>(new Object("Obj0")),
        boost::shared_ptr<Object>(new Object("Obj1")),
        boost::shared_ptr<Object>(new Object("Obj2"))};
    cout << "参照数 = " << Array->use_count() << endl;
    if (1) {
      //ブロック2
      vector< boost::shared_ptr<Object> > v;
      v.insert(v.begin(), Array, Array + 3);
      for (int i = 0; i < v.size(); ++i) {
        cout << "v[" << i << "] = " << v[i]->str << endl;
      }
      cout << "参照数 = " << Array->use_count() << endl;
      //ブロック2から抜ける(vectorが破棄される)
      cout << "break Block2" << endl;
    }
    cout << "参照数 = " << Array->use_count() << endl;
    //ブロック1から抜ける(配列が破棄される)
    cout << "break Block1" << endl;
  }
  cout << "return" << endl;
  return 0;
}
