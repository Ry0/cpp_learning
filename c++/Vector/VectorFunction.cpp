#include <iostream>
#include <vector>
using namespace std;
int max(std::vector<int> v)
{
    int maxVal = v[0];       // 整数最小値
    for(unsigned int i = 1; i < v.size(); ++i) {
        if( v[i] > maxVal ){
            maxVal = v[i];
        }
    }
    return maxVal;
}

int main(void)
{
    std::vector<int> v ={2,5,6,7};
    //v に要素を追加;
    int mx = max(v);
    cout << mx << endl;

}