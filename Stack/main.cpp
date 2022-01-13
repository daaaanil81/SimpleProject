#include <iostream>

#include "stack.h"

int main() {
    Stack<int> s;
    s.push(5);

    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << std::endl;
    }

    for (auto it : s) {
        std::cout << it << std::endl;
    }
    return 0;
}
