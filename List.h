#ifndef LIST_H
# define LIST_H

# include <iostream>
# include <memory>

template <class T>
class Node
{
    public:
        T data;
        std::shared_ptr<Node<T>> next;
        Node();
};


template <class T>
class List
{
    private:
        std::shared_ptr<Node<T>> List;
    public:
        List();
        void    insert(T data);
        void    delet(void);
        void    search(T data);
        void    print(void);

};


#endif