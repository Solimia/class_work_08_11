#include "List.h"
#include <string>

template <typename T>
List<T>::Node::Node(const T& data) : data(data), next(nullptr)
{}

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr)
{}

template <typename T>
List<T>::~List() 
{
    clear();
}

template <typename T>
void List<T>::clear()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}

template <typename T>
void List<T>::addTail(const T& data) 
{
    Node* newNode = new Node(data);
    if (tail)
    {
        tail->next = newNode;  
    }
    tail = newNode;
    if (!head) 
    {
        head = newNode;  
    }
}

template <typename T>
void List<T>::removeTail() 
{
    if (!head) return;  

    if (head == tail) 
    {

        delete head;
        head = tail = nullptr;
    }
    else {

        Node* current = head;
        while (current->next != tail) 
        {
            current = current->next;
        }
        delete tail;
        current->next = nullptr;
        tail = current;
    }
}

template <typename T>
void List<T>::print() const 
{
    Node* current = head;
    while (current) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template class List<int>;
template class List<double>;
template class List<string>;