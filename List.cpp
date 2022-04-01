#include "List.h"

template <class T>
List<T>::List() {
    _List = nullptr;
}

template <class T>
void    List<T>::pushback(const T &value) {

    if (_List == nullptr)
    {
    _List = std::make_shared<Node<T>> ();
    _List->data = std::make_shared<T> (value);
    _List->next = std::make_shared<Node<T>> ();
    _List->next->next = nullptr;
    _List->next->data = nullptr;
    }
    else {

        std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>> ();

        tmp = _List;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->data = std::make_shared<T> (value);
        tmp->next = std::make_shared<Node<T>> ();
        tmp->next->next = nullptr;
        tmp->next->data = nullptr;
    }
}

template <class T>
void    List<T>::print(void) const {

    Node<T> tmp;

    tmp = (*_List);
    while (tmp.next != nullptr) {
        std::cout << *tmp.data << std::endl;
        tmp = (*tmp.next);
    }
}


int main(void) {

    List<int> lst;

    lst.pushback(10);
    lst.pushback(20);
    lst.pushback(30);
    lst.print();
}