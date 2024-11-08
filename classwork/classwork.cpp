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
List<T>::List(const List<T>& other) : head(nullptr), tail(nullptr)
{
    Node* current = other.head;
    while (current != nullptr) 
    {
        addTail(current->data); 
        current = current->next;
    }
}

template <typename T>
List<T>& List<T>::operator = (const List<T>& other)
{
    if (this == &other) 
    {
        return *this;  
    }

    clear();  

    Node* current = other.head;
    while (current != nullptr) 
    {
        addTail(current->data); 
        current = current->next;
    }

    return *this;
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
    else
    {

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
        cout << current->data << "**";
        current = current->next;
    }
    cout << endl;
}

template class List<int>;
template class List<double>;
template class List<string>;

void testList()
{
    List<int> list1;
    list1.addTail(10);
    list1.addTail(20);
    list1.addTail(30);

    List<int> list2 = list1;
    list2.print();  

    List<int> list3;
    list3.addTail(100);
    list3 = list1;  
    list3.print();  

    list1.addTail(40);
    list1.print();  
    list3.print(); 
}