#include "List.h"

int main() {
    List<int> l = {2, 3, 4};

    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
