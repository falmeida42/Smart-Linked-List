#include "List.hpp"

template <class T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

//ACESS ELEMENT
template <class T>
T&   List<T>::front(void) {
    return (*head->data);
}

template <class T>
T&   List<T>::back(void) {
    return (*tail->data);
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
    
    lst.push_back(133);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.pop_back();
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(1212121);
    lst.push_front(42);
    lst.print();

    std::cout << "List Front: "<< lst.front() << std::endl;
    std::cout << "List Back: " << lst.back() << std::endl;

}