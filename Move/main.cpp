#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>

class Vector {
    public:
        Vector() { std::cout << "Contructor" << std::endl; }
        Vector(const Vector& v) { std::cout << "Contructor Copy" << std::endl; }
        Vector(const Vector&& v) { std::cout << "Contructor Move" << std::endl; }
};

void test(Vector& t) {
    auto& d = t;
    std::cout << "test: " << std::is_same<decltype(d), decltype(t)>::value << std::endl;
    std::cout << "test: " << std::is_same<decltype(d), Vector>::value << std::endl;
}

int main() {
    std::unique_ptr<int> p1(new int{0});
    std::unique_ptr<int> p2 = std::move(p1);

    Vector t;
    test(t);
    return 0;
}
