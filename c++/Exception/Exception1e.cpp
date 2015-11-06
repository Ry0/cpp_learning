#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
  try {
    ifstream file;
    int a;

    file.open("./tmp/testa.txt");
    if (!file.is_open()) {
      a = 1;
      // throw "ファイルを開けませんでした！";
      throw a;
    }

    string line;
    getline(file, line);
    if (file.fail()) {
      // throw "ファイルから読み込めませんでした！";
      a = 2;
      throw a;
    }

    cout << line << endl;
  // } catch (const char* error) {
  } catch (int error) {
    cerr << error << endl;
    return EXIT_FAILURE;
  }

  return 0;
}