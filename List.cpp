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

    Node<T> tmp;
    size_t  size;

    if (empty())
        return (0);
    tmp = (*head);
    size = 0;

    while (tmp.next != nullptr) {
        tmp = (*tmp.next);
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
        tail = std::make_shared<Node<T>> ();
        head->data = std::make_shared<T> (value);
        head->next = std::make_shared<Node<T>> ();
        head->next = tail;
        tail = head;
    }
    else {
        tail->next = std::make_shared<Node<T>> ();
        tail->next->data = std::make_shared<T> (value);
        tail = tail->next;
        tail->next = nullptr;
    }
   
}

template <class T>
void    List<T>::pop_back(void) {
    
    if (empty())
        return ;
    else if (size() == 1)
        head = nullptr;
    else {
        std::cout << "####" << std::endl;
        std::cout << (*tail->data) << std::endl;
    }
}

template <class T>
void List<T>::push_front( const T& value ) {

    if (head == nullptr) {
        head = std::make_shared<Node<T>> ();
        head->data = std::make_shared<T> (value);
        head->next = std::make_shared<Node<T>> ();
        head->next = nullptr;
        head->next->data = nullptr;
    }
    else {
        std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

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

    Node<T> tmp;

    if (empty())
        return ;
    tmp = (*head);
    std::cout << "------" << std::endl;
    while (tmp.next != nullptr) {
        std::cout << *tmp.data << std::endl;
        tmp = (*tmp.next);
    }
    std::cout << "------" << std::endl;
}

template <class T>
void    List<T>::reverseprint(void) const {

    std::weak_ptr<Node<T>> tmp;

    tmp = tail->prev;
    std::cout << "------" << std::endl;
    while (tmp.lock() != head->prev.lock()) {
        std::cout << (*tmp.lock()->data) << std::endl;
        tmp = tmp.lock()->prev;
    }
    std::cout << "------" << std::endl;
}

int main(void) {

    List<int> lst;

    lst.push_back(1);
    lst.push_back(1);
    lst.push_back(1);
    lst.push_back(1);
    lst.push_back(1);
    //lst.push_back(1);


    //lst.pop_back();

    //std::cout << lst.size() << std::endl;
    
   // lst.reverseprint();
    lst.print();
}