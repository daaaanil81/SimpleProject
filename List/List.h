#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <initializer_list>

template <typename Type>
struct Node {
    Node(const Type& v) : value(v), next(nullptr) {}
    Type value;
    Node* next;
};

template <typename Type>
struct Iterator {
    Node<Type>* _n;

    Iterator(Node<Type>* n) : _n(n) {}

    Type& operator*() { return _n->value; }
    const Type& operator*() const { return _n->value; }

    Iterator& operator++() {
        _n = _n->next;
        return *this;
    }

    bool operator!=(const Iterator& it) {
        return this->_n != it._n;
    }
};

template <typename Type>
struct List {
    Node<Type> *first, *last;
    List() : first(nullptr), last(nullptr) {
        std::cout << "Construct" << std::endl;
    }
    ~List() {
        while (first != nullptr) {
            auto time = first->next;
            delete first;
            first = time;
            std::cout << "Destruct" << std::endl;
        }
    }

    List(std::initializer_list<Type> values) {
        for (auto v : values) {
            append(v);
        }
    }

    void append(const Type& v) {
        if (first != nullptr) {
            last = last->next = new Node<Type>(v);
        } else {
            last = first = new Node<Type>(v);
        }
    }

    Iterator<Type> begin() { return Iterator<Type>(first); }
    Iterator<Type> end() { return Iterator<Type>(nullptr); }

};

#endif
