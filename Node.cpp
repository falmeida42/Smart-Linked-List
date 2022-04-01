#include "List.h"

template <class T>
Node<T>::Node(void) {
    next = nullptr;
}

// int main(void) {

//     Node<int> node;

//     node.data = std::make_shared<int> (1);
//     node.next = std::make_shared<Node<int>> (); 
//     node.next->data = std::make_shared<int>(10);

//     std::cout << (*node.data) << std::endl;
//     std::cout << (*node.next->data) << std::endl;
// }