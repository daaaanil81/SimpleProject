#ifndef __CVECTOR__
#define __CVECTOR__

#include <iostream>

namespace my {

template <class Type>
class CVector {
private:
    Type *m_array;
    size_t m_size;
    size_t m_allocated;
public:
    typedef Type value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    CVector(size_t s = 0);
    ~CVector();
    size_t size();
};

template <class Type>
size_t CVector<Type>::size() {
    return m_size;
}

template <class Type>
CVector<Type>::CVector(size_t s) {
    if (m_size == 0) {
        std::cout << "Container is empty." << std::endl;
    } else {
        m_array = new Type[s];
        m_allocated = m_size = s;
    }
    std::cout << "Contructor with size: " << m_size << std::endl;
}

template <class Type>
CVector<Type>::~CVector() {
    std::cout << "Destructor\nClear: " << m_allocated << std::endl;
    delete [] m_array;
}

}
#endif /* __CVECTOR__ */
