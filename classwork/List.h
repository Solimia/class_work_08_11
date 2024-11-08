#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data);
    };

    Node* head;
    Node* tail;

public:
    List();
    ~List();

    List(const List<T>& other);         
    List<T>& operator = (const List<T>& other); 

    void clear();
    void addTail(const T& data);
    void removeTail();
    void print() const;
};
