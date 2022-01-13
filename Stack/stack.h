#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <typename Type>
class Stack {
private:
    struct Node {
        Node* next;
        Node* prev;
        Type value;
        Node(const Type& t) : next(nullptr), prev(nullptr), value(t) {}
    };

    struct Iterator {
        Stack<Type>::Node* _it;
        Iterator(Node* it) : _it(it) {}

        Iterator operator--() {
            _it = _it->prev;
            return *this;
        }

        Iterator operator++() {
            _it = _it->next;
            return *this;
        }

        bool operator!=(const Iterator& it) {
            return _it != it._it;
        }

        Type& operator*() {
            if (_it == nullptr) {
                throw std::out_of_range("Out of range");
            }
            return _it->value;
        }
    };
private:
    Stack<Type>::Node* _first;
    Stack<Type>::Node* _last;
    size_t _size;
public:
    Stack() : _first(nullptr), _last(nullptr) {}

    Stack(const Stack& s) = delete;
    Stack& operator=(const Stack& s) = delete;

    Stack(Stack&& s) :
        _first(s._first),
        _last(s._last),
        _size(s._size) {
        s._first = nullptr;
        s._last = nullptr;
        s._size = 0;
    }

    void operator =(Stack&& s) {
        clear();
        _first = s._first;
        _last = s._last;
        _size = s._size;
        s._first = nullptr;
        s._last = nullptr;
        s._size = 0;
    }

    ~Stack() {
        while (_first != nullptr) {
            auto tmp = _first;
            _first = _first->next;
            delete tmp;
        }
    }

    Type top() { return _last->value; }

    void pop() {
        if (_first == nullptr) {
            throw std::out_of_range("Out of range");
        }

        Node* tmp = _last;
        _last = _last->prev;
        _last->next = nullptr;
        --_size;
        delete tmp;
    }

    void push(const Type& value) noexcept {
        auto tmp = new Node(value);

        if (_first != nullptr) {
            _first->prev = tmp;
            tmp->next = _first;
        }

        _first = tmp;
        ++_size;
    }

    void clear() {
        while (_first != nullptr) {
            auto tmp = _first;
            _first = _first->next;
            delete tmp;
        }
        _size = 0;
    }

    size_t size() const {
        return _size;
    }

    bool empty() {
        if (_size == 0) {
            return true;
        } else {
            return false;
        }
    }

    Iterator begin() { return Iterator(_first);}
    Iterator end() { return Iterator(nullptr);}
};

#endif /* __STACK_H__ */
