#include "List.hpp"

template <class T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

//CAPACITY

template <class T>
bool    List<T>::empty(void) const {

    if (this->head == nullptr)
        return (true);
    return (false);
}

template <class T>
size_t  List<T>::size(void) const {

    std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();
    size_t  size;

    if (empty())
        return (0);
    tmp = head;
    size = 0;

    while (tmp) {
        tmp = tmp->next;
        size++;
    }

    return (size);
}

template <class T>
void List<T>::clear()
{
    std::shared_ptr<Node<T>> current = std::make_shared<Node<T>> ();
    current = head;
    std::shared_ptr<Node<T>> next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        pop_back();
        current = next;
    }
    head = NULL;
}


//CAPACITY


//MODIFIERS
template <class T>
void    List<T>::push_back(const T &value) {

    if (size() == 0) {
        head = std::make_shared<Node<T>> ();
        tail = head;
        head->data = std::make_shared<T> (value);
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    else {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>> ();
        node->data = std::make_shared<T>(value);
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

template <class T>
void    List<T>::pop_back(void) {
    
    if (empty())
        return ;
    else if (size() == 1)
        head = nullptr;
    else {
        tail = tail->prev.lock();
        tail->next = nullptr;
    }
}

template <class T>
void List<T>::push_front( const T& value ) {

    if (size() == 0) {
        head = std::make_shared<Node<T>> ();
        tail = head;
        head->data = std::make_shared<T> (value);
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    else {
        std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

        head->prev = tmp;
        tmp->data = std::make_shared<T> (value);
        tmp->next = std::make_shared<Node<T>> ();
        tmp->next = head;
        head = tmp;
    }
}

template <class T>
void    List<T>::pop_front(void) {

    if (head->next == nullptr)
        head = nullptr;
    else
        head = head->next;
}

//MODIFIERS

template <class T>
void    List<T>::print(void) const {

    std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

    if (empty())
        return ;
    tmp = head;
    std::cout << "------" << std::endl;
    while (tmp) {
        std::cout << *tmp->data << std::endl;
        tmp = tmp->next;
    }
    std::cout << "------" << std::endl;
   
}

int main(void) {

    List<int> lst;

    
    lst.push_back(1);
    lst.push_back(1);
    lst.clear();
    
    //lst.pop_back();
    lst.print();
}