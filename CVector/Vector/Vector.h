#ifndef __CVECTOR__
#define __CVECTOR__

#include <iostream>

namespace dstd {

template <class Type>
class CVector {
private:
    Type *arr;
    size_t size;
public:
    CVector();
    ~CVector();
};

template <class Type>
CVector<Type>::CVector() {
    std::cout << "Contructor without arguments" << std::endl;
}

template <class Type>
CVector<Type>::~CVector() {
    std::cout << "Destructor" << std::endl;
}

}
#endif /* __CVECTOR__ */
