#include "Vector.h"

using namespace my;

int main(int argc, char** argv) {
    CVector k = {3,4,5};
    CVector t(4);
    std::cout << k << std::endl;
    CVector d = k;
    std::cout << d << std::endl;

    //for (CVector::Iterator it = k.begin(); it != k.end(); ++it) {
    for (auto it = k.begin(); it != k.end(); ++it) {
        std::cout << *it << std::endl;
    }

    auto time = 1;

    std::cout << accumulate(k.begin(), k.end(), 0, [time](int a, int b){
            return a + b;
    }) << std::endl;

    return 0;
}
