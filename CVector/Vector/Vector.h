#ifndef __CVECTOR__
#define __CVECTOR__

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <sstream>

namespace my {


class CVector {
private:
    size_t               _allocated;
    size_t               _size;
    std::unique_ptr<int[]> _arrPtr;

public:
    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = int*;
    using const_pointer = const int*;
    using size_type = size_t;

    struct Iterator {
        pointer _node;
        Iterator(pointer node) : _node(node) {}

        reference operator*() {
            return *_node;
        }

        const_reference operator*() const {
            return *_node;
        }

        Iterator& operator++() {
            _node = _node + 1;
            return *this;
        }

        bool operator!=(const Iterator& it) {
            return this->_node != it._node;
        }
    };


    /**Because vector{4,5,6} -> vector(with elements), but vector(4) -> vector with size */
    explicit CVector(size_t s = 0) : _allocated(s),
                                     _size(s),
                                     _arrPtr(new int[_allocated]) {
        std::cout << "Contructor with size: " << _size << std::endl;
    }

    /** vector{4,5,6}*/
    CVector(std::initializer_list<int> values) : _allocated(values.size()),
                                                 _size(values.size()),
                                                 _arrPtr(std::move(new int[_allocated])) {
        std::copy(std::begin(values), std::end(values), &_arrPtr[0]);
        std::cout << "Contructor with initializer_list: " << _size << std::endl;
    }

    CVector(const CVector& v) : _allocated(v._allocated),
                                _size(v._size) {
        _arrPtr.reset(new int[_allocated]);
        std::copy(&v._arrPtr[0], &v._arrPtr[v.size()], &_arrPtr[0]);
        std::cout << "Constructor copy: " << _size << std::endl;
    }

    CVector& operator=(const CVector& v) {
        if (_allocated != v._allocated) {
            _arrPtr.reset(new int[v._allocated]);
            _allocated = v._allocated;
        }
        _size = v._size;
        std::copy(&v._arrPtr[0], &v._arrPtr[v.size()], &_arrPtr[0]);
        return *this;
    }

    /** Move constructor, after "v" will be bad object(don't use "v") */
    CVector(CVector&& v) : _allocated(v._allocated),
                           _size(v._size),
                           _arrPtr(std::move(v._arrPtr)) {
        v._size = 0;
        v._allocated = 0;
        std::cout << "Move constructor" << std::endl;
    }

    CVector& operator=(CVector&& v) {
        _allocated = v._allocated;
        _size = v._size;
        _arrPtr = std::move(v._arrPtr);

        v._size = 0;
        v._allocated = 0;
        return *this;
    }

    ~CVector() {
        std::cout << "Destructor\nClear: " << _allocated << std::endl;
    }

    size_type size() const {
        return _size;
    }

    reference operator[](size_type i) noexcept {
        assert(i < _size);
        return _arrPtr[i];
    }

    const_reference operator[](size_type i) const noexcept {
        assert(i < _size);
        return _arrPtr[i];
    }

    reference at(size_type i) {
        if (i >= _size) {
            throw std::out_of_range("Go out of range");
        }
        return _arrPtr[i];
    }

    const_reference at(size_type i) const {
        if (i >= _size) {
            throw std::out_of_range("Go out of range");
        }
        return _arrPtr[i];
    }

    Iterator begin() { return Iterator(&_arrPtr[0]); }
    Iterator end() { return Iterator(&_arrPtr[_size]); }
};

std::ostream& operator<< (std::ostream& os, const CVector& v) {
    std::stringstream ss;

    for (size_t i = 0; i < v.size(); i++) {
        ss << v[i] << " ";
    }

    os << ss.str();

    return os;
}

template <typename Iter, typename Type, typename Functor>
Type accumulate(Iter it1, Iter it2, Type result, Functor functor) {
    for (; it1 != it2; ++it1) {
        result = functor(result, *it1);
    }
    return result;
}

template <typename T>
struct add {
    T operator()(const T& a, const T& b) {
        return a + b;
    }
};

struct mux {
template <typename T>
    T operator()(const T& a, const T& b) {
        return a * b;
    }
};

}
#endif /* __CVECTOR__ */
