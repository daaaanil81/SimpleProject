#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <typename Type>
class Stack {
private:
    struct Node {
        Stack<Type>::Node* next;
        Stack<Type>::Node* prev;
        Type value;
        Node() : next(nullptr), prev(nullptr) {}
    };
private:
    Stack<Type>::Node* _first;
    Stack<Type>::Node* _last;
    size_t _size;
public:
    Stack() : _first(nullptr), _last(nullptr) {}

    ~Stack() {
        while (_first != nullptr) {
            Node* tmp = _first;
            _first = _first->next;
            delete tmp;
        }
    }

    Type top() { return _last->value; }

    void pop() {
        Stack<Type>::Node* tmp = _last;
        _last = _last->prev;
        _last->next = nullptr;
        delete tmp;
        --_size;
    }

    void push(const Type& value) {
        std::cout << "1" << std::endl;
        Stack<Type>::Node* tmp = new Stack<Type>::Node;
        std::cout << "2" << std::endl;
        _first->prev = tmp;
        std::cout << "3" << std::endl;
        tmp->next = _first;
        std::cout << "4" << std::endl;
        _first = tmp;
        ++_size;
    }

    void clear() {
        while (_first != nullptr) {
            Stack<Type>::Node* tmp = _first;
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
};

#endif /* __STACK_H__ */
