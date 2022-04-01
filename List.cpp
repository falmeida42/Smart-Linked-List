#include "List.hpp"

template <class T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

//CAPACITY

// template <class T>
// bool    List<T>::empty(void) const {

//     if (_List == nullptr)
//         return (true);
//     return (false);
// }

// template <class T>
// size_t  List<T>::size(void) const {

//     Node<T> tmp;
//     size_t  size;

//     tmp = (*_List);
//     size = 0;
//     while (tmp.next != nullptr) {
//         tmp = (*tmp.next);
//         size++;
//     }

//     return (size);
// }

//CAPACITY


//MODIFIERS
template <class T>
void    List<T>::push_back(const T &value) {

    if (head == nullptr)
    {
    head = std::make_shared<Node<T>> ();
    tail = std::make_shared<Node<T>> ();
    head->data = std::make_shared<T> (value);
    head->next = std::make_shared<Node<T>> ();
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
    }
    else {
        tail->data = std::make_shared<T> (value);
        tail->next = std::make_shared<Node<T>> ();
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = nullptr;
    }
}

// template <class T>
// void    List<T>::pop_back(void) {

//     std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

//     tmp = _List;
//     while (tmp->next->next != nullptr)
//         tmp = tmp->next;
//     tmp->next->data = nullptr;
//     tmp->next = nullptr;
// }

// template <class T>
// void List<T>::push_front( const T& value ) {

//     if (_List == nullptr) {
//         _List = std::make_shared<Node<T>> ();
//         _List->data = std::make_shared<T> (value);
//         _List->next = std::make_shared<Node<T>> ();
//         _List->next->next = nullptr;
//         _List->next->data = nullptr;
//     }
//     else {
//         std::shared_ptr<Node<T>> node = std::make_shared<Node<T>> ();
//         node->data = std::make_shared<T> (value);
//         node->next = std::make_shared<Node<T>> ();
//         node->next = _List;
//         _List = node;
//     }
// }

// template <class T>
// void    List<T>::pop_front(void) {

//     std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

//     tmp = _List;
    
//     _List = _List->next;
//     tmp->data = nullptr;
//     tmp = nullptr;
// }

//MODIFIERS

template <class T>
void    List<T>::print(void) const {

    Node<T> tmp;

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

    lst.push_back(11);
    lst.push_back(12);
    lst.push_back(13);
    lst.push_back(14);
    lst.push_back(15);
    lst.push_back(16);
    lst.push_back(17);
    lst.push_back(18);
  
    lst.print();
    lst.reverseprint();
}