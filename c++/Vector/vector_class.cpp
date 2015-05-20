#include <iostream>
#include <vector>

class Foo {
public:
    int i;
    Foo() : i(0) {
        std::cout << "default" << std::endl;
    }
    Foo(int num) : i(num) {
        std::cout << "int param" << std::endl;
    }
    Foo(const Foo &rhs) : i(rhs.i) {
        std::cout << "copy const" << std::endl;
    }
    ~Foo() {
        std::cout << "destructer" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    std::vector<Foo> v;
    v.push_back(Foo(1));
    v.resize(2);
    return 0;
}