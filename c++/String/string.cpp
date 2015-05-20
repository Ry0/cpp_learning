#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::string b;

    std::cin >> a;
    b = "テスト";

    if( a == b ) std::cout << "等しい\n";
    else std::cout << "等しくない\n";

    return 0;
}